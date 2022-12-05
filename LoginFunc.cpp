#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <list>

#include "LoginFunc.h"

using namespace std;

/// Member functions of Login class

void LoginSystem::createNewAccount()
{
    system("cls");
    string choice = "0", staff_key = "staff",adm_key = "admin";
    while(choice !=  "1"|| choice != "2" || choice != "3" || choice != "4")
    {
        cout << "\n\n\t----- Create Account -----";
        cout << "\n\n\t|1. Create User Account\n";
        cout << "\t|2. Create Staff Member Account\n";
        cout << "\t|3. Create Admin Account\n";
        cout << "\t|4. Go to Menu\n";
        cout << "\n\n\tPlease select your choice: ";
        cin >> choice;
        if(choice == "1" || choice == "2" || choice == "3" || choice == "4")
        {
            break;
        }
        else
        {
            cout << "\n\n\tWrong Input. Please try again!\n\n\t";
            system("pause");
            system("cls");
        }
    }
    if(choice == "1")
    {
        system("cls");
        createUser();
    }
    else if(choice == "2")
    {
        system("cls");
        string key_1;
        while(key_1 != staff_key)
        {
            cout << "\n\n\tPlease enter the staff secret key (No Spaces):  ";
            cin >> key_1;
            system("cls");
            if(key_1 == staff_key)
            {
                break;
            }
            else
            {
                cout << "\n\n\tWrong key. Try again!";
            }
        }
        createStaffMember();
    }
    else if(choice == "3")
    {
        system("cls");
        string key_2;
        while(key_2 != adm_key)
        {
            cout << "\n\n\tPlease enter the admin secret key (No Spaces):  ";
            cin >> key_2;
            system("cls");
            if(key_2 == adm_key)
            {
                break;
            }
            else
            {
                cout << "\n\n\tWrong key. Try again!";
            }
        }
        createAdmin();
    }
    else if(choice == "4")
    {
        system("cls");
        menu();
    }
}

void LoginSystem::createUser()
{
    int valid_choice = 0;
    while(valid_choice != 1)
    {
        system("cls");
        cout << "\n\n\t|----- Creation of User Account -----|\n\n";
        string userName, e_mail, pass_word;
        cout << "\n\tPlease enter a username(No spaces): ";
        cin >> userName;
        cout << "\n\tPlease enter an email(No spaces): ";
        cin >> e_mail;
        cout << "\n\tPlease enter a password(No spaces): ";
        cin >> pass_word;
        if(users.size() >= 1 || admins.size() >= 1 || staff_members.size() >= 1)
        {
            list<User>::iterator itr_u;
            list<Admin>::iterator itr_a;
            list<Staff_Member>::iterator itr_s;
            for(itr_u = users.begin(); itr_u != users.end(); itr_u++)
            {
                if(userName == (*itr_u).get_username())
                {
                    valid_choice = 0;
                    cout << "\n\n\tThe user-name you have entered is owned by another user. \n\n\tPlease enter a different user-name!\n\n\t";
                    system("pause");
                    menu();
                }
                else
                {
                    valid_choice = 1;
                }
            }
            for(itr_a = admins.begin(); itr_a != admins.end(); itr_a++)
            {
                if(userName == (*itr_a).get_username())
                {
                    valid_choice = 0;
                    cout << "\n\n\tThe user-name you have entered is owned by another user. \n\n\tPlease enter a different user-name!\n\n\t";
                    system("pause");
                    menu();
                }
                else
                {
                    valid_choice = 1;
                }
            }
            for(itr_s = staff_members.begin(); itr_s != staff_members.end(); itr_s++)
            {
                if(userName == (*itr_s).get_username())
                {
                    valid_choice = 0;
                    cout << "\n\n\tThe user-name you have entered is owned by another user. \n\n\tPlease enter a different user-name!\n\n\t";
                    system("pause");
                    menu();
                }
                else
                {
                    valid_choice = 1;
                }
            }
        }
        else
        {
            valid_choice = 1;
        }
        if(valid_choice == 1)
        {
            User* userPtr = new User(userName, e_mail, pass_word);
            users.push_front(*userPtr);
            number_of_users++;
            delete userPtr;
            cout << "\n\n\tYour user account has been created with username: " << userName << "\n\n\t";
            system("pause");
            menu();
        }
        else
        {
            cout << "\n\n\tThe user-name you have entered is owned by another user. \n\n\tPlease enter a different user-name!\n\n\t";
            system("pause");
        }
    }
}

