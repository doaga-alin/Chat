#pragma once
#include <iostream>
using std::string;
namespace client{
    class Client;
}
namespace chat{

class SocketHandler
{
    public:
        SocketHandler();
        SocketHandler(int sfd);
        SocketHandler(const SocketHandler& rhs);
        ~SocketHandler();
        SocketHandler& operator=(const SocketHandler& rhs) = delete;
        //SocketHandler(SocketHandler& rhs) = delete;
        void bind(int port);
        void listen();
        client::Client accept();
        int connect(const string ip, int port);
        void write(const char* buff);
        void printSfd();
        void error(const char* msg);
        void send(const char* str);
        void read(char* str, int* buffSize);
        int getSfd();
    protected:

    private:
        static const int ERROR_SFD = -1;
        int sfd;
        static const int backlog = 50;
};
} //namespace chat
