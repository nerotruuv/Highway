#ifndef vehilcle_h
#define vehilcle_h



using namespace std;

class Vehicle { 

    static int new_id;

    public:
        Vehicle(int accel, int brake, int lenght) : max_accel(accel), max_brake(brake), lenght(lenght), id(new_id++), velocity(0), crashed(false){}//TODO: tijdelijke constructor
        //void set_values(int accel, int brake, int lenght);    //TODO: uncoomment wanneer childs aangemaakt zijn             
        void accelerate();
        void decelerate(int distance);
        void crash();

        /*Getters en Setters*/
        bool get_crashed();
        int get_id();
        int get_lenght();
        int get_max_accel();
        int get_max_brake();
        float get_velocity();

    protected:
        bool crashed;
        int id;
        int lenght;
        int max_accel;
        int max_brake;
        float velocity;

};

#endif