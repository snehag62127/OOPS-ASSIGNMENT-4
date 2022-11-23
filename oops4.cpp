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
            getline(name);
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
    int choose;
    Savings s;
    Current c;
    Account *a;
    cout<<"1.Savings \n2.Current \nEnter your choice : ";
    cin>>choose;
    switch (choose)
    {
        case 1: 
            a=&s;
            a->get_data();
            a->display();
            cout<<"\n1.Deposit \n2.Withdraw \nEnter your choice : ";
            cin>>choose;
            switch(choose)
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
            cin>>choose;
            switch(choose)
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
    
    FILE* ptr;
    char ch;
 
    ptr = fopen("my_file.txt", "r");
 
    if (NULL == ptr) 
    {
        cout<<"file can't be opened \n";
    }
    cout<<"content of this file are \n";
    do 
    {
        ch = fgetc(ptr);
        cout<<ch;
    } while (ch != -1);
    fclose(ptr);
    
   return 0;
}
