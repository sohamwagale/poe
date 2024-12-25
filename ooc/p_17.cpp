/*
implement a class hierarchy for a simple library
system with a base class LibraryItem and derived classes Book and Magazine.
*/

#include <iostream>
using namespace std;

class LibraryItem{
    protected:
        int ID;
        string author;
        string title;

    public:
        LibraryItem(int i, string a, string t): ID(i), author(a), title(t) {}

        virtual void show_info(void){
            cout<<"Title Name: "<<title<<endl;
            cout<<"Author Name: "<<author<<endl;
            cout<<"ID: "<<ID<<endl;
        }

        virtual void check_out(void){
            cout<<"The iteam has beed checked out"<<endl;
        }

        virtual void return_item(void){
            cout<<"The iteam has beed returned"<<endl;
        }
        ~LibraryItem() {}
};

class Book: public LibraryItem{
    public:
        Book(int i, string a, string t):LibraryItem(i,a,t) {}

        void show_info(void) override{
            cout<<"BOOK INFO: "<<endl;
            LibraryItem::show_info();
        }

        void check_out(void) override{
            cout<<"The book name "<<title<<"Has been checked out"<<endl;
        }

        void return_item(void) override{
            cout<<"The book name "<<title<<"Has been returned to library"<<endl;
        }

};

class Magazine: public LibraryItem{
    public:
        Magazine(int i, string a, string t):LibraryItem(i,a,t) {}

        void show_info(void) override{
            cout<<"Magazine info:"<<endl;
            LibraryItem::show_info();
        }

        void check_out(void) override{
            cout<<"The Magazine "<<title<<" has been checked out"<<endl;
        }

        void return_item(void) override{
            cout<<"The Magazine "<<title<<" has Been checked out"<<endl;
        }
};

int main(void){
    LibraryItem* li = NULL;

    li = new Book(4302, "xyz", "X");
    li->show_info();
    li->check_out();
    li->return_item();
    delete li;
    cout<<"-------------------------------------------------"<<endl;

    li = new Magazine(545, "abc", "A");
    li->show_info();
    li->check_out();
    li->return_item();
    delete li;

    return 0;
}