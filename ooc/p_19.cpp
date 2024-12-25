/*
Multiple Inheritance -> - Problem Statement: Create a program to model a
"FlyingCar" class that inherits attributes (wingspan, fuelCapacity) and methods
(fly, drive) from both "Car" and "Airplane" base classes.
*/

#include <iostream>
using namespace std;

class Car{
    protected:
        double fuel_capacity;
        double max_speed;
    
    public:
        Car(double f, double m): fuel_capacity(f), max_speed(m) {}

        void car_details(void){
            cout<<"Fuel capacity of the car: "<<fuel_capacity<<endl;
            cout<<"Max speed of the car is"<<max_speed<<endl;
        }

        void drive(void){
            cout<<"The car is driving at speed of "<<max_speed<<" km/h"<<endl;
        }


};

class Airplane{
    protected:
        double wings_span;
        double max_altitue;

    public:
        Airplane(double w, double m): wings_span(w), max_altitue(m) {}

        void fly(void){
            cout<<"The Plane is flying on altitude "<<max_altitue<<endl;
        }

        void plane_details(void){
            cout<<" Wings span of the plane: "<<wings_span<<endl;
            cout<<"Maximum altitude of the plane: "<<max_altitue<<endl;
        }


};

class FlyingCar: public Car, public Airplane{
    protected:
        string model_name;

    public:
        FlyingCar(string model, double fuel, double speed, double wing, double altitude):model_name(model),
        Car(fuel,speed), Airplane(wing, altitude) {}

        void show_details(void){
            cout<<"FlyingCar details"<<endl;
            cout<<"Model Name: "<<model_name<<endl;
            car_details();
            plane_details();
            cout<<"---------------------------------------------"<<endl;
        }

        void operate(void){
            cout<<"Operating as a FLYING CAR"<<endl;
            drive();
            fly();
        }
};

int main(void){
    FlyingCar fc("wz32", 500, 450, 7, 7000);
    fc.show_details();
    fc.operate();
    return 0;
}
