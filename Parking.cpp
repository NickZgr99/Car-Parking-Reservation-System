#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <list>

#include "Parking.h"

using namespace std;

bool isFloat(const std::string& s)
{
    try {
        std::stof(s);
        return true;
    } catch(...) {
        return false;
    }
}

/* Parking Class Member Functions */
void Parking::create_parking_lots()
{
    /* Parking Class Function

    This Function will create the names of the parking lots

    */
    for(auto & floor: Floors)
    {
        for(auto & area: Area_Names)
        {
            for(int i = 0; i < max_area_capacity; i++)
            {
                string str;
                str = floor[0] + area + to_string(i+1);
                All_Car_Lots.push_back(str);
                Available_Car_Lots.push_back(str);
            }
        }
    }
}

void Parking::display_all_parking_lots()
{
    /* Parking Class Function

    This Function will display all the parking lots

    */
    string choice;
    while(choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "5")
    {
        system("cls");
        cout << "\n\n\t     Display Parking Lots\n\n";
        cout << "\t|1.  1st Floor\n";
        cout << "\t|2.  2nd Floor\n";
        cout << "\t|3.  Ground Floor\n";
        cout << "\t|4.  Underground Floor";
        cout << "\t\t\t\t\t\tGo back -> 5";
        cout << "\n\n\tSelect floor to view parking lots: ";
        cin >> choice;
        if(choice == "4")
        {
            char u = 'U';
            char * str_ptr_u = &u;
            cout << "\n\t\t\t\t\t UNDERGROUND FLOOR PARKING LOTS \n\n";
            for(auto & elem: All_Car_Lots)
            {
                if(elem[0] == *str_ptr_u)
                {
                    cout << "\t" << elem;
                }
            }
            cout << "\n\n\t";
            system("pause");
        }
        else if(choice == "3")
        {
            char g = 'G';
            char * str_ptr_g = &g;
            cout << "\n\t\t\t\t\t GROUND FLOOR PRAKING LOTS \n\n";
            for(auto & elem: All_Car_Lots)
            {
                if(elem[0] == *str_ptr_g)
                {
                    cout << "\t" << elem;
                }
            }
            cout << "\n\n\t";
            system("pause");
        }
        else if(choice == "1")
        {
            char f = '1';
            char * str_ptr_1 = &f;
            cout << "\n\t\t\t\t\t 1st FLOOR PARKING LOTS \n\n";
            for(auto & elem: All_Car_Lots)
            {
                if(elem[0] == *str_ptr_1)
                {
                    cout << "\t" << elem;
                }
            }
            cout << "\n\n\t";
            system("pause");
        }
        else if(choice == "2")
        {
            char s = '2';
            char * str_ptr_2 = &s;
            cout << "\n\t\t\t\t\t 2nd FLOOR PRAKING LOTS \n\n";
            for(auto & elem: All_Car_Lots)
            {
                if(elem[0] == *str_ptr_2)
                {
                    cout << "\t" << elem;
                }
            }
            cout << "\n\n\t";
            system("pause");
        }
        else if(choice == "5")
        {
            break;
        }
        else
        {
            cout << "\n\n\tInvalid input. Please enter a valid input!\n\n\t";
            system("pause");
        }
    }
}

