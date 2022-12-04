#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <list>

#include "User.h"

using namespace std;

User::User(string UserName, string E_mail, string PassWord)
{
    user_name = UserName;
    Email = E_mail;
    user_password = PassWord;
}

void User::set_user_name(string Uname)
{
    user_name = Uname;
}

void User::set_email(string email)
{
    Email = email;
}

void User::set_password(string passW)
{
    user_password = passW;
}

string User::get_username()
{
    return user_name;
}

string User::get_email()
{
    return Email;
}

void User::get_password_last_2_elements()
{
    int size_of_string = user_password.size();
    cout << "The last 2 elements of your password are: ";
    for(int i = size_of_string-2; i < size_of_string; i++)
    {
        cout << user_password[i];
    }
}

string User::get_password()
{
    return user_password;
}

Admin::Admin(string UserName, string E_mail,string PassWord)
{
    user_name = UserName;
    Email = E_mail;
    user_password = PassWord;
}

void Admin::showUser(User& user_to_show)
{
    cout << "\nUser's username is -> " << user_to_show.get_username() << endl;
    cout << "Would you also like to view the user's password? [Y/N]" << endl;
    string choice;
    cin >> choice;
    if(choice == "Y" | choice == "Yes" | choice == "yes" | choice == "y" | choice == "YES")
    {
        cout << "User's password: " << user_to_show.get_password();
        cout << "\n\n\t--------- User has been displayed ---------\n";
    }
    else if (choice == "N" | choice == "No" | choice == "no" | choice == "n" | choice == "NO")
    {
        cout << "\n\n\t--------- User has been displayed ---------\n";
    }
    else
    {
        cout << "\n\n Wrong choice. Please type your choice as Y or N!\n";
    }
}

Staff_Member::Staff_Member(string UserName, string E_mail, string PassWord)
{
    user_name = UserName;
    Email = E_mail;
    user_password = PassWord;
}

void Staff_Member::showUser(User& user_to_show)
{
    cout << "\nUser's username is -> " << user_to_show.get_username() << endl;
    cout << "Would you also like to view the user's password? [Y/N]" << endl;
    string choice;
    cin >> choice;
    if(choice == "Y" | choice == "Yes" | choice == "yes" | choice == "y" | choice == "YES")
    {
        cout << "User's password: " << user_to_show.get_password();
        cout << "\n\n\t--------- User has been displayed ---------\n";
    }
    else if (choice == "N" | choice == "No" | choice == "no" | choice == "n" | choice == "NO")
    {
        cout << "\n\n\t--------- User has been displayed ---------\n";
    }
    else
    {
        cout << "\n\n Wrong choice. Please type your choice as Y or N!\n";
    }
}
