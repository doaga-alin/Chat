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

Client::Client(string serverIp, int portNo){
    cout << "Client constructor with portno and serverIp" << endl;
    skt = new chat::SocketHandler();
    this->portNo  = portNo;
    this->serverIp = serverIp;


}
Client::~Client(){
    cout << "Client destructor" << endl;
    delete skt;
}

void Client::connectToServer(){
    this->skt->connect(this->serverIp,this->portNo);
}
void Client::readMessage(){
    this->skt->read(this->buffer, &(this->buffSize));
}

void Client::sendMessage(char * str){
    this->skt->send(str);
}

void Client::printMessage(){
    cout << this->buffer << endl;
}

void Client::error(const char* msg){
    perror(msg);
    exit(1);
}

}
