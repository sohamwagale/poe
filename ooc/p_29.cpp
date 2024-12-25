#include <iostream>
#include <exception>
using namespace std;

class MyException:public exception{
    public:
        const char* what() const throw(){
           return "ZeroDivision Error !\n";
        }
        
};

int main(void){
    try{
        int x,y;
        cout<<"Enter the two numbers: ";
        cin >>x>>y;

        if(y == 0){
            MyException z;
            throw z;
        }
        else{
            cout<<"ANS: "<<x/y<<endl;
            return 0;
        }
    }

    catch(exception &e){
        cout<<e.what();
    }

    return 0;
}