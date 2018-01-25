#include "SocketHandler.hpp"
#include <iostream>
#include<unistd.h>
//
#include<stdlib.h>
#include<string.h>

namespace socketLibrary{
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
}
namespace chat{

SocketHandler::SocketHandler(){
    sfd = socketLibrary::socket(AF_INET, socketLibrary::SOCK_STREAM, 0);

    if(sfd == ERROR_SFD){
        //show a message with error looging
    }
}

SocketHandler::~SocketHandler(){
    if(sfd != ERROR_SFD){
        if(close(sfd)){
            //logger sfd err closed
        }
        sfd = ERROR_SFD;
    }
}

int SocketHandler::getSfdNumber(){
    return sfd;
}

int SocketHandler::bind(int sfd){

    struct socketLibrary::sockaddr_un my_addr;


    memset(&my_addr, 0, sizeof(struct socketLibrary::sockaddr_un));
    my_addr.sun_family = AF_INET;

    if (!(socketLibrary::bind(sfd, (struct socketLibrary::sockaddr *) &my_addr, sizeof(struct socketLibrary::sockaddr_un)))){
        return 0;
    }
    return -1;
}

int SocketHandler::listen(int sfd,int backlog){
    if(!socketLibrary::listen(sfd,backlog)){
        return 0;
    }

    //Log something
    return -1;
}

int SocketHandler::accept(int sfd,struct socketLibrary::sockaddr *addr, socketLibrary::socklen_t *addrlen){

}
} // namespace chat
