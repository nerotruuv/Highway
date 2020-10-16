#ifndef vehilcle_h
#define vehilcle_h



using namespace std;

class Vehicle {

    public:
        Vehicle(int accel, int brake, int lenght) : max_accel(accel), max_brake(brake), lenght(lenght) {}              //TODO: tijdelijke constructor
        //void set_values(int accel, int brake, int lenght);    //TODO: uncoomment wanneer childs aangemaakt zijn
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