#include "SocketHandler.hpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using std::cout;
using std::endl;

namespace socketLibrary{
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
}
namespace chat{

SocketHandler::SocketHandler(){
    cout << "SocketHandler constructor" << endl;
    sfd = socketLibrary::socket(AF_INET, socketLibrary::SOCK_STREAM, 0);

    if(sfd == ERROR_SFD){
        //show a message with error looging
    }
}

SocketHandler::SocketHandler(int sfd){
    cout << "SocketHandler constructor -> sfd" << endl;

    this->sfd = sfd;

    if(this->sfd == ERROR_SFD){
        cout << "No file descriptor here+ here" << endl;
    }
}



SocketHandler::~SocketHandler(){
    cout << "SocketHandler destructor" << endl;
    if(sfd != ERROR_SFD){
        if(socketLibrary::close(this->sfd)){
            //logger sfd err closed
        }
        sfd = ERROR_SFD;
    }
}

int SocketHandler::bind(int port){
    cout << "bind" << endl;
    struct socketLibrary::sockaddr_in serv_addr;

    memset(&serv_addr, 0, sizeof(struct socketLibrary::sockaddr_in));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = port;

    return socketLibrary::bind(this->sfd, (struct socketLibrary::sockaddr *) &serv_addr,
     sizeof(serv_addr));
}

int SocketHandler::listen(){
    cout << "listen" << endl;
    return socketLibrary::listen(this->sfd,this->backlog);
}

SocketHandler SocketHandler::accept(){
    cout << "accept" << endl;

    SocketHandler::SocketHandler() skt(socketLibrary::accept(this->sfd,(struct socketLibrary::sockaddr*)NULL, NULL));
    return skt;
}

int SocketHandler::connect(string ip,int port){
    struct socketLibrary::sockaddr_in serv_addr;

    memset(&serv_addr, 0, sizeof(struct socketLibrary::sockaddr_in));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = port;

    return socketLibrary::connect(this->sfd, (struct socketLibrary::sockaddr*)&serv_addr,sizeof(serv_addr));

}

void SocketHandler::write(const char* buff){
    socketLibrary::write(this->sfd, buff, strlen(buff));
}
//check it again
int SocketHandler::read(char* recvBuff){
    return socketLibrary::read(this->sfd, recvBuff, strlen(recvBuff));
}
} // namespace chat
