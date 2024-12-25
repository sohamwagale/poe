#include <iostream>
using namespace std;

int main(void){
	int number;
	unsigned long long factorial = 1;

	cout<<"Enter a positive Integer: ";
	cin>>number;

	if(number < 0)
		cout<<"Factorial of a negative number doesn't exist."<<endl;
	else{
		for(int i = 1; i <= number; ++i)
			factorial *= i ;
	
		cout<<"Factoial of "<<number<<" = "<<factorial<<endl;
	}

	return 0;
}


