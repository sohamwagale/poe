#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    ofstream fout;
    ifstream fin;
    string line;

    fout.open("example.txt");
    while(fout){
        getline(cin, line);
        if(line == "-1")
            break;

        fout<<line<<endl;
    }
    fout.close();

    fin.open("example.txt");
    while(getline(fin,line)){
        cout<<line<<endl;
    }
    fin.close();
    return 0;
}