void LoginSystem::createAdmin()
{
    int valid_choice = 0;
    while(valid_choice != 1)
    {
        system("cls");
        cout << "\n\n\t|----- Creation of Admin Account -----|\n\n";
        string userName, e_mail, pass_word;
        cout << "\n\tPlease enter a username(No spaces): ";
        cin >> userName;
        cout << "\n\tPlease enter an email(No spaces): ";
        cin >> e_mail;
        cout << "\n\tPlease enter a password(No spaces): ";
        cin >> pass_word;
        if(users.size() >= 1 || admins.size() >= 1 || staff_members.size() >= 1)
        {
            list<User>::iterator itr_u;
            list<Admin>::iterator itr_a;
            list<Staff_Member>::iterator itr_s;
            for(itr_u = users.begin(); itr_u != users.end(); itr_u++)
            {
                if(userName == (*itr_u).get_username())
                {
                    valid_choice = 0;
                    cout << "\n\n\tThe user-name you have entered is owned by another user. \n\n\tPlease enter a different user-name!\n\n\t";
                    system("pause");
                    menu();
                }
                else
                {
                    valid_choice = 1;
                }
            }
            for(itr_a = admins.begin(); itr_a != admins.end(); itr_a++)
            {
                if(userName == (*itr_a).get_username())
                {
                    valid_choice = 0;
                    cout << "\n\n\tThe user-name you have entered is owned by another user. \n\n\tPlease enter a different user-name!\n\n\t";
                    system("pause");
                    menu();
                }
                else
                {
                    valid_choice = 1;
                }
            }
            for(itr_s = staff_members.begin(); itr_s != staff_members.end(); itr_s++)
            {
                if(userName == (*itr_s).get_username())
                {
                    valid_choice = 0;
                    cout << "\n\n\tThe user-name you have entered is owned by another user. \n\n\tPlease enter a different user-name!\n\n\t";
                    system("pause");
                    menu();
                }
                else
                {
                    valid_choice = 1;
                }
            }
        }
        else
        {
            valid_choice = 1;
        }
        if(valid_choice == 1)
        {
            Admin* adminPtr = new Admin(userName, e_mail, pass_word);
            admins.push_front(*adminPtr);
            delete adminPtr;
            cout << "\n\n\tYour admin account has been created with username: " << userName << "\n\n\t";
            system("pause");
            menu();
        }
        else
        {
            cout << "\n\n\tThe user-name you have entered is owned by another user. \n\n\tPlease enter a different user-name!\n\n\t";
            system("pause");
        }
    }
}

void LoginSystem::createStaffMember()
{
    int valid_choice = 0;
    while(valid_choice != 1)
    {
        system("cls");
        cout << "\n\n\t|----- Creation of Staff Member Account -----|\n\n";
        string userName, e_mail, pass_word;
        cout << "\n\tPlease enter a username(No spaces): ";
        cin >> userName;
        cout << "\n\tPlease enter an email(No spaces): ";
        cin >> e_mail;
        cout << "\n\tPlease enter a password(No spaces): ";
        cin >> pass_word;
        if(users.size() >= 1 || admins.size() >= 1 || staff_members.size() >= 1)
        {
            list<User>::iterator itr_u;
            list<Admin>::iterator itr_a;
            list<Staff_Member>::iterator itr_s;
            for(itr_u = users.begin(); itr_u != users.end(); itr_u++)
            {
                if(userName == (*itr_u).get_username())
                {
                    valid_choice = 0;
                    cout << "\n\n\tThe user-name you have entered is owned by another user. \n\n\tPlease enter a different user-name!\n\n\t";
                    system("pause");
                    menu();
                }
                else
                {
                    valid_choice = 1;
                }
            }
            for(itr_a = admins.begin(); itr_a != admins.end(); itr_a++)
            {
                if(userName == (*itr_a).get_username())
                {
                    valid_choice = 0;
                    cout << "\n\n\tThe user-name you have entered is owned by another user. \n\n\tPlease enter a different user-name!\n\n\t";
                    system("pause");
                    menu();
                }
                else
                {
                    valid_choice = 1;
                }
            }
            for(itr_s = staff_members.begin(); itr_s != staff_members.end(); itr_s++)
            {
                if(userName == (*itr_s).get_username())
                {
                    valid_choice = 0;
                    cout << "\n\n\tThe user-name you have entered is owned by another user. \n\n\tPlease enter a different user-name!\n\n\t";
                    system("pause");
                    menu();
                }
                else
                {
                    valid_choice = 1;
                }
            }
        }
        else
        {
            valid_choice = 1;
        }
        if(valid_choice == 1)
        {
            Staff_Member* staffPtr = new Staff_Member(userName, e_mail, pass_word);
            staff_members.push_front(*staffPtr);
            delete staffPtr;
            cout << "\n\n\tYour staff member account has been created with username: " << userName << "\n\n\t";
            system("pause");
            menu();
        }
        else
        {
            cout << "\n\n\tThe user-name you have entered is owned by another user. \n\n\tPlease enter a different user-name!\n\n\t";
            system("pause");
        }
    }
}

