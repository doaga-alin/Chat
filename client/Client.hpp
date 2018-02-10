#pragma once
#include "../common/SocketHandler.hpp"
namespace client{
class Client{
public:
    Client();
    Client(int, char*);
    ~Client();
    void sendmmsg(char*);
    void error(const char*);
    void setBuffer(string);
    void readMessage(char*, int*);
protected:

private:
    chat::SocketHandler* skt;
    int ERROR_SFD = -1;
    char buffer[256];
    int buffSize;
    string ipAddress;
    //chat::SocketHandler skt;
};
}
