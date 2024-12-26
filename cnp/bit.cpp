#include<bits/stdc++.h>
using namespace std;

int main(){
    string data;
    cin>> data;
    int cnt =0;
    vector<int> stfdata;
    for(auto bit : data){
        if(bit=='1'){
            stfdata.push_back(bit);
            cnt++;
        }
        else{
            stfdata.push_back(bit);
        }
        if(cnt == 5){
            stfdata.push_back('0');
            cnt=0;
        }
    }
    cout<<endl;
    for(auto bit: stfdata){
        cout<<(char)bit;
    }
}