void LoginSystem::login()
{
    /// Before Logging in
    string _user_ = "1", _staff_member_ = "2", _admin_ = "3", choice;
    while(choice != "1" || choice != "2" || choice != "3" || choice != "4")
    {
        system("cls");
        cout << "\n\n\t----- Login -----";
        cout << "\n\n\t|1. Login as User\n";
        cout << "\t|2. Login as Staff member\n";
        cout << "\t|3. Login as Admin\n";
        cout << "\t|4. Go to Menu\n";
        cout << "\n\n\tPlease enter one of the given choices: ";
        cin >> choice;
        if(choice == "1" || choice == "2" || choice == "3" || choice == "4")
        {
            break;
        }
        else
        {
            cout << "\n\n\tWrong Input. Please try again!\n\n\t";
            system("pause");
        }
    }
    if(choice == _user_)
    {
        int succ_log = 0;
        string user_name, pass_word, e_mail;
        while(succ_log != 1)
        {
            system("cls");
            cout << "\n\n\t----- Logging in as user -----";
            cout << "\t\t\t\t\t\t GO BACK: 0";
            cout << "\n\n\tPlease enter your username: ";
            cin >> user_name;
            if(user_name == "0")
            {
                menu();
            }
            cout <<"\n\tPlease enter your password: ";
            cin >> pass_word;
            if(pass_word == "0")
            {
                menu();
            }
            for(auto n: users)
            {
                if((user_name == n.get_username()) && (pass_word == n.get_password()))
                {
                    system("cls");
                    cout << "\n\n\tSuccessfully logged in as user with username: " << user_name << endl << endl;
                    succ_log = 1;
                    login_user(user_name, pass_word); /// Logged in as user
                }
            }
            if(succ_log == 0)
            {
                system("cls");
                cout << "\n\n\tYour username and password are not correct. Please try again!\n\n\t";
                system("pause");
            }
        }
    }
    else if(choice == _staff_member_)
    {
        int succ_log = 0;
        string user_name, pass_word;
        while(succ_log != 1)
        {
            system("cls");
            cout << "\n\n\t----- Logging in as staff -----";
            cout << "\t\t\t\t\t\t GO BACK: 0";
            cout << "\n\n\tPlease enter your username: ";
            cin >> user_name;
            if(user_name == "0")
            {
                menu();
            }
            cout <<"\n\tPlease enter your password: ";
            cin >> pass_word;
            if(pass_word == "0")
            {
                menu();
            }
            for(auto n: staff_members)
            {
                if((user_name == n.get_username()) && (pass_word == n.get_password()))
                {
                    system("cls");
                    cout << "\n\n\tSuccessfully logged in as staff member with username: " << user_name << endl << endl;
                    succ_log = 1;
                    login_staff(user_name, pass_word); /// Logged in as staff member
                }
            }
            if(succ_log == 0)
            {
                system("cls");
                cout << "\n\n\tYour username and password are not correct. Please try again!\n\n\t";
                system("pause");
            }
        }
    }
    else if(choice == _admin_)
    {
        int succ_log = 0;
        string user_name, pass_word;
        while(succ_log != 1)
        {
            system("cls");
            cout << "\n\n\t----- Logging in as admin -----";
            cout << "\t\t\t\t\t\t GO BACK: 0";
            cout << "\n\n\tPlease enter your username: ";
            cin >> user_name;
            if(user_name == "0")
            {
                menu();
            }
            cout <<"\n\tPlease enter your password: ";
            cin >> pass_word;
            if(pass_word == "0")
            {
                menu();
            }
            for(auto n: admins)
            {
                if((user_name == n.get_username()) && (pass_word == n.get_password()))
                {
                    system("cls");
                    cout << "\n\n\tSuccessfully logged in as admin with username: " << user_name << endl << endl;
                    succ_log = 1;
                    login_admin(user_name, pass_word); /// Logged in as admin
                }
            }
            if(succ_log == 0)
            {
                system("cls");
                cout << "\n\n\tYour username and password are not correct. Please try again!\n\n\t";
                system("pause");
            }
        }
    }
    else if(choice == "4")
    {
        system("cls");
        menu();
    }
}

