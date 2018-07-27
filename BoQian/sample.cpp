#include<iostream>

using namespace std;

class A{
    int i;
    public:
    A():i(0){}
};


class B{
    int i;
};

int
main(void)
{
    A a();
    B b();
    A a1;
    B b1;
    
    return 0;
}