#include "include/vehicle.h"

int Vehicle::new_id = 1;


/**
 * huidige velocity + half distance naar top velocity
 * voor het exponentieele
 */
void Vehicle::accelerate(){
    if(crashed == false){
        if(velocity <= max_accel){
            velocity += ((max_accel - velocity) / 2);
        }
    }
}
/**
 *  hoe dichterbij het is, hoe harder hij moet remmen, 
 *  maar hij heeft een maximale snelheid dat het kan remmen
 *  ((-0.04 * distance) + 0.94)) deze formule is gebaseert op dat remvermogen ongeveer 50% is bij een afstand van 10 meter en 90% bij 1 meter
 */
void Vehicle::decelerate(int distance){
    if(crashed == false){
        float temp = (max_brake * ((-0.05 * distance) + 1));
        
        if(temp >= 0 && (velocity - temp) > 0){
            velocity -= temp;
        }else{
             velocity = 0;
        }
        
    }   
}

void Vehicle::crash(){
    crashed = true;
    velocity = 0;
}

/*getters en Setters*/

bool Vehicle::get_crashed(){
    return crashed;
}

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