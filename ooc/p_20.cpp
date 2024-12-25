#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void person_details() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person {
protected:
    string department;
    int ID;

public:
    Employee(string n, int a, string d, int i) : Person(n, a), department(d), ID(i) {}

    void employee_details() const {
        cout << "ID: " << ID << endl;
        cout << "Department: " << department << endl;
    }

    void teach() const {
        cout << name << " is teaching a core subject." << endl;
    }

    void research() const {
        cout << name << " is leading a secret project." << endl;
    }
};

class Professor : public Employee {
public:
    Professor(string n, int a, string d, int i) : Employee(n, a, d, i) {}

    void professor_details() const {
        cout << "------ Professor Details ------" << endl;
        person_details();
        employee_details();
        cout << "-------------------------------" << endl;
    }
};

int main() {
    Professor prof("xyz", 45, "CSE", 101);

    prof.professor_details();
    prof.teach();
    prof.research();

    return 0;
}
