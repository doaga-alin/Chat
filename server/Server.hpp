#pragma once
#include "../common/SocketHandler.hpp"
#include "../client/Client.hpp"
namespace server{
class Server{
public:
    Server(int port);
    ~Server();
    void dealWithIncommingConnections();
protected:
private:
    int portNumber;
    chat::SocketHandler* skt;
    client::Client* client;

};
}
