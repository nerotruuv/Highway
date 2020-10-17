#include "include/vehicle.h"

int Vehicle::new_id = 0;

void Vehicle::accelerate(){

}

void Vehicle::brake(){
    
}

/*getters en Setters*/

int Vehicle::get_id(){
    return id;
}

int Vehicle::get_lenght(){
    return lenght;
}

int Vehicle::get_max_accel(){
    return max_accel;
}

int Vehicle::get_max_brake(){
    return max_brake;
}

float Vehicle::get_velocity(){
    return velocity;
}