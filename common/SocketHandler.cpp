#include "SocketHandler.hpp"
#include <iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
using namespace std;
namespace chat{
SocketHandler::SocketHandler(){
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd == ERROR_SFD){
        //show a message with error looging
    }
}
SocketHandler::SocketHandler(const SocketHandler &rhs) : SocketHandler(){
    cout << "I'm in copy constructor" << endl;
}
SocketHandler::~SocketHandler(){
    if(sfd != ERROR_SFD){
        if(close(sfd)){
            //logger sfd err closed
        }
        sfd = ERROR_SFD;
    }
}

SocketHandler& SocketHandler::operator=(const SocketHandler& rhs){
    cout << "I'm in operator=" << endl;
    //call def constructor
    //Since in C++ an object is initialized when it is defined we just return object itself
    return *this;
}
int SocketHandler::getSfdNumber(){
    return sfd;
}
} // namespace chat
