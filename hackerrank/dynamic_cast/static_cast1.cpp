//Derived1Functionn= 0
//Derived1Functionn= 5

#include <iostream>

using namespace std;

class Base
{
    public:
        virtual void f(){}
};

class Derived1 : public Base
{
    int n;
    
    public:
        Derived1(int n1):n(n1){}
        Derived1(){}
        void Derived1Function()
        {
            cout << "Derived1Function" << "n= " << n << endl;
        }
};

class Derived2 : public Base
{
    int otherData;
    
    public:
        Derived2(){ otherData = 5; }
};

int
main()
{
    Base *base = new Derived1;
    
    Derived1 *d1 = static_cast<Derived1 *>(base);
    
    d1->Derived1Function();

    //////////////////////////////////////////////////////////////////
    Base *base1 = new Derived2;
    
    //Weird!!!  Below compiles without a problem.
    //Although base1 is a pointer to Derived2 class, it is
    //static_cast to Derived1 class.
    //d2 type is Derived1.
    Derived1 *d2 = static_cast<Derived1 *>(base1);
    d2->Derived1Function();

    //////////////////////////////////////////////////////////////////
    //Below does not return anything.
    Base *base2 = new Derived2;
    
    Derived1 *d3 = dynamic_cast<Derived1 *>(base2);
    if( d3 ){
        d3->Derived1Function();
        
    }
    
    return 0;
}