void LoginSystem::login_user(string username, string password)
{
    logged_in_user_u = username, logged_in_user_p = password;
    string choice;
    while(choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "5"
          || choice != "6" || choice != "7" || choice != "8" || choice != "9")
    {

        system("cls");
        cout << "\n\n\t----- Welcome User -----\n\n";
        cout << "\t|1.     Reserve a parking lot\n";
        cout << "\t|2.     Depart a vehicle\n";
        cout << "\t|3.     Display free parking lots\n";
        cout << "\t|4.     View your parking lots\n";
        cout << "\t|5.     View your info\n";
        cout << "\t|6.     Change your info\n";
        cout << "\t|8.     Logout\n";
        cout << "\t|9.     Exit";
        cout << "\n\n\tPlease enter one of the given choices: ";
        cin >> choice;
        if(choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5" ||
                                        choice == "6" || choice == "7" || choice == "8" || choice == "9")
        {
            if(choice == "1")
            {
                system("cls");
                P1.reserve_parking_lot(username);
                cout << "\n\n\t";
                system("pause");
                choice = "0";
            }
            else if(choice == "2")
            {
                system("cls");
                P1.depart_vehicle_user(logged_in_user_u);
                cout << "\n\n\t";
                system("pause");

            }
            else if(choice == "3")
            {
                P1.display_free_parking_lots();
                cout << "\n\n\t";
                //system("pause");
                choice = "0";
            }
            else if(choice == "4")
            {
                if(P1.Used_Car_Lots.size() >= 1)
                {
                    system("cls");
                    cout << "\n\n\n\t\t\t\t\t----- Your Parking Lots -----\n\n\t";
                    P1.display_your_parking_lots(logged_in_user_u);
                    system("pause");
                    choice == "0";
                }
                else
                {
                    cout << "\n\n\tAll parking lots are free!\n\n\t";
                    system("pause");
                    choice = "0";
                }
            }
            else if(choice == "5")
            {
                system("cls");
                show_user_info(username);
                cout << "\n\n\t";
                system("pause");
                choice = "0";
            }
            else if(choice == "6")
            {
                system("cls");
                change_user_info(username);
                cout << "\n\n\t";
                system("pause");
                choice = "0";
            }
            else if(choice == "8")
            {
                logged_in_user_u = "";
                logged_in_user_p = "";
                menu();
            }
            else if(choice == "9")
            {
                system("cls");
                exit(0);
            }
        }
        else
        {
            cout << "\n\n\tWrong Input. Please try again!\n\n\t";
            system("pause");
        }
    }
}

void LoginSystem::login_staff(string username, string password)
{
    logged_in_user_u = username, logged_in_user_p = password;
    string choice;
    while(choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "5" || choice != "6" || choice != "7"
          || choice != "8" || choice != "9" || choice != "10" || choice != "11")
    {

        system("cls");
        cout << "\n\n\t----- Welcome Staff Member -----\n\n";
        cout << "\t|1.     Use a Parking Lot\n";
        cout << "\t|2.     Display free parking lots\n";
        cout << "\t|3.     Display used parking lots\n";
        cout << "\t|4.     View User Info\n";
        cout << "\t|5.     View Staff Info\n";
        cout << "\t|6.     View your info\n";
        cout << "\t|7.     Change your info\n";
        cout << "\t|8.     Delete User\n";
        cout << "\t|9.     Depart Vehicle\n";
        cout << "\t|10.    Logout\n";
        cout << "\t|11.    Exit";
        cout << "\n\n\tPlease enter one of the given choices: ";
        cin >> choice;
        if(choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5" ||
                choice == "6" || choice == "7" || choice == "8" || choice == "9" || choice == "10" || choice == "11")
        {
            if(choice == "1")
            {
                system("cls");
                P1.use_parking_lot(logged_in_user_u);
                cout << "\n\n\t";
                system("pause");
                choice = "0";
            }
            else if(choice == "2")
            {
                P1.display_free_parking_lots();
                cout << "\n\n\t";
                //system("pause");
                choice = "0";
            }
            else if(choice == "3")
            {
                if(P1.Used_Car_Lots.size() >= 1)
                {
                    cout << "\n\n\n\t\t\t\t\t----- Used Parking Lots -----\n\n\t";
                    P1.display_used_parking_lots();
                    system("pause");
                    choice == "0";
                }
                else
                {
                    cout << "\n\n\tAll parking lots are free!\n\n\t";
                    system("pause");
                    choice = "0";
                }
            }
            else if(choice == "4")
            {
                system("cls");
                show_users();
                choice = "0";
            }
            else if(choice == "5")
            {
                system("cls");
                show_staff_members();
                choice = "0";
            }
            else if(choice == "5")
            {
                system("cls");
                show_staff_members();
                choice = "0";
            }
            else if(choice == "6")
            {
                system("cls");
                show_staff_info(username);
                cout << "\n\n\t";
                system("pause");
                choice = "0";
            }
            else if(choice == "7")
            {
                system("cls");
                change_staff_info(username);
                cout << "\n\n\t";
                system("pause");
                choice = "0";
            }
            else if(choice == "8")
            {
                system("cls");
                show_users();
                if(users.size() >= 1)
                {
                    delUser();
                }
                choice = "0";
            }
            else if(choice == "9")
            {
                system("cls");
                if(P1.Used_Car_Lots.size() >= 1)
                {
                    P1.depart_vehicle(logged_in_user_u);
                    cout << "\n\n\t";
                    system("pause");
                }
                else
                {
                    cout << "\n\n\tNo parking lots are used!\n\n\t";
                    system("pause");
                }
                choice == "0";
            }
            else if(choice == "10")
            {
                logged_in_user_u = "";
                logged_in_user_p = "";
                menu();
            }
            else if(choice == "11")
            {
                system("cls");
                exit(0);
            }
        }
        else
        {
            cout << "\n\n\tWrong Input. Please try again!\n\n\t";
            system("pause");
        }
    }
}

