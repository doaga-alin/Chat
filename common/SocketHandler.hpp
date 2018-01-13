#pragma once
namespace chat{
class SocketHandler
{
    public:
        SocketHandler();
        SocketHandler(const SocketHandler& rhs);
        ~SocketHandler();
        int getSfdNumber();
        SocketHandler& operator=(const SocketHandler& rhs);

    protected:

    private:
        //checked with deleted methods
        //SocketHandler& operator=(const SocketHandler& rhs) = delete;
        //SocketHandler(SocketHandler& rhs) = delete;
        static const int ERROR_SFD = -1;
        int sfd;
};
} //namespace chat
