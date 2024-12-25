#include <iostream>
#include <cstdlib>
using namespace std;

void fibonacci_print(int n);

int main(void){
	int n;
	cout<<"Enter the number of Fibonacci numbers to print:";
	cin>>n;
	fibonacci_print(n);

	return 0;
}

void fibonacci_print(int n){
	long long first = 0, second = 1;
	long next;

	if(n <= 0){
		cout<<"Please Enter the Positive number."<<endl;
		exit(EXIT_FAILURE);
	}

	cout<<"Fibonacci Sequence: ";
	for(int i = 0; i < n; ++i){
		cout<<first<<" ";
		next = second + first;
		first = second;
		second  = next;
	}

	cout<<endl;

}