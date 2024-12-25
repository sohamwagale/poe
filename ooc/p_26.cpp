#include <iostream>
using namespace std;

class Complex{
    public:
        int real, imag;

        Complex(){
            this->real = 0;
            this->imag = 0;
        }

        friend ostream & operator <<(ostream &out, Complex &obj);
        friend istream & operator >>(istream &in, Complex &obj);
};

ostream & operator <<(ostream &out, Complex &obj){
    out<<obj.real;
    out<<"+i"<<obj.imag<<endl;
    return out;
}

istream & operator >>(istream &in, Complex &obj){
    cout<<"Enter real no: ";
    in>>obj.real;

    cout<<"\nEnter imag no:";
    in>>obj.imag;

    return in;
}

int main(void){
    Complex c;
    cin>>c;
    cout<<c;
    return 0;
}