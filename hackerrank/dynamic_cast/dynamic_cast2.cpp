//An example of RTTI - run time type identification.
//
//Randomly generates a number.
//Does mod of 2.
//If it is odd, base pointer is assigned to Derived1 obj.
//If it is even, base pointer is assigned to Derived2 obj.
//
#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>

using namespace std;

class Base{
    virtual void display(){}
};

class Derived1 : public Base{};

class Derived2 : public Base{};

int
main()
{
    srand(time(0));

    Base *base = ( rand() % 2 ) == 0 ? static_cast<Base *>(new Derived1): new Derived2;
    
    Derived1 *d1 = dynamic_cast<Derived1*>(base);
    
    if( d1 )
    {
        cout << "derived1" << endl;
    }

    Derived2 *d2 = dynamic_cast<Derived2*>(base);
    
    if( d2 )
    {
        cout << "derived2" << endl;
    }
   
    return 0;
}