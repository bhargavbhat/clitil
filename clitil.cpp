#include <iostream>
#include <string>
#include <cstring>
#include "curl_wrapper.h"
#include "json11/json11.hpp"

using namespace json11;


int main()
{
    //fetch JSON from server
    std::string err;
    std::string server_data = CurlWrapper::getJSON();
    auto d = Json::parse(server_data, err);
    auto root = d["data"];
    auto list_root = root["children"];
    auto it = list_root.array_items().begin();

    // skip over the first entry
    ++it;

    //for(; it != list_root.array_items().end(); ++it)
    {
        auto dat = it->object_items();
        std::cout<<dat["data"]["title"].string_value()<<std::endl;
        std::cout<<"https://www.reddit.com/"<<dat["data"]["permalink"].string_value()<<std::endl;
    }
}
