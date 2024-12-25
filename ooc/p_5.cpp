#include <iostream>
#include <cstdlib>
using namespace std;

enum months{
	JAN = 1,
	FEB,
	MAR,
	APR,
	MAY,
	JUN,
	JUL,
	AUG,
	SEP,
	OCT,
	NOV,
	DEC
};

int main(void){
	int month_no = 0;
	months mn;
	cout<<"Please enter the month number:";
	cin>>month_no;

	if(!(month_no >= 1 && month_no <= 12)){
		cout<<"Please Enter the valid month Number"<<endl;
		exit(EXIT_FAILURE);
	}
	
	cout<<"The Month Name is"<<endl;
	switch(month_no){
		case JAN:
			cout<<"JANAURY"<<endl;
			break;
		case FEB:
			cout<<"FEBRUARY"<<endl;
			break;

		case MAR:
			cout<<"MARCH"<<endl;
			break;

		case APR:
			cout<<"APRIL"<<endl;
			break;

		case MAY:
			cout<<"MAY"<<endl;
			break;

		case JUN:
			cout<<"JUNE"<<endl;
			break;

		case JUL:
			cout<<"JULY"<<endl;
			break;

		case AUG:
			cout<<"AUGUST"<<endl;
			break;

		case SEP:
			cout<<"SEPTEMBER"<<endl;
			break;

		case OCT:
			cout<<"OCTOBER"<<endl;
			break;

		case NOV:
			cout<<"NOVMBER"<<endl;
			break;

		case DEC:
			cout<<"DECEMBER"<<endl;
			break;
	}

	return 0;
}
