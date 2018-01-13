#include <iostream>
#include "common/SocketHandler.hpp"
using namespace std;
using namespace chat;
int main()
{
    SocketHandler sh;
    cout << sh.getSfdNumber() << endl;
    SocketHandler sh2(sh);
    cout << sh2.getSfdNumber() << endl;
    SocketHandler sh3(sh3);
    cout << sh3.getSfdNumber() << endl;

    return 0;
}
