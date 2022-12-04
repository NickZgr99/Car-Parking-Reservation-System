#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <list>

#include "Vehicle.h"

using namespace std;

/* Vehicle Class Constructor */
Vehicle::Vehicle(string vb, string lp, string vt)
{
    vehicle_brand = vb;
    licence_plate = lp;
    vehicle_type = vt;
}

/* Vehicle Class Member Functions */
void Vehicle::set_vehicle_details()
{
    cout << "\n\n\t|1. Vehicle's brand: ";
    cin >> vehicle_brand;
    cout << "\n\t|2. License plate: ";
    cin >> licence_plate;
    cout << "\n\t|3. Vehicle's type: ";
    cin >> vehicle_type;
}

string Vehicle::get_licence_plate()
{
    return licence_plate;
}

string Vehicle::get_vehicle_brand()
{
    return vehicle_brand;
}

string Vehicle::get_vehicle_type()
{
    return vehicle_type;
}

void Vehicle::display_vehicle_details()
{
    system("cls");
    cout << "\n\t\t CAR DETAILS\n\n";
    cout << "==== Vehicle Brand: \t" << vehicle_brand << endl;
    cout << "==== License Plate: \t" << licence_plate << endl;
    cout << "==== Vehicle Type: \t" << vehicle_type << endl;
}
