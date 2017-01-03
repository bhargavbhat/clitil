#include <algorithm>
#include <iostream>
#include "Config.h"

const FeedType getSource(const std::string& src)
{
    std::string str;
    str.resize(src.length());
    std::transform(src.begin(), src.end(), str.begin(), ::tolower);
    FeedType retVal;

    if(str.compare("reddit") == 0)
    {
        retVal = FeedType::REDDIT_TIL;
    }
    else if(str.compare("numbers") == 0)
    {
        retVal = FeedType::NUMBERS_API; 
    }
    else if(str.compare("icndb") == 0)
    {
        retVal = FeedType::ICNDB_API; 
    }
    else
    {
        retVal = FeedType::REDDIT_TIL;
    }

    return retVal;
}
const std::string getUserAgent()
{
    return CONF_BOT_USER_AGENT;
}

const std::string getServerURI(FeedType type)
{
    std::string retVal;
    switch(type)
    {
        case FeedType::REDDIT_TIL:
            retVal = "https://www.reddit.com/r/todayilearned/top/.json?limit=1";
            break;
        case FeedType::NUMBERS_API:
            retVal = "http://numbersapi.com/random/year?json";
            break;
        case FeedType::ICNDB_API:
            retVal = "http://api.icndb.com/jokes/random?limitTo=%5Bnerdy%5D";
            break;
        default:
            // nothing to do
            break;
    }
    return retVal;
}
