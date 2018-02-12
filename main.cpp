#include <iostream>
#include <string.h>
#include "server/Server.hpp"
#include "client/Client.hpp"
using std::cout;
using std::endl;
int main(int argc, char* argv[])
{
    if(!strcmp(argv[1], "server")){
        server::Server srv(atoi(argv[2]));
        srv.dealWithIncommingConnections();
    }
    else{
        std::string str(argv[2]);
        client::Client client(str, atoi(argv[3]));
        client.connectToServer();
        client.sendMessage("Hello World");
    }

    return 0;
}
