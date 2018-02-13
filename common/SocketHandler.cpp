#include "SocketHandler.hpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "../client/Client.hpp"

using std::cout;
using std::endl;

namespace socketLibrary{
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
}
namespace chat{

SocketHandler::SocketHandler(){
    sfd = socketLibrary::socket(AF_INET, socketLibrary::SOCK_STREAM, 0);
    if(sfd == ERROR_SFD){
        error("Error when creating socket");
    }
}

SocketHandler::SocketHandler(int sfd){
    this->sfd = sfd;
    if(this->sfd == ERROR_SFD){
        error("Error when creating socket");
    }
}

SocketHandler::~SocketHandler(){
    if(sfd != ERROR_SFD){
        if(socketLibrary::close(this->sfd)){
            //logger sfd err closed
        }
        sfd = ERROR_SFD;
    }
}

void SocketHandler::error(const char* msg){
    perror(msg);
    exit(1);
}

void SocketHandler::bind(int port){
    using namespace socketLibrary;

    struct sockaddr_in serv_addr;

    memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr("10.0.2.15");
    if(socketLibrary::bind(this->sfd, (struct sockaddr *) &serv_addr,
        sizeof(serv_addr)) < 0){
        error("Error to bind socket");
     }
}

void SocketHandler::listen(){
    if(socketLibrary::listen(this->sfd,this->backlog) < 0){
        error("Error in listen method");
    }
}

client::Client* SocketHandler::accept(){
    using namespace socketLibrary;

    char ipAddress[INET_ADDRSTRLEN];
    struct sockaddr_in addr;

    socklen_t addrlen = sizeof(addr);
    int clientSfd = socketLibrary::accept(this->sfd,(struct socketLibrary::sockaddr*) &addr, &addrlen);
    if(clientSfd == ERROR_SFD){
        error("Accept method return -1");
    }

    inet_ntop(AF_INET, &(addr.sin_addr), ipAddress, INET_ADDRSTRLEN);
    client::Client* client = new client::Client(clientSfd,ipAddress);
    return client;
}

int SocketHandler::connect(const string ip,int port){
    using namespace socketLibrary;

    struct socketLibrary::sockaddr_in serv_addr;
    struct hostent *host_entry;

    host_entry = gethostbyname(ip.c_str());
    if(host_entry == NULL){
        error("Error: host_entry is null");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr);
    serv_addr.sin_port = htons(port);
    return socketLibrary::connect(this->sfd, (struct socketLibrary::sockaddr*)&serv_addr,sizeof(serv_addr));
}

void SocketHandler::send(const char *str){
    if(socketLibrary::send(this->sfd, str, strlen(str), 0) < 0){
        error("Cannot send data");
    }
}

void SocketHandler::read(char *buff, int* buffSize){
    if( socketLibrary::read(this->sfd, buff, 255) < 0){
        error("Cannot read");
    }
}
}
