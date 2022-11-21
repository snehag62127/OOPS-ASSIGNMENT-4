#include<iostream>
using namespace std;

class Host
{
public:
 class Nested
 {
 public:
 void PrintMe()
 {
 cout << "Printed!\n";
 }
 };
};
int main()
{
 Host::Nested foo;
 foo.PrintMe();
 return 0;
}


//HELLO I M ADIL  
