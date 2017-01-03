#pragma once
#include <string>

// Identify the source of the feed
enum class FeedType : int8_t
{
    FEED_INVALID = -1,
    REDDIT_TIL,
    NUMBERS_API,
    ICNDB_API,
    FEED_MAX_COUNT = 127
};

// Configuration
const std::string CONF_BOT_USER_AGENT = "clitil/1.0";

// Error messages
const std::string ERR_MSG_RATE_LIM = "TIL the server is Rate Limiting this bot";
const std::string ERR_MSG_IMPOSSIBLE = "TIL that in software, the impossible is possible and things that should never happen, happen sometimes.";
const std::string ERR_MSG_NETWORK = "TIL that this computer(or the remote end) has connectivity issues";

// Helper Methods
const FeedType getSource(const std::string& src);
const std::string getUserAgent();
const std::string getServerURI(FeedType type);
