#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    cout<<"Enter the address";
    cin>>a>>b>>c>>d;
    if(a>=1 && a<=127){
        cout<<"Class A"<<" Net ID:"<<a<<".0.0.0"<<"";
    }
    cout<<a<<b<<c<<d;
}