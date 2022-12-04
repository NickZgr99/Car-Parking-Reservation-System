#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <list>

using namespace std;

class Vehicle
{
private:
    // Vehicle Details
    string vehicle_brand, licence_plate, vehicle_type;
public:
    // Vehicle Class Member Functions
    Vehicle(){}
    Vehicle(string vb, string lp, string vt);
    void set_vehicle_details();
    string get_vehicle_brand();
    string get_licence_plate();
    string get_vehicle_type();
    void display_vehicle_details();
};
