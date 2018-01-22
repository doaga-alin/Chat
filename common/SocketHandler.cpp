#include "SocketHandler.hpp"
#include <iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/un.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
namespace chat{

SocketHandler::SocketHandler(){
    sfd = socket(AF_INET, SOCK_STREAM, 0);

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

    struct sockaddr_un my_addr;


    memset(&my_addr, 0, sizeof(struct sockaddr_un));
    my_addr.sun_family = AF_INET;

    if (!(bind(sfd, (struct sockaddr *) &my_addr,
        sizeof(struct sockaddr_un))){

        return 0;
    }

    return -1;
}
} // namespace chat
