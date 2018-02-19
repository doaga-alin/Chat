#pragma once
#include "../common/SocketHandler.hpp"
namespace client{
class Client{
public:
    Client();
    Client(int, char*);
    Client(string, int);
    ~Client();
    void sendmmsg(char*);
    void error(const char*);
    void setBuffer(string);
    void readMessage();
    void connectToServer();
    void sendMessage(const char* str);
    void printMessage();
    int getSktSfd();
protected:

private:
    chat::SocketHandler* skt;
    static const int ERROR_SFD = -1;
    char buffer[256];
    int buffSize;
    string ipAddress;
    string serverIp;
    int portNo;
    //chat::SocketHandler skt;
};
}
