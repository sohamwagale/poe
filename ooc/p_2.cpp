#include <iostream>
using namespace std;

int main(void){
	int i = 1;
	int n = 0;

	cout<<"Please Enter N:";
	cin>>n;

	do{
		cout<<i<<endl;
		++i;
	}while(i <= n);

	return 0;
}
