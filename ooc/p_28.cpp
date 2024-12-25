#include <iostream>
using namespace std;

int main(void){
    try{
        int a = 50;
        int b = 0;
        
        if(b == 0)
            throw("Zero Division Error");
        else{
            cout<<"Ans: "<<a/b<<endl;
            return 0;
        }
    }

    catch(const char* msg){
        cout<<"Error: "<<msg<<endl;
    }

    return 0;
}