#include <iostream>
using namespace std;

int area(int side);
int area(int len, int bre);
float area(float base, float height);
float area(float r);

int main(void){
	int s,l, b;
	float bs, he, r;

	cout<<"Enter the SIDE of the square: ";
	cin>>s;
	cout<<"Area of the square is : "<<area(s)<<endl;

	cout<<"Enter the length and breadth of Recatangle: ";
	cin>>l>>b;
	cout<<"Area of the Rectangle: "<<area(l,b)<<endl;

	cout<<"Enter the Base and Height of the Triangle: ";
	cin>>bs>>he;
	cout<<"Area of the Triangle: "<<area(bs,he)<<endl;

	cout<<"Enter the Radius of the Circle: ";
	cin>>r;
	cout<<"Area of the Circle: "<<area(r)<<endl;

	return 0;
}


int area(int side){
	return(side * side);
}

int area(int len, int bre){
	return(len * bre);
}

float area(float base, float height){
	return((base * height)/2);
}

float area(float r){
	return(3.14 * r * r);
}


