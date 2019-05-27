#include <iostream>
#include <server.hpp>

const std::string kServerIp = "127.0.0.1";
const uint kPort = 8001;


int main() {
    Server server(kServerIp, kPort);
    server.RunServer();
    return 0;
}