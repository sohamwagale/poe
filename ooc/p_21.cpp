
#include <iostream>
using namespace std;

class Vehicle{
   protected:
        string colour;
        int wheels;
        string engine;

    public:
        void accelerate(void){
            cout<<"The Vehicle is Accelarated"<<endl;
        }

        void brake(void){
            cout<<"The brake is applied to Vehicle"<<endl;
        }

        void show_info(void){
            cout<<"Colour = "<<colour<<endl;
            cout<<"No of Wheels = "<<wheels<<endl;
            cout<<"engine type = "<<engine<<endl;
        }

};

class Car: public Vehicle{
   public:
        Car(string c_name, int wh_no, string e_type){
            colour = c_name;
            wheels = wh_no;
            engine = e_type;
        }

};

class Truck: public Vehicle{
      public:
        Truck(string c_name, int wh_no, string e_type){
            colour = c_name;
            wheels = wh_no;
            engine = e_type;
        }
};

class Motorcycle: public Vehicle{
      public:
        Motorcycle(string c_name, int wh_no, string e_type){
            colour = c_name;
            wheels = wh_no;
            engine = e_type;
        }
};

int main(void){
    Car cr("red", 4, "petrol");
 
    cout<<"CAR INFO"<<endl;
    cr.show_info();
    cr.accelerate();
    cr.brake();
    cout<<"-------------------"<<endl;
    
    Truck tr("Brown", 10, "disel");
    cout<<"TRUCK INFO"<<endl;
    tr.show_info();
    tr.accelerate();
    tr.brake();
    cout<<"-------------------"<<endl;

    Motorcycle mt("black", 2, "petrol");
    cout<<"MOTORCYCLE INFO"<<endl;
    mt.show_info();
    mt.accelerate();
    mt.brake();
    cout<<"-------------------"<<endl;

    return 0;

}