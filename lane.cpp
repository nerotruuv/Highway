#include "include/lane.h"

Lane::Lane(){

}

void Lane::change_lane(direction drt){

}

void Lane::new_vehicle(type vhc){
    switch(vhc){
        case fast: vehicles.push_front(location{new Vehicle(50,50,5), 0});
            break;
        default:
            cout << "Der is iets onmogelijks gebeurt"<< endl;
    }
}

void Lane::remove_vehicle(Vehicle *vhc){

}

void Lane::print_lane(){
    for(int i = vehicles.size(); i > 0; i--){
        cout << vehicles[i].distance << " | " << vehicles[i].vhc->get_id();
    }
}