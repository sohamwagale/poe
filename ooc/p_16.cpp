/*
  Implement a program to create a student class from which derive test class and
     from test class derive result class.

 */

#include <iostream>
using namespace std;

class Student{
	protected:
		string name;
		int roll_no;
	public:
		Student(string n, int r):name(n), roll_no(r) {}

		void show_info(void){
			cout<<"Name of the student is : "<<name<<endl;
			cout<<"roll no : "<<roll_no<<endl;
		}
};

class Test :public Student{
	protected:
		int test_1_marks;
		int test_2_marks;
		int test_3_marks;
		int test_4_marks;
		int test_5_marks;

	public:
    Test(string n, int r):Student(n, r) {}
		void fill_marks(void){
			cout<<"Please Enter the marks for Test 1: ";
			cin>>test_1_marks;
			cout<<endl;
			
			cout<<"Please enter the marks for Test 2: ";
			cin>>test_2_marks;
			cout<<endl;

			cout<<"Please enter the marks for Test 3: ";
			cin>>test_3_marks;
			cout<<endl;

			cout<<"Please enter the marks for Test 4: ";
			cin>>test_4_marks;
			cout<<endl;

			cout<<"Please enter the marks for Test 5: ";
			cin>>test_5_marks;
			cout<<endl;

		}

		int calculate_result(void){
			int result;
			result = (test_1_marks + test_2_marks + test_3_marks + test_4_marks + test_5_marks) / 5;
			return result;
		}
};

class Result: public Test{
	public:
		Result(string n, int r):Test(n, r) {}
		
		void show_result(void){
			cout<<"The result of the Student is : "<<Test::calculate_result()<<endl;
		}

};

int main(void){
	Result re("xyz", 5);
	re.show_info();
	re.fill_marks();
	re.calculate_result();
	re.show_result();

	return 0;
}
