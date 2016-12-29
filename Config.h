#pragma once
#include <string>

enum class FeedType : int8_t
{
    FEED_INVALID = -1,
    REDDIT_TIL,

    FEED_MAX_COUNT = 127
};

// Configuration
const std::string CONF_BOT_USER_AGENT = "clitil/1.0";

// Error messages
const std::string ERR_MSG_RATE_LIM = "TIL the server is Rate Limiting this bot";
const std::string ERR_MSG_IMPOSSIBLE = "TIL that in software, the impossible is possible and things that should never happen, happen sometimes.";
const std::string ERR_MSG_NETWORK = "TIL that this computer(or the remote end) has connectivity issues";

// Test stuff
const std::string TEST_REDDIT_RATE_LIMIT = R"err({"message": "Too Many Requests", "error": 429})err";

// Helper Methods    
const std::string getUserAgent();
const std::string getServerURI(FeedType type);

