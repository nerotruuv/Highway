#include "include/lane.h"

Lane::Lane(){

}

void Lane::change_lane(direction drt){

}

/**
 * deze shit werkt niet bij de eerste auto, omdat deze geen auto voor zich heeft 
 * 
 * 
 */

void Lane::new_vehicle(type vhc){
    switch(vhc){
        case fast:  vhc_location.push_front(location{.vhc = new Vehicle(100,30,5), 0, 0});                                     
            break;
        case slow:  vhc_location.push_front(location{.vhc = new Vehicle(80,30,5), 0, 0});                                        
            break;
        case truck: vhc_location.push_front(location{.vhc = new Vehicle(75,30,15), 0, 0});                                      
            break;
        default:
            cout << "Der is iets onmogelijks gebeurt"<< endl;
    }
    if(vhc_location.size() != 1){
        vhc_location.front().distance_between = vhc_location[1].distance_total;
    } 
    
}
/**
 * hiermee kunnen vehicles worden verweiderd die te ver vooruit lopen, 
 * omdat deze toch niets meer kunne veroorzaken
 */
void Lane::remove_vehicle(Vehicle *vhc){

}

/**
 * distance_total += velocity
 * distance between wordt berekent nadat er 2 vehicles hun totaal distance geupdate hebben
 * ligt aan de afstand naar de auto ervoor: accelerate();
 */
void Lane::move(){
    for(int i = (vhc_location.size() - 1); i >= 0; i--){

        // hier moet bij als het de eerste index is (0)
        if(vhc_location[i].distance_between < 0){
            //cout << "crsh:" << vhc_location[i].vhc->get_id();
            vhc_location[i].vhc->crash();

        }else if(vhc_location[i].distance_between > 20 ||  vhc_location.back().vhc->get_id() == vhc_location[i].vhc->get_id()){
            vhc_location[i].vhc->accelerate(); 

        }else if(vhc_location[i].distance_between < 20){
            vhc_location[i].vhc->decelerate(vhc_location[i].distance_between);
        }
              
        vhc_location[i].distance_total += vhc_location[i].vhc->get_velocity();

        if(i < vhc_location.size() - 2 && vhc_location.back().vhc->get_id() != vhc_location[i].vhc->get_id()){
            vhc_location[i].distance_between = calc_between(vhc_location[i], vhc_location[i+1]);
        }
    }
}

long int Lane::calc_between(location vhc_back, location vhc_front){
    return vhc_front.distance_total - vhc_back.distance_total;
}

/**
 * print lane print van voren naar achter om een echte "lane" voor te stellen, 
 * met een vehicle en dan de afstand tussen vehicles. 
 */
void Lane::print_lane(){
    cout.precision(3);

    for(int i = 0; i < vhc_location.size(); i++){    
        cout << " \t| " << vhc_location[i].distance_between << " \tV:" << vhc_location[i].vhc->get_velocity();
    }

    cout << endl;

    for(int i = 0; i < vhc_location.size(); i++){    
        cout << " \t| " << vhc_location[i].distance_total << " \tID:" << vhc_location[i].vhc->get_id();
    }
    
    cout << endl;

    for(int i = 0; i < vhc_location.size(); i++){
        cout << " - - - - - - - - -";
    }

    cout << endl;
}