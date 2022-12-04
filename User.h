#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <list>

using namespace std;

class User
{
protected:
    string user_name, Email, user_password;
    bool vip_access = false;
// Member Functions of User Class
public:
    User(){}
    User(string UserName, string E_mail, string PassWord);
    void set_user_name(string Uname);
    void set_password(string passW);
    void set_email(string email);
    string get_username();
    void get_password_last_2_elements();
    string get_password();
    string get_email();
};

class Admin:public User
{
private:
    bool vip_access = true;
public:
    Admin(){}
    Admin(string UserName, string E_mail, string PassWord);
    void showUser(User& user_to_show);
    void delUser(User& user_to_del);
};


class Staff_Member:public User
{
private:
    bool vip_access = true;
public:
    Staff_Member(){}
    Staff_Member(string UserName, string E_mail, string PassWord);
    void showUser(User& user_to_show);
};