void Parking::display_free_parking_lots()
{
    /* Parking Class Function

    This Function will display all the parking lots

    */
    string choice;
    while(choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "5")
    {
        system("cls");
        cout << "\n\n\t     Displaying Free Parking Lots\n\n";
        cout << "\t|1.  1st Floor\n";
        cout << "\t|2.  2nd Floor\n";
        cout << "\t|3.  Ground Floor\n";
        cout << "\t|4.  Underground Floor";
        cout << "\t\t\t\t\t\tGo back -> 5";
        cout << "\n\n\tSelect floor to view parking lots: ";
        cin >> choice;
        if(choice == "4")
        {
            char u = 'U';
            char * str_ptr_u = &u;
            cout << "\n\t\t\t\t\t UNDERGROUND FLOOR PARKING LOTS \n\n";
            for(auto & elem: Available_Car_Lots)
            {
                if(elem[0] == *str_ptr_u)
                {
                    cout << "\t" << elem;
                }
            }
            cout << "\n\n\t";
            system("pause");
        }
        else if(choice == "3")
        {
            char g = 'G';
            char * str_ptr_g = &g;
            cout << "\n\t\t\t\t\t GROUND FLOOR PARKING LOTS \n\n";
            for(auto & elem: Available_Car_Lots)
            {
                if(elem[0] == *str_ptr_g)
                {
                    cout << "\t" << elem;
                }
            }
            cout << "\n\n\t";
            system("pause");
        }
        else if(choice == "1")
        {
            char f = '1';
            char * str_ptr_1 = &f;
            cout << "\n\t\t\t\t\t 1st FLOOR PARKING LOTS \n\n";
            for(auto & elem: Available_Car_Lots)
            {
                if(elem[0] == *str_ptr_1)
                {
                    cout << "\t" << elem;
                }
            }
            cout << "\n\n\t";
            system("pause");
        }
        else if(choice == "2")
        {
            char s = '2';
            char * str_ptr_2 = &s;
            cout << "\n\t\t\t\t\t 2nd FLOOR PARKING LOTS \n\n";
            for(auto & elem: Available_Car_Lots)
            {
                if(elem[0] == *str_ptr_2)
                {
                    cout << "\t" << elem;
                }
            }
            cout << "\n\n\t";
            system("pause");
        }
        else if(choice == "5")
        {
            break;
        }
        else
        {
            cout << "\n\n\tInvalid input. Please enter a valid input!\n\n\t";
            system("pause");
        }
    }
}

void Parking::display_used_parking_lots()
{
    system("cls");
    int counts = 0;
    multimap<string, string>::iterator itr1;
    multimap<string, Vehicle>::iterator itr2;
    //cout << "\n\n\t" << username << "'s vehicles in the parking: ";
    if(User_Lot_Map.size() >= 1)
    {
        for(itr1 = User_Lot_Map.begin(); itr1 != User_Lot_Map.end(); itr1++)
        {
            if(Lot_Veh_Map.size() >= 1)
            {
                for(itr2 = Lot_Veh_Map.begin(); itr2 != Lot_Veh_Map.end(); itr2++)
                {
                    if(itr1->second == itr2->first)
                    {
                        cout << "\n\n\t"<< counts + 1 << ". " << itr1 -> second << " | " << itr1 -> first << " | "
                            << itr2 -> second.get_vehicle_brand() << " | " << itr2 -> second.get_vehicle_type()
                                << " | " << itr2 -> second.get_licence_plate();
                        counts++;
                    }
                }
            }
        }
    }
    cout << "\n\n\t";
}

void Parking::display_your_parking_lots(string username)
{
    int counts = 0;
    multimap<string, string>::iterator itr1;
    multimap<string, Vehicle>::iterator itr2;
    //cout << "\n\n\t" << username << "'s vehicles in the parking: ";
    if(User_Lot_Map.size() >= 1)
    {
        for(itr1 = User_Lot_Map.begin(); itr1 != User_Lot_Map.end(); itr1++)
        {
            if(Lot_Veh_Map.size() >= 1)
            {
                for(itr2 = Lot_Veh_Map.begin(); itr2 != Lot_Veh_Map.end(); itr2++)
                {
                    if(itr1->first == username && itr1->second == itr2->first)
                    {
                        cout << "\n\n\t"<< counts + 1 << ". " << itr1 -> second << " | " << itr1 -> first << " | "
                            << itr2 -> second.get_vehicle_brand() << " | " << itr2 -> second.get_vehicle_type()
                                << " | " << itr2 -> second.get_licence_plate();
                        counts++;
                    }
                }
            }
        }
    }
    cout << "\n\n\t";
}

