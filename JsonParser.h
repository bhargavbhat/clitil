#pragma once
#include <string>
#include <cstdint>
#include "CurlWrapper.h"

enum class FeedType : int8_t;

namespace json11
{
    class Json;
}

class JsonParser
{
    public:
        static std::string parseJSON(const FeedType type, const CurlResponse& resp);
};

class ResponseParser
{
    public:
        virtual std::string parse(const CurlResponse& resp) = 0;
};

class RedditTILResponseParser final : public ResponseParser
{
    public:
        std::string parse(const CurlResponse& resp) override;
};

class NumbersAPIResponseParser final : public ResponseParser
{
    public:
        std::string parse(const CurlResponse& resp) override;
};

class ICNDBAPIResponseParser final : public ResponseParser
{
    public:
        std::string parse(const CurlResponse& resp) override;
};