void LoginSystem::login_admin(string username, string password)
{
    logged_in_user_u = username, logged_in_user_p = password;
    string choice;
    while(choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "5" || choice != "6" || choice != "7" || choice != "8")
    {

        system("cls");
        cout << "\n\n\t----- Welcome Admin -----\n\n";
        cout << "\t|1.     Use a Parking Lot\n";
        cout << "\t|2.     Display free parking lots\n";
        cout << "\t|3.     Display used parking lots\n";
        cout << "\t|4.     View User Info\n";
        cout << "\t|5.     View Staff Info\n";
        cout << "\t|6.     View Admin Info\n";
        cout << "\t|7.     View your info\n";
        cout << "\t|8      Change your info\n";
        cout << "\t|9.     Delete User\n";
        cout << "\t|10.    Delete Staff Member\n";
        cout << "\t|11.    Delete Admin\n";
        cout << "\t|12.    Depart Vehicle\n";
        cout << "\t|13.    Logout\n";
        cout << "\t|14.    Exit";
        cout << "\n\n\tPlease enter one of the given choices: ";
        cin >> choice;
        if(choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5" || choice == "6" || choice == "7" ||
                choice == "8" || choice == "9" || choice == "10" || choice == "11" || choice == "12" || choice == "13" || choice == "14")
        {
            if(choice == "1")
            {
                system("cls");
                P1.use_parking_lot(logged_in_user_u);
                cout << "\n\n\t";
                system("pause");
                choice = "0";
            }
            else if(choice == "2")
            {
                P1.display_free_parking_lots();
                cout << "\n\n\t";
                //system("pause");
                choice = "0";
            }
            else if(choice == "3")
            {
                if(P1.Used_Car_Lots.size() >= 1)
                {
                    cout << "\n\n\n\t\t\t\t\t----- Used Parking Lots -----\n\n\t";
                    P1.display_used_parking_lots();
                    system("pause");
                    choice == "0";
                }
                else
                {
                    cout << "\n\n\tAll parking lots are free!\n\n\t";
                    system("pause");
                    choice = "0";
                }
            }
            else if(choice == "4")
            {
                system("cls");
                show_users();
                choice = "0";
            }
            else if(choice == "5")
            {
                system("cls");
                show_staff_members();
                choice = "0";
            }
            else if(choice == "6")
            {
                system("cls");
                show_admins();
                choice = "0";
            }
            else if(choice == "7")
            {
                system("cls");
                show_admin_info(username);
                cout << "\n\n\t";
                system("pause");
                choice = "0";
            }
            else if(choice == "8")
            {
                system("cls");
                change_admin_info(username);
                cout << "\n\n\t";
                system("pause");
                choice = "0";
            }
            else if(choice == "9")
            {
                system("cls");
                show_users();
                if(users.size() >= 1)
                {
                    delUser();
                }
                choice = "0";
            }
            else if(choice == "10")
            {
                system("cls");
                show_staff_members();
                if(staff_members.size() >= 1)
                {
                    delStaff();
                }
                choice = "0";
            }
            else if(choice == "11")
            {
                system("cls");
                show_admins();
                if(admins.size() >= 1)
                {
                    delAdmin(logged_in_user_u);
                }
                choice = "0";
            }
            else if(choice == "12")
            {
                system("cls");
                if(P1.Used_Car_Lots.size() >= 1)
                {
                    P1.depart_vehicle(logged_in_user_u);
                    cout << "\n\n\t";
                    system("pause");
                }
                else
                {
                    cout << "\n\n\tNo parking lots are used!\n\n\t";
                    system("pause");
                }
                choice == "0";
            }
            else if(choice == "13")
            {
                logged_in_user_u = "";
                logged_in_user_p = "";
                menu();
            }
            else if(choice == "14")
            {
                system("cls");
                exit(0);
            }
        }
        else
        {
            cout << "\n\n\tWrong Input. Please try again!\n\n\t";
            system("pause");
        }
    }
}

