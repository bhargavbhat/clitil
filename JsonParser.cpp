#include "JsonParser.h"
#include "Config.h"
#include "json11/json11.hpp"

using namespace json11;

// driver method
std::string JsonParser::parseJSON(const FeedType type, const std::string& raw_json)
{
    std::string retVal;
    std::string err;
    auto resp = Json::parse(raw_json, err);

    // process further only if there were no
    // errors during parsing of raw JSON data
    if(err.empty())
    {
        switch(type)
        {
            case FeedType::REDDIT_TIL:
                retVal = parseRedditTIL(resp);
                break;
            case FeedType::NUMBERS_API:
                retVal = parseNumbersAPI(resp);
                break;
            case FeedType::ICNDB_API:
                retVal = parseICNDBAPI(resp);
                break;
             default:
                // nothing to do
                break;
        }
    }
    return retVal;
}

// parser for r/TodayILearned JSON
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

// parse for numbersapi.com JSON
std::string JsonParser::parseNumbersAPI(const json11::Json& json)
{
    std::string retVal;
    auto msg = json["text"];
    if(!msg.is_null())
        retVal = "TIL " + msg.string_value();
    return retVal;
}

std::string JsonParser::parseICNDBAPI(const json11::Json& json)
{
    std::string retVal;
    auto msg = json["type"];
    if(!msg.is_null())
    {
        auto val = msg.string_value();
        if(val.compare("success") == 0)
        {
            auto joke = json["value"]["joke"];
            if(!joke.is_null())
            {
                retVal = "TIL that, " + joke.string_value();
            }
        }
    }
    return retVal;
}
