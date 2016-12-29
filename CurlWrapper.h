#pragma once

#include <string>
#include <curl/curl.h>

enum class FeedType : int8_t;

class CurlWrapper
{
    public:
        static std::string getJSON(const FeedType type);
};
