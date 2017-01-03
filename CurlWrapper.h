#pragma once

#include <string>
#include <curl/curl.h>

enum class FeedType : int8_t;

class CurlResponse
{
    public:
        CurlResponse() {}
        CurlResponse(const std::string& resp)
            :_response(resp){}
        void setResponse(const std::string& resp) { _response = resp; }
        std::string getResponse() const { return _response; }
        bool valid() const { return !_response.empty(); }
    private:
        std::string _response;
};

class CurlWrapper
{
    public:
        static CurlResponse getResponse(const FeedType type);
};
