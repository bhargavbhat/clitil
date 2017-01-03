#include "JsonParser.h"
#include "Config.h"
#include "json11/json11.hpp"
#include <memory>

using namespace json11;

// driver method
std::string JsonParser::parseJSON(const FeedType type, const CurlResponse& resp)
{
    std::unique_ptr<ResponseParser> parser;
    
    switch(type)
    {
        case FeedType::REDDIT_TIL:
            parser.reset(new RedditTILResponseParser);
            break;
        case FeedType::NUMBERS_API:
            parser.reset(new NumbersAPIResponseParser);
            break;
        case FeedType::ICNDB_API:
            parser.reset(new ICNDBAPIResponseParser);
            break;
        default:
            // nothing to do
            break;
    }
    
    if(parser)
        return parser->parse(resp);
    else
        return std::string("");
}

// parser for r/TodayILearned JSON
std::string RedditTILResponseParser::parse(const CurlResponse& resp)
{
    std::string retVal;
    std::string err;
    auto json = Json::parse(resp.getResponse(), err);

    // process further only if there were no
    // errors during parsing of raw JSON data
    if(err.empty())
    {
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
    }
    return retVal;
}

// parse for numbersapi.com JSON
std::string NumbersAPIResponseParser::parse(const CurlResponse& resp)
{
    std::string retVal;
    std::string err;
    auto json = Json::parse(resp.getResponse(), err);

    // process further only if there were no
    // errors during parsing of raw json data
    if(err.empty())
    {
        auto msg = json["text"];
        if(!msg.is_null())
            retVal = "TIL " + msg.string_value();
    }
    return retVal;
}

std::string ICNDBAPIResponseParser::parse(const CurlResponse& resp)
{
    std::string retVal;
    std::string err;
    auto json = Json::parse(resp.getResponse(), err);

    // process further only if there were no
    // errors during parsing of raw json data
    if(err.empty())
    {
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
    }
    return retVal;
}
