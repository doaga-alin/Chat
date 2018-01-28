#pragma once
#include <iostream>
using std::string;
namespace chat{


class SocketHandler
{
    public:
        SocketHandler();
        SocketHandler(int sfd);
        ~SocketHandler();
        SocketHandler& operator=(const SocketHandler& rhs) = delete;
        SocketHandler(SocketHandler& rhs) = delete;
        int bind(int port);
        int listen();
        SocketHandler accept();
        int connect(string ip, int port);
        void write(const char* buff);
        int read(char* recvBuff);
    protected:

    private:
        static const int ERROR_SFD = -1;
        int sfd;
        static const int backlog = 50;
};
} //namespace chat
