#include <iostream>
using namespace std;

class Measure{
    private:
        int feet,inch;
    public:
        Measure(int f, int i):feet(f), inch(i) {}

        void operator -(){
            feet--;
            inch--;
        }

        void decrement(){
            cout<<"feet: "<<feet<<endl;
            cout<<"inch: "<<inch<<endl;
        }

};

int main(void){
    Measure m(20,20);
    -m;
    m.decrement();
    return 0;
}
