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

    cout << "Client constructor with sfd and ipAddress" << endl;
    skt = new chat::SocketHandler(sfd);
    this->ipAddress = ipAddress;
}

int Client::getSktSfd(){
        return this->skt->getSfd();
    }

Client::Client(string serverIp, int portNo){
    cout << "Client constructor with portno and serverIp" << endl;
    skt = new chat::SocketHandler();
    this->portNo  = portNo;
    this->serverIp = serverIp;
}

Client::Client(const Client& rhs){
    cout << "Copy constructor" << endl;
    skt = new chat::SocketHandler(*rhs.skt);
    ERROR_SFD = rhs.ERROR_SFD;
    //buffer = rhs.buffer;
    buffSize = rhs.buffSize;
    ipAddress = rhs.ipAddress;
    serverIp = rhs.serverIp;
    portNo = rhs.portNo;
}

Client& Client::operator=(const Client& rhs){
    cout << "Copy constructor" << endl;
    skt = new chat::SocketHandler(*rhs.skt);
    ERROR_SFD = rhs.ERROR_SFD;
    //buffer = rhs.buffer;
    buffSize = rhs.buffSize;
    ipAddress = rhs.ipAddress;
    serverIp = rhs.serverIp;
    portNo = rhs.portNo;

    return *this;
}

Client::~Client(){
    cout << "Client destructor" << endl;
    delete skt;
}

void Client::connectToServer(){
    cout << this->skt->connect(this->serverIp,this->portNo) << endl;
}
void Client::readMessage(){
    this->skt->read(this->buffer, &(this->buffSize));
}

void Client::sendMessage(char * str){
    cout << str << endl;
    this->skt->send(str);
}

void Client::printMessage(){
    cout << "cevaaaaaaaaaaaaaa" << endl;
    cout << this->buffer << endl;
}

void Client::error(const char* msg){
    perror(msg);
    exit(1);
}

}
