#pragma once
#include "../common/SocketHandler.hpp"
namespace server{
class Server{
public:
    Server(int port);
    ~Server();
    void acceptIncommingConnections();
protected:
private:
    int portNumber;
    chat::SocketHandler skt;
    chat::SocketHandler* sktAccept;

};



}
