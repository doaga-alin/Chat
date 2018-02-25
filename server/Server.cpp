#include "Server.hpp"
#include <iostream>
#include "../common/Helper.hpp"
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

void Server::dealWithIncommingConnections(){

    while(true){
        cout << "while(1)" << endl;
        client = skt->accept();
        client->readMessage();
        client->printMessage();
    }
}




}
