#pragma once
#include "../common/SocketHandler.hpp"
namespace server{
class Server{
public:
    Server();
    ~Server();
    void acceptIncommingConnections();
protected:
private:
    chat::SocketHandler skt;

};



}
