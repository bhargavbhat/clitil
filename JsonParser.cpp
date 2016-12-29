#include "JsonParser.h"
#include "Config.h"
#include "json11/json11.hpp"

using namespace json11;

std::string JsonParser::parseJSON(const FeedType type, const std::string& raw_json)
{
    std::string retVal;
    std::string err;
    auto resp = Json::parse(raw_json, err);

    if(err.empty())
    {
        switch(type)
        {
            case FeedType::REDDIT_TIL:
                retVal = parseRedditTIL(resp);
                break;

            default:
                // nothing to be done
                break;
        }
    }
    return retVal;
}

std::string JsonParser::parseRedditTIL(const json11::Json& json)
{
    std::string retVal;
    auto err_root = json["message"];
    auto root = json["data"];

    if(!err_root.is_null())
    {
        retVal = ERR_MSG_RATE_LIM;
    }
    else if(!root.is_null())
    {
        auto list_root = root["children"];
        auto it = list_root.array_items().begin();

        // skip over the first entry
        ++it;

        if(it != list_root.array_items().end())
        {
            auto dat = it->object_items();
            if(!dat.empty())
                retVal = dat["data"]["title"].string_value();
        }
    }    
    else
    {
        // should never happen, but let's face it, it is going to some day
        // and when it does, the least I can do make an attempt at being witty
        retVal = ERR_MSG_IMPOSSIBLE; 
    }

    return retVal;
}
