#ifndef lane_h
#define lane_h

#include <deque>
#include <iostream>
#include "vehicle.h"



using namespace std;

enum direction{right, left};
enum type{truck, fast, slow};

struct location
{
    Vehicle *vhc;
    long int distance;
};


class Lane {
    public:
        Lane();
        void change_lane(direction drt);
        void new_vehicle(type vhc); //TODO: hier moet mischien nog een locatie aan worden toegevoegd zodat afslagen erbij kunnen komen
        void remove_vehicle(Vehicle *vhc);
        void print_lane();          //TODO: dit laat zien de id van de vehicle en dan de afstand naar de andere id's, ongeveer.

    private:
        deque<location> vehicles;   //TODO: dit moet een deque worden
        
};

#endif