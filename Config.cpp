#include "Config.h"

// Helper Methods
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
            retVal = "https://www.reddit.com/r/todayilearned/top/.json?count=1";
            break;
        default:
            // nothing to do
            break;
    }
    return retVal;
}
