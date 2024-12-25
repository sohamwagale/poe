#include <iostream>
using namespace std;

int main(void){
	int number;

	cout<<"Please Enter The number:";
	cin>>number;

	if(number > 0 )
		cout<<"You entered a positive number"<<endl;
	else if(number < 0)
		cout<<"You enterd a negative number"<<endl;
	else
		cout<<"You enterd a zero"<<endl;

	return 0;
}
