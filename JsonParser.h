#pragma once
#include <string>
#include <cstdint>

enum class FeedType : int8_t;

namespace json11
{
    class Json;
}

class JsonParser
{
        static std::string parseRedditTIL(const json11::Json& json);
        static std::string parseNumbersAPI(const json11::Json& json);
    public:
        static std::string parseJSON(const FeedType type, const std::string& raw_json);
};
