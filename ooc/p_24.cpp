#include <iostream>
using namespace std;

class Mesurement{
    public:
        int feet;
        int inch;

        Mesurement(int f, int i): feet(f), inch(i) {}
        Mesurement(){
            this->feet = 0;
            this->inch = 0;
        }

        Mesurement operator +(Mesurement &obj){
            Mesurement m3;
            m3.feet = this->feet + obj.feet;
            m3.inch = this->inch + obj.inch;
            return m3;
        }


};

int main(void){
    Mesurement m1(10,10);
    Mesurement m2(20,20);
    Mesurement m3;

    m3 = m1 + m2;
    cout<<"Feet: "<<m3.feet<<endl;
    cout<<"Inch: "<<m3.inch<<endl;

    return 0;
}