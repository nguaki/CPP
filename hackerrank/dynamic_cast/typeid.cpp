//4base
//8derived1
//8derived2
//4base

#include <iostream>
#include <typeinfo>

using namespace std;

class base{};

class derived1 : public base{};

class derived2 : public base{};

int
main()
{

    cout << typeid(base).name() << endl;
    cout << typeid(derived1).name() << endl;
    cout << typeid(derived2).name() << endl;

    base *b = new derived1;

    cout << typeid(*b).name() << endl;


}