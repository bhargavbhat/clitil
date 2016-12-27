#pragma once

#include <string>
#include <curl/curl.h>

const std::string uri = "https://www.reddit.com/r/todayilearned/top/.json";
const std::string ua = "clitil/1.0";

class CurlWrapper
{
    public:
        static std::string getJSON();
};
