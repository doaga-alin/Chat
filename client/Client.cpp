#include "Client.hpp"
#include<iostream>
using std::cout;
using std::endl;
namespace client{
Client::Client(){
    cout << "Client constuctor" << endl;
    skt = new chat::SocketHandler();
}
// remove duplicated code
Client::Client(int sfd,char* ipAddress){

    cout << "Client constructor with sfd and ipAddress" << endl;
    skt = new chat::SocketHandler(sfd);
    this->ipAddress = ipAddress;
}

Client::Client(string serverIp, int portNo){
    skt = new chat::SocketHandler();
    this->portNo  = portNo;
    this->serverIp = serverIp;
}


Client::~Client(){
    cout << "Client destructor" << endl;
    //check it
    delete skt;
}

void Client::connectToServer(){
    cout << this->skt->connect(this->serverIp,this->portNo) << endl;
}
void Client::readMessage(){
    this->skt->read(this->buffer, &(this->buffSize));
}

void Client::sendMessage(const char* str){
    cout << str << endl;
    this->skt->send(str);
}

void Client::printMessage(){
    cout << this->buffer << endl;
}

}