float Parking::reserve_parking_lot(string username)
{
    system("cls");
    string choice = "0";
    float cost;
    while(choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "5")
    {
        cout << "\n\n\tWhere would you like to park your vehicle?\n\n";
        cout << "\t|1.    1st Floor\n";
        cout << "\t|2.    2nd Floor\n";
        cout << "\t|3.    Ground Floor\n";
        cout << "\t|4.    Underground Floor\t\t\t";
        cout << "5.    Exit the parking\n";
        cout << "\n\tPlease enter your choice: ";
        cin >> choice;
        if(choice == "4")
        {
            char u = 'U';
            char * str_ptr_u = &u;
            int u_ = 0, correct_choice = 0;
            choice = "0";
            for(auto & elem: Available_Car_Lots)
            {
                if(elem[0] == *str_ptr_u)
                {
                    if(u_ == 0)
                    {
                        system("cls");
                        cout << "\n\n\t\t\t\t\t FREE UNDERGROUND FLOOR PARKING LOTS \n\n";
                        u_ = 1;
                    }
                    cout << "\t" << elem;
                }
            }
            if(u_ == 0)
            {
                choice = "0";
            }
            else if(u_ == 1)
            {
                while(correct_choice == 0)
                {
                    cout << "\n\n\tPlease select one of the available parking lots: ";
                    cin >> choice;
                    for(auto lot: Available_Car_Lots)
                    {
                        if(choice == lot)
                        {
                            correct_choice = 1;
                        }
                    }
                    if(correct_choice == 0)
                    {
                        cout << "\n\n\tEnter a valid parking lot!";
                    }
                    if(correct_choice == 1)
                    {
                        int correct = 0;
                        bool valid_hours = false;
                        string hours;
                        while(correct != 1)
                        {
                            cout << "\n\n\tThe parking charges 3$ per hour at any time of the day.";
                            cout << "\n\n\tThe parking operates 24/7.";
                            cout << "\n\n\tPlease enter the number of hours you desire to use the parking lot for: ";
                            cin >> hours;
                            valid_hours = isFloat(hours);
                            if(valid_hours == true)
                            {
                                cost = std::stof(hours) * 3;
                                correct = 1;
                            }
                            else
                            {
                                cout << "\n\n\tPlease enter a valid number!";
                            }
                        }
                    }
                }
                system("cls");
                cout << "\n\n\tPlease enter the following details of your car";
                Vehicle V1;
                V1.set_vehicle_details();
                add_vehicle(choice, V1, username, cost);
                cout << "\n\n\tPlease place your car on the parking lot " << choice;
                cout << "\n\n\n\tThank you for using the parking!\n\n\t";
                choice = "4";
                return cost;
            }
        }
        else if(choice == "3")
        {
            char g = 'G';
            char * str_ptr_g = &g;
            int g_ = 0, correct_choice = 0;
            choice = "0";
            for(auto & elem: Available_Car_Lots)
            {
                if(elem[0] == *str_ptr_g)
                {
                    if(g_ == 0)
                    {
                        system("cls");
                        cout << "\n\n\t\t\t\t\t FREE GROUND FLOOR PARKING LOTS \n\n";
                        g_ = 1;
                    }
                    cout << "\t" << elem;
                }
            }
            if(g_ == 0)
            {
                choice = "0";
            }
            else if(g_ == 1)
            {
                while(correct_choice == 0)
                {
                    cout << "\n\n\tPlease select one of the available parking lots: ";
                    cin >> choice;
                    for(auto lot: Available_Car_Lots)
                    {
                        if(choice == lot)
                        {
                            correct_choice = 1;
                        }
                    }
                    if(correct_choice == 0)
                    {
                        cout << "\n\n\tEnter a valid parking lot!";
                    }
                    if(correct_choice == 1)
                    {
                        int correct = 0;
                        bool valid_hours = false;
                        string hours;
                        while(correct != 1)
                        {
                            cout << "\n\n\tThe parking charges 3$ per hour at any time of the day.";
                            cout << "\n\n\tThe parking operates 24/7.";
                            cout << "\n\n\tPlease enter the number of hours you desire to use the parking lot for: ";
                            cin >> hours;
                            valid_hours = isFloat(hours);
                            if(valid_hours == true)
                            {
                                cost = std::stof(hours) * 3;
                                correct = 1;
                            }
                            else
                            {
                                cout << "\n\n\tPlease enter a valid number!";
                            }
                        }
                    }
                }
                system("cls");
                cout << "\n\n\tPlease enter the following details of your car";
                Vehicle V1;
                V1.set_vehicle_details();
                add_vehicle(choice, V1, username, cost);
                cout << "\n\n\tPlease place your car on the parking lot " << choice;
                cout << "\n\n\n\tThank you for using the parking!\n\n\t";
                choice = "3";
                break;
            }
        }
        else if(choice == "1")
        {
            char f = '1';
            char * str_ptr_1 = &f;
            int f_ = 0, correct_choice = 0;
            choice = "0";
            for(auto & elem: Available_Car_Lots)
            {
                if(elem[0] == *str_ptr_1)
                {
                    if(f_ == 0)
                    {
                        system("cls");
                        cout << "\n\n\t\t\t\t\t FREE 1st FLOOR PARKING LOTS \n\n";
                        f_ = 1;
                    }
                    cout << "\t" << elem;
                }
            }
            if(f_ == 0)
            {
                choice = "0";
            }
            else if(f_ == 1)
            {
                while(correct_choice == 0)
                {
                    cout << "\n\n\tPlease select one of the available parking lots: ";
                    cin >> choice;
                    for(auto lot: Available_Car_Lots)
                    {
                        if(choice == lot)
                        {
                            correct_choice = 1;
                        }
                    }
                    if(correct_choice == 0)
                    {
                        cout << "\n\n\tEnter a valid parking lot!";
                    }
                    if(correct_choice == 1)
                    {
                        int correct = 0;
                        bool valid_hours = false;
                        string hours;
                        while(correct != 1)
                        {
                            cout << "\n\n\tThe parking charges 3$ per hour at any time of the day.";
                            cout << "\n\n\tThe parking operates 24/7.";
                            cout << "\n\n\tPlease enter the number of hours you desire to use the parking lot for: ";
                            cin >> hours;
                            valid_hours = isFloat(hours);
                            if(valid_hours == true)
                            {
                                cost = std::stof(hours) * 3;
                                correct = 1;
                            }
                            else
                            {
                                cout << "\n\n\tPlease enter a valid number!";
                            }
                        }
                    }
                }
                system("cls");
                cout << "\n\n\tPlease enter the following details of your car";
                Vehicle V1;
                V1.set_vehicle_details();
                add_vehicle(choice, V1, username, cost);
                cout << "\n\n\tPlease place your car on the parking lot " << choice;
                cout << "\n\n\n\tThank you for using the parking!\n\n\t";
                choice = "1";
                break;
            }
        }
        else if(choice == "2")
        {
            char s = '2';
            char * str_ptr_2 = &s;
            int s_ = 0, correct_choice = 0;
            choice = "0";
            for(auto & elem: Available_Car_Lots)
            {
                if(elem[0] == *str_ptr_2)
                {
                    if(s_ == 0)
                    {
                        system("cls");
                        cout << "\n\n\t\t\t\t\t FREE 2nd FLOOR PARKING LOTS \n\n";
                        s_ = 1;
                    }
                    cout << "\t" << elem;
                }
            }
            if(s_ == 0)
            {
                choice = "0";
            }
            else if(s_ == 1)
            {
                while(correct_choice == 0)
                {
                    cout << "\n\n\tPlease select one of the available parking lots: ";
                    cin >> choice;
                    for(auto lot: Available_Car_Lots)
                    {
                        if(choice == lot)
                        {
                            correct_choice = 1;
                        }
                    }
                    if(correct_choice == 0)
                    {
                        cout << "\n\n\tEnter a valid parking lot!";
                    }
                    if(correct_choice == 1)
                    {
                        int correct = 0;
                        bool valid_hours = false;
                        string hours;
                        while(correct != 1)
                        {
                            cout << "\n\n\tThe parking charges 3$ per hour at any time of the day.";
                            cout << "\n\n\tThe parking operates 24/7.";
                            cout << "\n\n\tPlease enter the number of hours you desire to use the parking lot for: ";
                            cin >> hours;
                            valid_hours = isFloat(hours);
                            if(valid_hours == true)
                            {
                                cost = std::stof(hours) * 3;
                                correct = 1;
                            }
                            else
                            {
                                cout << "\n\n\tPlease enter a valid number!";
                            }
                        }
                    }
                }
                system("cls");
                cout << "\n\n\tPlease enter the following details of your car";
                Vehicle V1;
                V1.set_vehicle_details();
                add_vehicle(choice, V1, username, cost);
                cout << "\n\n\tPlease place your car on the parking lot " << choice;
                cout << "\n\n\n\tThank you for using the parking!\n\n\t";
                choice = "2";
                break;
            }
        }
        else if(choice == "5")
        {
            system("cls");
            exit(0);
        }
        else
        {
            cout << "\n\n\tWrong key. Try again!\n\n\t";
            system("pause");
            system("cls");
        }
    }

}

