#include "Server.hpp"
#include <iostream>
using std::cout;
using std::endl;
namespace server{
Server::Server(int port){
    cout << "Server constructor" << endl;
    cout << "port in server is " << port << endl;
    skt = new chat::SocketHandler();
    skt->bind(port);
    skt->listen();

}

Server::~Server(){
    cout << "Server destructor" << endl;
    delete skt;

}

void Server::error(char* msg){
    perror(msg);
    exit(1);
}

void Server::dealWithIncommingConnections(){
    cout << "Accept incomming connections" << endl;

    while(1){
        cout << "while(1)" << endl;
        client = new client::Client(skt->accept());
        client->readMessage();
        client->printMessage();
        //multiplexare -> select
    }
}




}
