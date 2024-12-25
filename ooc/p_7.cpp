#include <iostream>
using namespace std;

#define N 	9

int main(void){
	int arr[N] = {1,2,3,4,5,6,7,8,9};
	int i;

	cout<<"The array "<<endl;
	for(i = 0; i < N; ++i)
			cout<<"arr["<<i<<"]:"<<arr[i]<<endl;

	cout<<"Elements at even index:"<<endl;
	for(i = 0; i < N; ++i)
		if(i % 2 == 0)
			cout<<"arr["<<i<<"]:"<<arr[i]<<endl;
		
	cout<<"Elements at odd index:"<<endl;
	for(i = 0; i < N; ++i)
		if(!(i % 2 == 0))
			cout<<"arr["<<i<<"]:"<<arr[i]<<endl;

	return 0;
	

}
		
