#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Helper.hpp"
using namespace std;
namespace helper{
void Helper::error(const string msg){
    perror(msg.c_str());
    exit(1);
}
}
