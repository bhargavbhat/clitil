#include <iostream>
#include <string>
#include "CurlWrapper.h"
#include "JsonParser.h"
#include "Config.h"

int main(int argc, char** argv)
{
    // source tells you what to fetch
    auto source = FeedType::REDDIT_TIL;

    if(argc > 1)
    {
        std::string src(argv[1]);
        source = getSource(src);
    }

    // server_data is the raw response from the server
    auto server_data = CurlWrapper::getResponse(source);

    if(server_data.valid())
    {
        // message is the final message to be shown to user
        auto message = JsonParser::parseJSON(source, server_data.getResponse());

        if(!message.empty())
            std::cout<<message<<std::endl;
    }
    else
    {
        // handler for network/connectivity issues
        std::cout<<ERR_MSG_NETWORK<<std::endl;
    }
}
