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

/* Parking Class Declaration */
class Parking
{
private:
    // Number of Parking Floors
    int parking_floors = 4;

    // Names of Parking Floors
    string floor_1 = "Underground Floor", floor_2 = "Ground Floor", floor_3 = "1st Floor", floor_4 = "2nd Floor";
    int floor_no_1 = -1, floor_num_2 = 0, floor_num_3 = 1, floor_num_4 = 2;

    // Maximum number of vehicles that can fit in any given floor
    int max_floor_capacity = 50;

    /// Every Parking Floor will have 5 areas, each one able to contain 10 cars maximum ///
    int max_area_capacity = 10;
    int no_of_areas_of_any_floor = 5;

    // Vectors containing details about floors and floor areas
    list<string> Area_Names = {"A", "B", "C", "D", "E"};
    list<string> Floors = {floor_1,floor_2,floor_3, floor_4};

public:
    // Vector, in which all the parking lot names will be contained
    list<string> All_Car_Lots;
    list<string> Available_Car_Lots;
    list<string> Used_Car_Lots;

    // A map container that will connect added car lots with the Vehicle they contain
    multimap<string, Vehicle> Lot_Veh_Map;

    // A map container that will connect users with their parking lots
    multimap<string, string> User_Lot_Map;

    // A map container that will connect parking lots with the total cost of them.
    multimap<string, float> Lot_Cost_Map;

    // Parking Class Member Functions
    void create_parking_lots();
    void display_all_parking_lots();
    void display_free_parking_lots();
    void display_used_parking_lots();
    void display_your_parking_lots(string username);
    float reserve_parking_lot(string username);
    void use_parking_lot(string username);
    void add_vehicle(string parking_lot, Vehicle veh, string username);
    void add_vehicle(string parking_lot, Vehicle veh, string username, float Cost);
    void depart_vehicle(string username);
    void depart_vehicle_user(string username);
};
