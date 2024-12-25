/*
Bank Account Hierarchy: Design a program to represent various types of bank
     accounts (Savings, Checking, Credit) that inherit common attributes
     (accountNumber, balance) and behaviors (deposit, withdraw) from a base
     BankAccount class.
*/

#include <iostream>
using namespace std;

class BankAccount{
	protected:
		long account_number;
		double balance;
	public:
		void  deposit(double deposit_amount){
			balance = balance +  deposit_amount;
			cout<<"amaount deposited successfully. BALANCE : "<<balance<<endl;
		}

		void withdraw(double withdraw_amount){
			balance -= withdraw_amount;
			cout<<"amount withdraw successfully. BALANCE : "<<balance<<endl;
		}
        void money_operation(void);
};

void BankAccount::money_operation(void){
	static double da, wa;
	balance = 0;
	
	cout<<"Your AC no is : "<<account_number<<endl;
	cout<<"Currently AC balance is Zero\n please Deposit first"<<endl;
	
    cout<<"Please enter amount for deposit "<<endl;
	cin>>da;
    deposit(da);

	cout<<"Enter amount for withdraw"<<endl;
	cin>>wa;
    withdraw(wa);

}

class Savings: public BankAccount{
	public:
		Savings(long ac_no){
            account_number = ac_no;
        }
		void show_info(void){
			cout<<"Saving AC no : "<<account_number<<endl;
			cout<<"Balance: "<<balance <<endl;
		}

};

class Checking:public BankAccount{
	public:
		Checking(long ac_no){
            account_number = ac_no;
        }
		void show_info(void){
			cout<<"Checking AC no :"<<account_number<<endl;
			cout<<"Balance : "<<balance<<endl;
		}
};

class Credit:public BankAccount{
	public:
		Credit(long ac_no){
            account_number = ac_no;
        }
		void show_info(void){
			cout<<"Credit AC no : "<<account_number<<endl;
			cout<<"Balance : "<<balance<<endl;
		}
};

int main(void){
	Savings sv(12344565);
	cout<<"Savings Account"<<endl;
	sv.money_operation();
	sv.show_info();
	cout<<"-----------------------------------------------------"<<endl;

    Checking ch(2222222222);
    cout<<"Checking Account"<<endl;
    ch.money_operation();
    ch.show_info();
    cout<<"---------------------------------------------------"<<endl;

    Credit cd(545324242);
    cout<<"Credit Account"<<endl;
    cd.money_operation();
    cd.show_info();
	return 0;
}
