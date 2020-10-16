#ifndef Lane_h
#define Lane_h

#include <vector>
#include "Vehicle.h"


using namespace std;

enum direction{right, left};
enum type{truck, fast, slow};

class Lane {
    public:
        Lane();
        void change_lane(direction drt);
        void new_vehicle(type vhc); //TODO: hier moet mischien nog een locatie aan worden toegevoegd zodat afslagen erbij kunnen komen
        void remove_vehicle(Vehicle *vhc);
        void print_lane(); //TODO: dit laat zien de id van de vehicle en dan de afstand naar de andere id's, ongeveer.

    private:
        vector<Vehicle> vehicles; //TODO: dit moet een container worden gelinked aan de distances tussen vehicles
        vector<long int> distance;
        
};

#endif