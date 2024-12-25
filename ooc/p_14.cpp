/*
Animal Kingdom: Create a program to simulate the animal kingdom, where
     different species (Mammal, Bird, Reptile) inherit characteristics (name, age,
     habitat) and behaviors (eat, sleep, sound) from a base Animal class. 

*/

#include <iostream>
using namespace std;

class Animal{
	protected:
		string name;
		int age;
		string habitat;

	public:
		Animal(string n, int a, string h):name(n), age(a), habitat(h) {}

		virtual void eat(void){
			cout<<name<<"Animal is now eating"<<endl;
		}

		virtual void sleep(void){
			cout<<name<<" Animal is now Slepping"<<endl;
		}

		virtual void sound(void) = 0;

		virtual void  show_info(void){
			cout<<"Animal Name: "<<name<<endl;
			cout<<"Animal Age: "<<age<<endl;
			cout<<"Animal habitat: "<<habitat<<endl;
		}

};

class Mammal:public Animal{
	public:
		Mammal(string n, int a, string h):Animal(n,a,h) {}
		
		void sound(void) override{
			cout<<name<<"Makes mammalian sound"<<endl;
		}

		void show_info(void) override{
			cout<<"Mammal Info"<<endl;
			Animal::show_info();
		}
};

class Bird: public Animal{
	public:
		Bird(string n, int a, string h):Animal(n,a,h) {}

		void sound(void) override{
			cout<<name<<"crips or sounds"<<endl;
		}

		void show_info(void) override{
			cout<<"Bird Info"<<endl;
			Animal::show_info();
		}
};

class Reptile: public Animal{
	public:
		Reptile(string n, int a, string h):Animal(n,a,h) {}

		void sound(void) override{
			cout<<name<<"glows or hisses"<<endl;
		}

		void show_info(void) override{
			cout<<"Reptile Info"<<endl;
			Animal::show_info();
		}

};

int main(void){
	Animal* an = NULL;

	an = new Mammal("lion", 10, "Junle or ground");
	an->show_info();
	an->sleep();
	an->eat();
	an->sound();
	delete an;
	cout<<"---------------------------------"<<endl;

	an = new Bird("crow", 1, "tree");
	an->show_info();
	an->sleep();
	an->eat();
	an->sound();
	delete an;
	cout<<"----------------------------------------"<<endl;

	an = new Reptile("alligator", 2, "water or ground");
	an->show_info();
	an->sleep();
	an->eat();
	an->sound();
	delete an;
	

	return 0;
}
