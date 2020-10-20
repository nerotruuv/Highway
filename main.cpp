#include <iostream>
#include "include/lane.h"

using namespace std;

int main(){ 
    
    Lane uno;
    for( int i = 0; i < 5; i++ ){
        
        if(i % 2 == 0){
            uno.new_vehicle(fast);
        }else{
            uno.new_vehicle(slow);
        }        
        //uno.print_lane();
        uno.move(); 
    }

    for(int j = 0; j < 10; j++){
        uno.print_lane();
        uno.move();
    }
    
    return 0;
}