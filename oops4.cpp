/*Create a class which stores account number, customer name and balance. Derive
two classes from ‘Account’ class: ‘Savings’ and ‘Current’. The ‘Savings’ class stores minimum
balance. The ‘Current’ class stores the over-due amount. Include member functions in the
appropriate class for -deposit money -withdraw [For saving account minimum balance
should be checked.] [For current account overdue amount should be calculated.] -display
balance Display data from each class using virtual function.*/

#include <iostream>
#include <string>
using namespace std;

class Account
{
    protected : 
        int accno;
        string name;
        double balance;
    public :
        void get_data()
        {
            cout<<"Enter details : ";
            cout<<"\nAccount Number : ";
            cin>>accno;
            cin.ignore();
            cout<<"Name : ";
            getline(cin,name);
            cout<<"Balance : ";
            cin>>balance;
        }
        void deposit()
        {
            double d;
            cout<<"Enter deposit amount : ";
            cin>>d;
            balance +=d;
        }
        virtual void display()
        {
            cout<<"Bank Details : \nAccount Number : "<<accno<<"\nName : "<<name<<"\nBalance : "<<balance;
        }
        virtual void check(){}
        virtual void calc(){}
};
class Savings : public Account
{
    double minbal;
    public :
        Savings()
        {
            cout<<"Enter minimum balance : ";
            cin>>minbal;
        }
        void display()
        {
            Account::display();
            cout<<"\nMinimum Balance : "<<minbal;
        }
        void check()
        {
            double wa;
            cout<<"Enter withdrawal amount : ";
            cin>>wa;
            if(balance<minbal || (balance-wa) < minbal)
            {
                cout<<"Not enough balance.";
                return;
            }
            balance -= wa;
            cout<<"\n Balance : "<<balance;
        }
};
class Current : public Account
{
    double odamt;
    public :
        Current()
        {
            cout<<"Enter current amount : ";
            cin>>odamt;
        }
        void display()
        {
            Account::display();
            cout<<"Over Due Amount : "<<odamt;
        }
        void calc()
        {
            double wa;
            cout<<"Enter amount to be withdrawn : ";
            cin>>wa;
            if( balance < odamt )
            {
                cout<<"Amount cannot be withdrawn.";
                return ;
            }
            balance-=wa;
            cout<<"Balance : "<<balance;
        }
};
template <typename T>
T GetMax (T a, T b) 
{
  T result;
  result = (a>b)? a : b;
  return (result);
}
int main()
{
    int ch;
    Savings s;
    Current c;
    Account *a;
    cout<<"1.Savings \n2.Current \nEnter your choice : ";
    cin>>ch;
    switch (ch)
    {
        case 1: 
            a=&s;
            a->get_data();
            a->display();
            cout<<"\n1.Deposit \n2.Withdraw \nEnter your choice : ";
            cin>>ch;
            switch(ch)
            {
                case 1: a->deposit(); break;
                case 2: a->check(); break;
                default : cout<<"Invalid Entry.";
            }
            break;
        case 2:
            a=&c;
            a->get_data();
            a->display();
            cout<<"1.Deposit \n2.Withdraw \nEnter your choice : ";
            cin>>ch;
            switch(ch)
            {
                case 1: a->deposit(); break;
                case 2: a->calc(); break;
                default : cout<<"\n Invalid Entry.";
            }
            break;
        default :
            cout<<"Invalid Entry.";
    }
    int i=5, j=6, k;
    long l=10, m=5, n;
    k=GetMax<int>(i,j);
    n=GetMax<long>(l,m);
    cout << k << endl;
    cout << n << endl;
   return 0;
}
