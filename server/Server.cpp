#include "Server.hpp"
#include <iostream>
using std::cout;
using std::endl;
namespace server{
Server::Server(int port){
    skt = new chat::SocketHandler();
    skt->bind(port);
    skt->listen();

}

Server::~Server(){
    delete skt;
    delete client;

}

void Server::error(const char* msg){
    perror(msg);
    exit(1);
}

void Server::dealWithIncommingConnections(){

    while(true){
        cout << "while(1)" << endl;
        client = skt->accept();
        client->readMessage();
        client->printMessage();
    }
}




}