void LoginSystem::show_user_info(string username)
{
    list<User>::iterator itr1;
    for(itr1 = users.begin(); itr1 != users.end(); itr1++)
    {
        if((*itr1).get_username() == username)
        {
            cout << "\n\n\tUsername: \t" << (*itr1).get_username() << endl;
            cout << "\tE-mail: \t" << (*itr1).get_email() << endl;
        }
    }
}

void LoginSystem::show_staff_info(string username)
{
    list<Staff_Member>::iterator itr1;
    for(itr1 = staff_members.begin(); itr1 != staff_members.end(); itr1++)
    {
        if((*itr1).get_username() == username)
        {
            cout << "\n\n\tUsername: \t" << (*itr1).get_username() << endl;
            cout << "\tE-mail: \t" << (*itr1).get_email() << endl;
        }
    }
}

void LoginSystem::show_admin_info(string username)
{
    list<Admin>::iterator itr1;
    for(itr1 = admins.begin(); itr1 != admins.end(); itr1++)
    {
        if((*itr1).get_username() == username)
        {
            cout << "\n\n\tUsername: \t" << (*itr1).get_username() << endl;
            cout << "\tE-mail: \t" << (*itr1).get_email() << endl;
        }
    }
}

void LoginSystem::change_user_info(string username)
{
    string choice;
    list<User>::iterator itr1;
    while(choice != "1" || choice != "2" || choice != "3")
    {
        system("cls");
        cout << "\n\n\t|1.    Change E-mail\n";
        cout << "\t|2.    Change password\n";
        cout << "\t|3.    Go back";
        cout << "\n\n\tPlease enter your choice: ";
        cin >> choice;
        if(choice == "1")
        {
            for(itr1 = users.begin(); itr1 != users.end(); itr1++)
            {
                if((*itr1).get_username() == username)
                {
                    string new_email;
                    cout << "\n\n\tYour current e-mail address is: " << (*itr1).get_email();
                    cout << "\n\n\tPlease enter your new e-mail address: ";
                    cin >> new_email;
                    (*itr1).set_email(new_email);
                    cout << "\n\n\tE-mail address successfully changed!\n\n\t";
                    system("pause");
                    choice = "0";
                }
            }
        }
        else if(choice == "2")
        {
            for(itr1 = users.begin(); itr1 != users.end(); itr1++)
            {
                if((*itr1).get_username() == username)
                {
                    string new_password;
                    cout << "\n\n\tPlease enter your new password: ";
                    cin >> new_password;
                    (*itr1).set_password(new_password);
                    cout << "\n\n\tPassword successfully changed!\n\n\t";
                    system("pause");
                    choice = "0";
                }
            }
        }
        else if(choice == "3")
        {
            break;
        }
        else
        {
            cout << "\n\n\tPlease enter a valid choice!\n\n\t";
            system("pause");
        }
    }
}

void LoginSystem::change_staff_info(string username)
{
    string choice;
    list<Staff_Member>::iterator itr1;
    while(choice != "1" || choice != "2" || choice != "3")
    {
        system("cls");
        cout << "\n\n\t|1.    Change E-mail\n";
        cout << "\t|2.    Change password\n";
        cout << "\t|3.    Go back";
        cout << "\n\n\tPlease enter your choice: ";
        cin >> choice;
        if(choice == "1")
        {
            for(itr1 = staff_members.begin(); itr1 != staff_members.end(); itr1++)
            {
                if((*itr1).get_username() == username)
                {
                    string new_email;
                    cout << "\n\n\tYour current e-mail address is: " << (*itr1).get_email();
                    cout << "\n\n\tPlease enter your new e-mail address: ";
                    cin >> new_email;
                    (*itr1).set_email(new_email);
                    cout << "\n\n\tE-mail address successfully changed!\n\n\t";
                    system("pause");
                    choice = "0";
                }
            }
        }
        else if(choice == "2")
        {
            for(itr1 = staff_members.begin(); itr1 != staff_members.end(); itr1++)
            {
                if((*itr1).get_username() == username)
                {
                    string new_password;
                    cout << "\n\n\tPlease enter your new password: ";
                    cin >> new_password;
                    (*itr1).set_password(new_password);
                    cout << "\n\n\tPassword successfully changed!\n\n\t";
                    system("pause");
                    choice = "0";
                }
            }
        }
        else if(choice == "3")
        {
            break;
        }
        else
        {
            cout << "\n\n\tPlease enter a valid choice!\n\n\t";
            system("pause");
        }
    }
}

