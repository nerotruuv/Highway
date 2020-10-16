#ifndef Vehilcle_h
#define Vehilcle_h



using namespace std;

class Vehicle {

    public:
        void set_values(int accel, int brake, int lenght);
        void accelerate();
        void brake();

    protected:
        int id;
        int lenght;
        int max_accel;
        int max_brake;
        float velocity;

};

#endif