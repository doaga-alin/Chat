#include <iostream>
#include "server/Server.hpp"
using namespace std;
int main(int argc, char* argv[])
{
    server::Server srv;
    srv.acceptIncommingConnections();


    return 0;
}


