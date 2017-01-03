#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CurlWrapper.h"
#include "JsonParser.h"
#include "Config.h"

#include <string>

// Test stuff
const std::string TEST_REDDIT_RATE_LIMIT = R"err({"message": "Too Many Requests", "error": 429})err";
const std::string TEST_REDDIT_NORMAL_RESP = R"normal({"kind": "Listing", "data": {"children": [{"data": {"permalink": "/r/todayilearned/comments/5llao6/til_blah/", "title": "TIL BLAH BLAH"}}]}})normal";
const std::string TEST_REDDIT_NORMAL_OUTPUT = "TIL BLAH BLAH";

TEST_CASE("JSON parsing of Reddit rate limit message", "[json_parse]")
{
    CurlResponse test_resp;
    test_resp.setResponse(TEST_REDDIT_RATE_LIMIT);
    auto output = JsonParser::parseJSON(FeedType::REDDIT_TIL, test_resp);
    REQUIRE( output.compare(ERR_MSG_RATE_LIM) == 0 );
}

TEST_CASE("JSON parsing of Reddit sample response","[json_parse]")
{
    CurlResponse test_resp;
    test_resp.setResponse(TEST_REDDIT_NORMAL_RESP);
    auto output = JsonParser::parseJSON(FeedType::REDDIT_TIL, test_resp);
    REQUIRE( output.compare(TEST_REDDIT_NORMAL_OUTPUT) == 0 );
}

