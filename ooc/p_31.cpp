#include <iostream>
using namespace std;

class Rectangle{
	public:
		int length;
		int breadth;

		int area(void){
			return(length * breadth);
		}

		int perimeter(void){
			return(2 * (length + breadth));
		}

};

int main(void){
	Rectangle* rect = NULL;

	rect = new Rectangle;
	rect->length = 10;
	rect->breadth = 10;

	cout<<"Length : "<<rect->length<<" breadth: "<<rect->breadth<<" of the Rectangle "<<endl;
	cout<<"Area of the Rectangle is : "<<rect->area()<<endl;
	cout<<"Perimeter of the Rectangle is : "<<rect->perimeter()<<endl;
	
	delete rect;
	return 0;
}
