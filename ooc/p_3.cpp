#include <iostream>
#include <cstdlib>
using namespace std;

int main(void){
	int age = 0;

	cout<<"Please Enter the age:";
	cin>>age;

	if(age < 0 ){
		cout<<"Please Enter the Valid Age"<<endl;
		exit(EXIT_FAILURE);
	}


	if(age >= 18)
		cout<<"He/She can drive  vehicle"<<endl;
	else
		cout<<"He/She can't dive vehicle"<<endl;

	return(0);
}
