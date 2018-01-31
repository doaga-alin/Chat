#include "Server.hpp"
#include <iostream>
using std::cout;
using std::endl;
namespace server{
Server::Server(int port){
    skt.printSfd();
    cout << skt.bind(port) << endl;
    cout << skt.listen() << endl;

}

Server::~Server(){
    cout << "Server destructor" << endl;
}

void Server::acceptIncommingConnections(){
    cout << "Accept incomming connections" << endl;
    while(1){
        cout << "while(1)" << endl;
        sktAccept = skt.accept();
    }
}




}
