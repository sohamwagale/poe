/*
University Hierarchy: Develop a system to manage different types of university
          staff (Professor, Lecturer, TeachingAssistant) who inherit common attributes
          (name, ID, department) and methods (teach, research, advise) from a base
          UniversityStaff class.
*/

#include <iostream>
using namespace std;

class UniversityStaff{
	protected:
		string name;
		long ID;
		string department;
	
	public:
		UniversityStaff(string n, long i, string d): name(n), ID(i), department(d) {}

		virtual void teach(void){
			cout<<name<<" is now teching"<<endl;
		}

		virtual void research(void){
			cout<<name<<" is conducting researching"<<endl;
		}

		virtual void advise(void){
			cout<<name<<" is Giving an adive"<<endl;
		}
	
		virtual void show_info(void){
			cout<<"Name : "<<name<<endl;
			cout<<"ID : "<<ID<<endl;
			cout<<"Department : "<<department<<endl;
		}
};

class Professor:public UniversityStaff{
	public:
		Professor(string n, long i, string d):UniversityStaff(n,i,d) {}
		
		void teach(void) override{
			cout<<name<<" is teaching an advance Topic"<<endl;
		}

		void research(void) override{
			cout<<name<<" is leading a unique project"<<endl;
		}
		
		void advise(void) override{
			cout<<name<<" is giving advice to Ph.D. students"<<endl;
		}

		void show_info(void) override{
			cout<<"Professor Info"<<endl;
			UniversityStaff::show_info();
		}
};

class Lecturer: public UniversityStaff{
	public:
		Lecturer(string n, long i, string d):UniversityStaff(n,i,d) {}

		void teach(void) override{
			cout<<name<<" is now teaching a chapter"<<endl;
		}

		void research(void) override{
			cout<<name<<" is now helping to students for research"<<endl;
		}

		void advise(void) override{
			cout<<name<<" is now giving advice to freshers"<<endl;
		}

		void show_info(void) override{
			cout<<"Lecturer Info"<<endl;
			UniversityStaff::show_info();
		}

};

class TeachingAssistant: public UniversityStaff{
	public:
		TeachingAssistant(string n, long i, string d):UniversityStaff(n,i,d) {}

		void teach(void) override{
			cout<<name<<" is coducting lab sessions for students"<<endl;
		}

		void research(void) override{
			cout<<name<<" is assisting to lecturer for research"<<endl;
		}

		void advise(void) override{
			cout<<name<<" is guiding to sudents how to do reasearch"<<endl;
		}

		void show_info(void) override{
			cout<<"Teaching_Assistant Info: "<<endl;
			UniversityStaff::show_info();
		}
};

int main(void){
	UniversityStaff* us = NULL;

	us = new Professor("xyz", 121212, "CSE");
	us->show_info();
	us->teach();
	us->research();
	us->advise();
	delete us;
	cout<<"----------------------------------------------------------------"<<endl;
	
    us = new Lecturer("abc", 653453, "CSE");
    us->show_info();
    us->teach();
    us->research();
    us->advise();
    delete us;
    cout<<"------------------------------------------------------------------"<<endl;

    us = new TeachingAssistant("pqr", 40934, "CSE");
    us->show_info();
    us->teach();
    us->research();
    us->advise();
    delete us;

    
	return 0;

}
