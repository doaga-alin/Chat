#include "Server.hpp"
#include <iostream>
using std::cout;
using std::endl;
namespace server{
Server::Server(){

    cout << skt.bind() << endl;
    cout << skt.listen() << endl;

}

Server::~Server(){
    cout << "Server destructor" << endl;
}

void Server::acceptIncommingConnections(){
    cout << "Accept incomming connections" << endl;
    while(1){
        cout << "while(1)" << endl;
        this->connSfd = skt.accept();
        cout << this->connSfd << endl;
    }
}




}