void LoginSystem::change_admin_info(string username)
{
    string choice;
    list<Admin>::iterator itr1;
    while(choice != "1" || choice != "2" || choice != "3")
    {
        system("cls");
        cout << "\n\n\t|1.    Change E-mail\n";
        cout << "\t|2.    Change password\n";
        cout << "\t|3.    Go back";
        cout << "\n\n\tPlease enter your choice: ";
        cin >> choice;
        if(choice == "1")
        {
            for(itr1 = admins.begin(); itr1 != admins.end(); itr1++)
            {
                if((*itr1).get_username() == username)
                {
                    string new_email;
                    cout << "\n\n\tYour current e-mail address is: " << (*itr1).get_email();
                    cout << "\n\n\tPlease enter your new e-mail address: ";
                    cin >> new_email;
                    (*itr1).set_email(new_email);
                    cout << "\n\n\tE-mail address successfully changed!\n\n\t";
                    system("pause");
                    choice = "0";
                }
            }
        }
        else if(choice == "2")
        {
            for(itr1 = admins.begin(); itr1 != admins.end(); itr1++)
            {
                if((*itr1).get_username() == username)
                {
                    string new_password;
                    cout << "\n\n\tPlease enter your new password: ";
                    cin >> new_password;
                    (*itr1).set_password(new_password);
                    cout << "\n\n\tPassword successfully changed!\n\n\t";
                    system("pause");
                    choice = "0";
                }
            }
        }
        else if(choice == "3")
        {
            break;
        }
        else
        {
            cout << "\n\n\tPlease enter a valid choice!\n\n\t";
            system("pause");
        }
    }
}

void LoginSystem::show_admins()
{
    int m = 0;
    cout << "\n\n\t|---------- Admin List ----------|\t\n\n";
    if(admins.size() == 0)
    {
        cout << "\t|\tThe admin list is empty!\n";
    }
    else
    {
        for (auto n: admins)
        {
            cout << "\t|\tAdmin " << ++m << ": " << n.get_username() << "\t\t e-mail: " << n.get_email() << endl;
        }
    }
    cout << "\n\n\t";
    system("pause");
}

void LoginSystem::show_users()
{
    int m = 0;
    cout << "\n\n\t|---------- User List ----------|\t\n\n";
    if(users.size() == 0)
    {
        cout << "\t|\tThe user list is empty!\n";
    }
    else
    {
        for (auto n: users)
        {
            cout << "\t|\tUser " << ++m << ": " << n.get_username() << "\t\t e-mail: " << n.get_email() << endl;
        }
    }
    cout << "\n\n\t";
    system("pause");
}

void LoginSystem::show_staff_members()
{
    int m = 0;
    cout << "\n\n\t|---------- Staff Member List ----------|\t\n\n";
    if(staff_members.size() == 0)
    {
        cout << "\t|\tThe staff list is empty!\n";
    }
    else
    {
        for (auto n: staff_members)
        {
            cout << "\t|\tStaff Member " << ++m << ": " << n.get_username() << "\t\t e-mail: " << n.get_email() << endl;
        }
    }
    cout << "\n\n\t";
    system("pause");
}
void LoginSystem::menu()
{
    system("cls");
    string choice = "0";
    if(P1.All_Car_Lots.size() == 0)
    {
        P1.create_parking_lots();
    }
    while(choice !=  "1"|| choice != "2" || choice != "3" || choice != "4")
    {
        cout << "\n\n\t|----------  Welcome to the Car Parking System  ----------|\n";
        cout << "\n\n\t                                          \n";
        cout << "\n\n\t|    1. Login";
        cout << "\n\n\t|    2. Create new account";
        cout << "\n\n\t|    3. Exit";
        cout << "\n\n\tPlease select your choice: ";
        cin >> choice;
        if(choice == "1" || choice == "2" || choice == "3")
        {
            break;
        }
        else
        {
            cout << "\n\n\tWrong Input. Please try again!\n\n\t";
            system("pause");
            system("cls");
        }
    }
    if(choice == "1")
    {
        login();
    }
    else if(choice == "2")
    {
        createNewAccount();
    }
    else if(choice == "3")
    {
        exit(0);
    }
}

