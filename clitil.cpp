#include <iostream>
#include <string>
#include "CurlWrapper.h"
#include "JsonParser.h"
#include "Config.h"

int main()
{
    // source tells you what to fetch
    auto source = FeedType::REDDIT_TIL;

    // server_data is the raw response from the server
    auto server_data = CurlWrapper::getJSON(source);

    if(!server_data.empty())
    {
        // message is the final message to be shown to user
        auto message = JsonParser::parseJSON(source, server_data);

        if(!message.empty())
            std::cout<<message<<std::endl;
    }
    else
    {
        // handler for network/connectivity issues
        std::cout<<ERR_MSG_NETWORK<<std::endl;
    }
}
