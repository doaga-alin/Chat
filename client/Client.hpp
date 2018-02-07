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
    int ERROR_SFD = -1;
    int sfd;
    string ipAddress;
    string buffer;
    //hat::SocketHandler skt;

};


}
