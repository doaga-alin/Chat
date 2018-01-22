#pragma once
namespace chat{
class SocketHandler
{
    public:
        SocketHandler();
        ~SocketHandler();
        int getSfdNumber();
        SocketHandler& operator=(const SocketHandler& rhs) = delete;
        SocketHandler(SocketHandler& rhs) = delete;
        int bind(int sfd);
    protected:

    private:
        static const int ERROR_SFD = -1;
        int sfd;
};
} //namespace chat
