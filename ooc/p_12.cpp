/*
p_12 -> Employee Management: Develop a system to manage different types of employees
        (Full-time, Part-time, Contractor) who inherit common attributes (name, ID,
        department) and methods (calculateSalary, displayInfo) from a base Employee
        class.
*/
#include <iostream>
using namespace std;

class Employee{
	protected:
		string name;
		int id;
		string department;
	public:
		void display_info(void){
			cout<<"Name of the employee: "<<name<<endl;
			cout<<"ID of the Employee: "<<id<<endl;
			cout<<"Department of the Employee: "<<department<<endl;
		}

		virtual void calculate_salary(void) = 0;
};

class FullTime:public Employee{
      	protected:
		const double hours_wage = 200; 
		double work_hour;
		double salary;
	public:
		FullTime(string n, int i, string dep, double w) {
			name = n;
			id = i;
			department = dep;
			work_hour = w;
		}
		void calculate_salary(void) override{
			salary = hours_wage * work_hour;
			cout<<"The salary of the Fulltime Employee is : "<<salary<<endl;
		}
};


class PartTime:public Employee{
	protected:
		const double hours_wage = 100; 
		double work_hour;
		double salary;
	public:
		PartTime(string n, int i, string dep,  double w) {
			name = n;
			id = i;
			department = dep;
			work_hour = w;
		}
		void calculate_salary(void) override{
			salary = hours_wage * work_hour;
			cout<<"The salary of the Parttime Employee is : "<<salary<<endl;
		}
};

class Contractor: public Employee{
	protected: 
		const double hours_wage = 60;
		double work_hour;
		double salary;
	public:
		Contractor(string n, int i, string dep, double w) {
			name = n;
			id = i;
			department = dep;
			work_hour = w;
		}
		void calculate_salary(void) override {
			salary = hours_wage * work_hour;
			cout<<"The salary of the Contractor is: "<<salary<<endl;
		}
};

int main(void){
	Employee* emp;
	emp = new FullTime("sumedh",2315,"CSE", 7);
	cout<<"FullTime: "<<endl;
	emp->display_info();
	emp->calculate_salary();
	delete emp;
    cout<<"------------------------------"<<endl;

    emp = new PartTime("Kunal", 2007, "MED", 4);
    cout<<"PartTime: "<<endl;
    emp->display_info();
    emp->calculate_salary();
    delete emp;
    cout<<"------------------------------------"<<endl;

    emp = new Contractor("om", 2024, "CHE", 9);
    cout<<"Contractor: "<<endl;
    emp->display_info();
    emp->calculate_salary();
    cout<<"-------------------------------------"<<endl;

	
	return 0;
}