void Parking::use_parking_lot(string username)
{
    system("cls");
    string choice = "0";
    while(choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "5")
    {
        cout << "\n\n\tWhere would you like to park your vehicle?\n\n";
        cout << "\t|1.    1st Floor\n";
        cout << "\t|2.    2nd Floor\n";
        cout << "\t|3.    Ground Floor\n";
        cout << "\t|4.    Underground Floor\t\t\t";
        cout << "5.    Exit the parking\n";
        cout << "\n\tPlease enter your choice: ";
        cin >> choice;
        if(choice == "4")
        {
            char u = 'U';
            char * str_ptr_u = &u;
            int u_ = 0, correct_choice = 0;
            choice = "0";
            for(auto & elem: Available_Car_Lots)
            {
                if(elem[0] == *str_ptr_u)
                {
                    if(u_ == 0)
                    {
                        system("cls");
                        cout << "\n\n\t\t\t\t\t FREE UNDERGROUND FLOOR PARKING LOTS \n\n";
                        u_ = 1;
                    }
                    cout << "\t" << elem;
                }
            }
            if(u_ == 0)
            {
                choice = "0";
            }
            else if(u_ == 1)
            {
                while(correct_choice == 0)
                {
                    cout << "\n\n\tPlease select one of the available parking lots: ";
                    cin >> choice;
                    for(auto lot: Available_Car_Lots)
                    {
                        if(choice == lot)
                        {
                            correct_choice = 1;
                        }
                    }
                    if(correct_choice == 0)
                    {
                        cout << "\n\n\tEnter a valid parking lot!";
                    }
                }
                system("cls");
                cout << "\n\n\tPlease enter the following details of your car";
                Vehicle V1;
                V1.set_vehicle_details();
                add_vehicle(choice, V1, username);
                cout << "\n\n\tPlease place your car on the parking lot " << choice;
                cout << "\n\n\n\tThank you for using the parking!\n\n\t";
                choice = "4";
                break;
            }
        }
        else if(choice == "3")
        {
            char g = 'G';
            char * str_ptr_g = &g;
            int g_ = 0, correct_choice = 0;
            choice = "0";
            for(auto & elem: Available_Car_Lots)
            {
                if(elem[0] == *str_ptr_g)
                {
                    if(g_ == 0)
                    {
                        system("cls");
                        cout << "\n\n\t\t\t\t\t FREE GROUND FLOOR PARKING LOTS \n\n";
                        g_ = 1;
                    }
                    cout << "\t" << elem;
                }
            }
            if(g_ == 0)
            {
                choice = "0";
            }
            else if(g_ == 1)
            {
                while(correct_choice == 0)
                {
                    cout << "\n\n\tPlease select one of the available parking lots: ";
                    cin >> choice;
                    for(auto lot: Available_Car_Lots)
                    {
                        if(choice == lot)
                        {
                            correct_choice = 1;
                        }
                    }
                    if(correct_choice == 0)
                    {
                        cout << "\n\n\tEnter a valid parking lot!";
                    }
                }
                system("cls");
                cout << "\n\n\tPlease enter the following details of your car";
                Vehicle V1;
                V1.set_vehicle_details();
                add_vehicle(choice, V1, username);
                cout << "\n\n\tPlease place your car on the parking lot " << choice;
                cout << "\n\n\n\tThank you for using the parking!\n\n\t";
                choice = "3";
                break;
            }
        }
        else if(choice == "1")
        {
            char f = '1';
            char * str_ptr_1 = &f;
            int f_ = 0, correct_choice = 0;
            choice = "0";
            for(auto & elem: Available_Car_Lots)
            {
                if(elem[0] == *str_ptr_1)
                {
                    if(f_ == 0)
                    {
                        system("cls");
                        cout << "\n\n\t\t\t\t\t FREE 1st FLOOR PARKING LOTS \n\n";
                        f_ = 1;
                    }
                    cout << "\t" << elem;
                }
            }
            if(f_ == 0)
            {
                choice = "0";
            }
            else if(f_ == 1)
            {
                while(correct_choice == 0)
                {
                    cout << "\n\n\tPlease select one of the available parking lots: ";
                    cin >> choice;
                    for(auto lot: Available_Car_Lots)
                    {
                        if(choice == lot)
                        {
                            correct_choice = 1;
                        }
                    }
                    if(correct_choice == 0)
                    {
                        cout << "\n\n\tEnter a valid parking lot!";
                    }
                }
                system("cls");
                cout << "\n\n\tPlease enter the following details of your car";
                Vehicle V1;
                V1.set_vehicle_details();
                add_vehicle(choice, V1, username);
                cout << "\n\n\tPlease place your car on the parking lot " << choice;
                cout << "\n\n\n\tThank you for using the parking!\n\n\t";
                choice = "1";
                break;
            }
        }
        else if(choice == "2")
        {
            char s = '2';
            char * str_ptr_2 = &s;
            int s_ = 0, correct_choice = 0;
            choice = "0";
            for(auto & elem: Available_Car_Lots)
            {
                if(elem[0] == *str_ptr_2)
                {
                    if(s_ == 0)
                    {
                        system("cls");
                        cout << "\n\n\t\t\t\t\t FREE 2nd FLOOR PARKING LOTS \n\n";
                        s_ = 1;
                    }
                    cout << "\t" << elem;
                }
            }
            if(s_ == 0)
            {
                choice = "0";
            }
            else if(s_ == 1)
            {
                while(correct_choice == 0)
                {
                    cout << "\n\n\tPlease select one of the available parking lots: ";
                    cin >> choice;
                    for(auto lot: Available_Car_Lots)
                    {
                        if(choice == lot)
                        {
                            correct_choice = 1;
                        }
                    }
                    if(correct_choice == 0)
                    {
                        cout << "\n\n\tEnter a valid parking lot!";
                    }
                }
                system("cls");
                cout << "\n\n\tPlease enter the following details of your car";
                Vehicle V1;
                V1.set_vehicle_details();
                add_vehicle(choice, V1, username);
                cout << "\n\n\tPlease place your car on the parking lot " << choice;
                cout << "\n\n\n\tThank you for using the parking!\n\n\t";
                choice = "2";
                break;
            }
        }
        else if(choice == "5")
        {
            system("cls");
            exit(0);
        }
        else
        {
            cout << "\n\n\tWrong key. Try again!\n\n\t";
            system("pause");
            system("cls");
        }
    }
}

