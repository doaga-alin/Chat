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
        SocketHandler(int);
        ~SocketHandler();
        SocketHandler& operator=(const SocketHandler& rhs) = delete;
        SocketHandler(const SocketHandler& rhs) = delete;
        void bind(const int);
        void listen();
        client::Client* accept();
        int connect(const string, const int);
        void error(const char*);
        void send(const char*);
        void read(char*, int*);
    protected:

    private:
        static const int ERROR_SFD = -1;
        int sfd;
        static const int backlog = 50;
};
} //namespace chat
