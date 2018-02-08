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
    int getSfd();
    string getIpAddress();
    void setBuffer(string);
    string getBuffer();
protected:

private:
    chat::SocketHandler* skt;
    int ERROR_SFD = -1;
    string ipAddress;
    string buffer;
    //chat::SocketHandler skt;
};
}
