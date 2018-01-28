#pragma once
#include "../common/SocketHandler.hpp"
namespace client{
class Client{
public:
    Client();
    ~Client();
    void sendmmsg(char*);
protected:

private:
    int ERROR_SFD = -1;
    int clientSfd;
    chat::SocketHandler skt;

};


}
