#include "Client.hpp"
#include<iostream>
using std::cout;
using std::endl;
namespace client{
Client::Client(){
    cout << "Client constuctor" << endl;
    skt = new chat::SocketHandler();
}

Client::Client(int sfd,char* ipAddress){

    cout << "SocketHandler constructor" << endl;
    this->sfd = sfd;
    this->ipAddress = ipAddress;

    if(this->sfd == ERROR_SFD){
        error("Error when creating socket");
    }
}

Client::~Client(){
    cout << "Client destructor" << endl;
    delete skt;
}

void Client::readMessage(char* buffer, int* buffSize){
    this->skt.read(buffer, buffSize);
}


void Client::error(const char* msg){
    perror(msg);
    exit(1);
}

}
