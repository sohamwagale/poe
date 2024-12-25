#include <iostream>
using namespace std;

int main(void){
	
	string s = "The statement";
	int n = 0;
	int i;

	cout<<"Please Enter the N: ";
	cin>>n;
	
	i = 0;
	while(i < n){
		cout<<s<<endl;
		++i;
	}

	return 0;
}

