#include "Client.hpp"
#include<iostream>
using std::cout;
using std::endl;
namespace client{
Client::Client(){
    cout << "Client constuctor" << endl;
}

Client::~Client(){
    cout << "Client destructor" << endl;
}

}
