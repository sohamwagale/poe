#include <iostream>
using namespace std;

class No{
    public:
        int value;

        No(){
            this->value = 0;
        }

        No(int v): value(v) {}

        bool operator >(No &obj)const{
            return(value > obj.value);
        }

        bool operator <(No &obj)const{
            return(value < obj.value);
        }

        bool operator ==(No &obj)const{
            return(value == obj.value);
        }
};

int main(void){
    No n(10);
    No s(20);

    if(n > s){
        cout<<"n is grater than s"<<endl;
    }else if(n < s){
        cout<<"n is less than s"<<endl;
    }else{
        cout<<"n is equal to s"<<endl;
    }

    return 0;
}