void LoginSystem::delUser()
{
    string userName;
    int valid_choice = 0;
    multimap<string, string>::iterator itr1;
    while(valid_choice != 1)
    {
        cout << "\n\n\t|    Go back -> 0    |";
        cout << "\n\n\tEnter the user-name of the user to delete: ";
        cin >> userName;
        if(userName == "0")
        {
            break;
        }
        if(P1.User_Lot_Map.size() >= 1)
        {
            for(itr1 = P1.User_Lot_Map.begin(); itr1 != P1.User_Lot_Map.end(); itr1++)
            {
                if(itr1->first == userName)
                {
                    cout << "\n\n\tWARNING! One or more parking lots are still used by " << userName << "!";
                    cout << "\n\n\tTo delete this user account, you must ensure that their vehicles are departed!\n\n\t";
                    system("pause");
                    return;
                }
            }
        }
        list<User>::iterator itr;
        for(itr = users.begin(); itr != users.end(); itr++)
        {
            if(userName == (*itr).get_username())
            {
                valid_choice = 1;
                users.erase(itr);
                cout << "\n\n\tUser deleted!\n\n\t";
                system("pause");
                break;
            }
        }
        if(valid_choice == 0)
        {
            cout << "\n\n\tInvalid username. Try again!\n\n\t";
        }
    }
}

void LoginSystem::delStaff()
{
    string userName;
    int valid_choice = 0;
    multimap<string, string>::iterator itr1;
    while(valid_choice != 1)
    {
        cout << "\n\n\t|    Go back -> 0    |";
        cout << "\n\n\tEnter the user-name of the staff member to delete: ";
        cin >> userName;
        if(userName == "0")
        {
            break;
        }
        if(P1.User_Lot_Map.size() >= 1)
        {
            for(itr1 = P1.User_Lot_Map.begin(); itr1 != P1.User_Lot_Map.end(); itr1++)
            {
                if(itr1->first == userName)
                {
                    cout << "\n\n\tWARNING! One or more parking lots are still used by " << userName << "!";
                    cout << "\n\n\tTo delete this staff account, you must ensure that their vehicles are departed!\n\n\t";
                    system("pause");
                    return;
                }
            }
        }
        list<Staff_Member>::iterator itr;
        for(itr = staff_members.begin(); itr != staff_members.end(); itr++)
        {
            if(userName == (*itr).get_username())
            {
                valid_choice = 1;
                staff_members.erase(itr);
                cout << "\n\n\tStaff member deleted!\n\n\t";
                system("pause");
                break;
            }
        }
        if(valid_choice == 0)
        {
            cout << "\n\n\tInvalid username. Try again!\n\n\t";
        }
    }
}

void LoginSystem::delAdmin(string username)
{
    string userName;
    int valid_choice = 0;
    multimap<string, string>::iterator itr1;
    while(valid_choice != 1)
    {
        cout << "\n\n\t|    Go back -> 0    |";
        cout << "\n\n\tEnter the user-name of the admin to delete: ";
        cin >> userName;
        if(userName == "0")
        {
            break;
        }
        if(P1.User_Lot_Map.size() >= 1)
        {
            for(itr1 = P1.User_Lot_Map.begin(); itr1 != P1.User_Lot_Map.end(); itr1++)
            {
                if(itr1->first == userName)
                {
                    cout << "\n\n\tWARNING! One or more parking lots are still used by " << userName << "!";
                    cout << "\n\n\tTo delete this staff account, you must ensure that their vehicles are departed!\n\n\t";
                    system("pause");
                    return;
                }
            }
        }
        else if(username != userName)
        {
            list<Admin>::iterator itr;
            for(itr = admins.begin(); itr != admins.end(); itr++)
            {
                if(userName == (*itr).get_username())
                {
                    valid_choice = 1;
                    admins.erase(itr);
                    cout << "\n\n\tAdmin deleted!\n\n\t";
                    system("pause");
                }
            }
            if(valid_choice == 0)
            {
                cout << "\n\n\tInvalid username. Try again!\n\n\t";
            }
        }
        else
        {
            cout << "\n\n\tYou can't delete your own account!";
        }
    }
}