void Parking::add_vehicle(string parking_lot, Vehicle veh, string username)
{
    User_Lot_Map.insert(pair<string, string>(username, parking_lot));
    Lot_Veh_Map.insert(pair<string, Vehicle>(parking_lot, veh));
    //Lot_Cost_Map.insert(pair<string, float>(parking_lot, cost));
    Available_Car_Lots.remove(parking_lot);
    Used_Car_Lots.push_front(parking_lot);
    cout << "\t";
}

void Parking::add_vehicle(string parking_lot, Vehicle veh, string username, float Cost)
{
    User_Lot_Map.insert(pair<string, string>(username, parking_lot));
    Lot_Veh_Map.insert(pair<string, Vehicle>(parking_lot, veh));
    Lot_Cost_Map.insert(pair<string, float>(parking_lot, Cost));
    Available_Car_Lots.remove(parking_lot);
    Used_Car_Lots.push_front(parking_lot);
    cout << "\t";
}

void Parking::depart_vehicle_user(string username)
{
    int counts = 0, loop = 0;
    string choice;
    multimap<string, string>::iterator itr1;
    multimap<string, Vehicle>::iterator itr2;
    multimap<string, float>::iterator itr3;
    typedef multimap<string,string>::iterator iter_pair1;
    //cout << "\n\n\t" << username << "'s vehicles in the parking: ";
    if(User_Lot_Map.size() >= 1)
    {
        for(itr1 = User_Lot_Map.begin(); itr1 != User_Lot_Map.end(); itr1++)
        {
            if(username == itr1->first)
            {
                if(Lot_Veh_Map.size() >= 1)
                {
                    for(itr2 = Lot_Veh_Map.begin(); itr2 != Lot_Veh_Map.end(); itr2++)
                    {
                        for(itr3 = Lot_Cost_Map.begin(); itr3 != Lot_Cost_Map.end(); itr3++)
                        {
                            if(itr1->second == itr2->first && itr1->second == itr3->first)
                            {
                                cout << "\n\n\t"<< counts + 1 << ". " << itr1->first << " | " << itr1->second
                                    << " | $" << itr3 -> second
                                        << " | " << itr2 -> second.get_vehicle_brand() << " | " << itr2 -> second.get_vehicle_type()
                                            << " | " << itr2 -> second.get_licence_plate();
                                counts++;
                                while(loop != 1)
                                {
                                    cout << "\n\n\tDo you wish to depart the vehicle above? Please enter [Y/N]: ";
                                    cin >> choice;
                                    if(choice == "y" || choice == "yes" || choice == "YES" || choice == "Yes" || choice == "Y" || choice == "1")
                                    {
                                        cout << "\n\n\tThe total cost is: $" << itr3->second;
                                        cout << "\n\n\tPlease pay off the amount to get the departure card!\n\n\t";
                                        system("pause");
                                        Available_Car_Lots.push_front(itr1->second);
                                        Used_Car_Lots.remove(itr1->second);
                                        Lot_Veh_Map.erase(itr2->first);
                                        Lot_Cost_Map.erase(itr3->first);
                                        pair<iter_pair1, iter_pair1> iterpair = User_Lot_Map.equal_range(username);
                                        iter_pair1 it = iterpair.first;
                                        for (; it != iterpair.second; ++it)
                                        {
                                            if (it->second == itr1->second)
                                            {
                                                User_Lot_Map.erase(it);
                                                break;
                                            }
                                        }
                                        // User_Lot_Map.erase(itr1->first);
                                        cout << "\n\n\tYou can now depart your vehicle!\n\n\t";
                                        return;
                                    }
                                    else if(choice == "n" || choice == "no" || choice == "NO" || choice == "No" || choice == "N" || choice == "0")
                                    {
                                        loop = 1;
                                        system("cls");
                                    }
                                    else
                                    {
                                        cout << "\n\n\tPlease enter 'Y' or 'N'\n\n\t";
                                        system("pause");
                                        system("cls");
                                    }
                                }
                                loop = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    if(counts == 0)
    {
        cout << "\n\n\tYou have no vehicles parked in the parking!";
    }
}

void Parking::depart_vehicle(string username)
{
    int counts = 0, loop = 0;
    string choice;
    multimap<string, string>::iterator itr1;
    multimap<string, Vehicle>::iterator itr2;
    //multimap<string, float>::iterator itr3;
    typedef multimap<string,string>::iterator iter_pair1;
    //cout << "\n\n\t" << username << "'s vehicles in the parking: ";
    if(User_Lot_Map.size() >= 1)
    {
        for(itr1 = User_Lot_Map.begin(); itr1 != User_Lot_Map.end(); itr1++)
        {
            if(username == itr1->first)
            {
                if(Lot_Veh_Map.size() >= 1)
                {
                    for(itr2 = Lot_Veh_Map.begin(); itr2 != Lot_Veh_Map.end(); itr2++)
                    {
                            if(itr1->second == itr2->first)
                            {
                                cout << "\n\n\t"<< counts + 1 << ". " << itr1->first << " | " << itr1->second
                                        << " | " << itr2 -> second.get_vehicle_brand() << " | " << itr2 -> second.get_vehicle_type()
                                            << " | " << itr2 -> second.get_licence_plate();
                                counts++;
                                while(loop != 1)
                                {
                                    cout << "\n\n\tDo you wish to depart the vehicle above? Please enter [Y/N]: ";
                                    cin >> choice;
                                    if(choice == "y" || choice == "yes" || choice == "YES" || choice == "Yes" || choice == "Y" || choice == "1")
                                    {
                                        Available_Car_Lots.push_front(itr1->second);
                                        Used_Car_Lots.remove(itr1->second);
                                        Lot_Veh_Map.erase(itr2->first);
                                        pair<iter_pair1, iter_pair1> iterpair = User_Lot_Map.equal_range(username);
                                        iter_pair1 it = iterpair.first;
                                        for (; it != iterpair.second; ++it)
                                        {
                                            if (it->second == itr1->second)
                                            {
                                                User_Lot_Map.erase(it);
                                                break;
                                            }
                                        }
                                        // User_Lot_Map.erase(itr1->first);
                                        cout << "\n\n\tYou can depart your vehicle!\n\n\t";
                                        return;
                                    }
                                    else if(choice == "n" || choice == "no" || choice == "NO" || choice == "No" || choice == "N" || choice == "0")
                                    {
                                        loop = 1;
                                        system("cls");
                                    }
                                    else
                                    {
                                        cout << "\n\n\tPlease enter 'Y' or 'N'\n\n\t";
                                        system("pause");
                                        system("cls");
                                    }
                                }
                                loop = 0;
                            }
                    }
                }
            }
        }
    }
    if(counts == 0)
    {
        cout << "\n\n\tYou have no vehicles parked in the parking!";
    }
}
