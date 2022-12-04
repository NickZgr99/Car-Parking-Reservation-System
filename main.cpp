/*

------------- Car Parking Reservation System in C++ -------------

*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <list>
#include <windows.h>

// #include "User.h"
#include "LoginFunc.h"

using namespace std;

int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,10);
    LoginSystem park_login;
    park_login.menu();

    return 0;
}
