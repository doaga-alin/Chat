#pragma once
namespace chat{
using namespace socketLibrary;
class SocketHandler
{
    public:
        SocketHandler();
        ~SocketHandler();
        int getSfdNumber();
        SocketHandler& operator=(const SocketHandler& rhs) = delete;
        SocketHandler(SocketHandler& rhs) = delete;
        int bind(int);
        int listen(int,int);
        int accept(int sfd,struct sockaddr *addr, socklen_t *addrlen);
    protected:

    private:
        static const int ERROR_SFD = -1;
        int sfd;
};
} //namespace chat
