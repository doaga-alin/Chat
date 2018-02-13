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
    cout << "SocketHandler constructor without params" << endl;
    sfd = socketLibrary::socket(AF_INET, socketLibrary::SOCK_STREAM, 0);

    if(sfd == ERROR_SFD){
        error("Error when creating socket");
    }
}

SocketHandler::SocketHandler(int sfd){
    cout << "SocketHandler constructor -> sfd" << endl;

    this->sfd = sfd;
    cout << this->sfd << endl;
    if(this->sfd == ERROR_SFD){
        error("Error when creating socket");
    }
}

SocketHandler::SocketHandler(const SocketHandler& rhs){
    sfd = rhs.sfd;
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

void SocketHandler::error(const char* msg){
    perror(msg);
    exit(1);
}

void SocketHandler::bind(int port){
    using namespace socketLibrary;
    cout << "bind" << endl;
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    //serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_addr.s_addr = inet_addr("10.0.2.15");
    if(socketLibrary::bind(this->sfd, (struct sockaddr *) &serv_addr,
        sizeof(serv_addr)) < 0){
        error("Error to bind socket");
     }
}

void SocketHandler::printSfd(){
    cout << this->sfd << endl;
}

void SocketHandler::listen(){
    cout << "listen" << endl;
    if(socketLibrary::listen(this->sfd,this->backlog) < 0){
        error("Error in listen method");
    }
}

int SocketHandler::getSfd(){
    return this->sfd;
}

client::Client SocketHandler::accept(){
    using namespace socketLibrary;
    cout << "accept" << endl;
    char ipAddress[INET_ADDRSTRLEN];
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    int clientSfd = socketLibrary::accept(this->sfd,(struct socketLibrary::sockaddr*) &addr, &addrlen);
    if(clientSfd == ERROR_SFD){
        error("Accept method return -1");
    }
    cout << "ClientSfd in accept is -> " << clientSfd << endl;
    inet_ntop(AF_INET, &(addr.sin_addr), ipAddress, INET_ADDRSTRLEN);
    cout << "Ipaddress is : ->   " << ipAddress << endl;
    cout << addr.sin_port << endl;
    client::Client client(clientSfd,ipAddress);
    cout << "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" << endl;
    cout << client.getSktSfd() << endl;
    return client;
}

int SocketHandler::connect(const string ip,int port){
    cout << "I m in connect method" << endl;
    cout << "SFD is " << this->sfd << endl;
    cout << ip << endl;
    cout << port << endl;
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
    cout << "Im in read message" << endl;
    char buffer[255];
    //int ceva = socketLibrary::read(this->sfd, buffer, 255);
    cout << this->sfd << endl;
    int ceva = socketLibrary::recv(this->sfd, buffer, 255, 0);
    cout << "ceva is " << ceva << endl;
    cout << buffer << endl;
    if( ceva < 0){
        error("Cannot read");
    }
}
}
