/*
p_11 -> Shape Inheritance: Create a program to model various shapes (Circle, Rectangle,
        Triangle) that inherit properties (area, perimeter) and methods (calculateArea,
        calculatePerimeter) from a base Shape class
*/
#include <iostream>
#include <cmath>
using namespace std;

#define PI	3.14

class Shape{
	public:
		virtual void calculateArea() = 0;
		virtual void calculatePerimeter() = 0;
};

class Circle: public Shape{
	private:
		double radius;

	public:
		Circle(double r) : radius(r){}

		void calculateArea() override{
			double area = PI * radius * radius;
			cout<<"Circle Area: "<<area<<endl;
		}

		void calculatePerimeter()override{
			double perimeter = 2 * PI * radius;
			cout<<"Circle Perimeter: "<<perimeter<<endl;
		}


};

class Rectangle: public Shape{
	private:
		double length, width;

	public:
		Rectangle(double len, double wid):length(len), width(wid){}

		void calculateArea()override{
			double area = length * width;
			cout<<"Rectangle Area: "<<area<<endl;
		}

		void calculatePerimeter()override{
			double perimeter = 2*(length + width);
			cout<<"Perimeter of Rectangle: "<<perimeter<<endl;
		}


};

class Triangle: public Shape{
	private:
		double side1, side2, side3;

	public:
		Triangle(double s1, double s2, double s3):side1(s1), side2(s2), side3(s3){}

		void calculateArea(void) override{
			double s = (side1 + side2 + side3) / 2;
			double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
			cout<<"Triangle Area: "<<area<<endl;
		}

		void calculatePerimeter(void)override{
			double perimeter = side1 + side2 + side3;
			cout<<"Triangle Perimeter : "<<perimeter<<endl;
		}

};


int main(void){
	Circle cl(5.0);
	cout<<"Cicle:"<<endl;
	cl.calculateArea();
	cl.calculatePerimeter();
	cout<<"------------------------"<<endl;

	Rectangle rect(4, 6);
	cout<<"Rectangle:"<<endl;
	rect.calculateArea();
	rect.calculatePerimeter();
	cout<<"--------------------------"<<endl;

	Triangle tr(3,4,5);
	cout<<"Triangle:"<<endl;
	tr.calculateArea();
	tr.calculatePerimeter();

	return 0;
	
}