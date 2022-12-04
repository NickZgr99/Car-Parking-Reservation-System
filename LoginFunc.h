#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <list>

#include "User.h"
#include "Parking.h"

using namespace std;

class LoginSystem
{
private:
    list<User> users;
    list<Admin> admins;
    list<Staff_Member> staff_members;
    int number_of_users = 0, number_of_admins = 0, number_of_staff_members = 0;
    string logged_in_user_u, logged_in_user_p;
    Parking P1;
public:
    void createNewAccount();
    void createUser();
    void createAdmin();
    void createStaffMember();
    void login();
    void login_admin(string username, string password);
    void login_user(string username,string password);
    void login_staff(string username,string password);
    void delUser();
    void delStaff();
    void delAdmin(string username);
    void show_user_info(string username);
    void show_staff_info(string username);
    void show_admin_info(string username);
    void change_user_info(string username);
    void change_staff_info(string username);
    void change_admin_info(string username);
    void show_users();
    void show_admins();
    void show_staff_members();
    void menu();
};
