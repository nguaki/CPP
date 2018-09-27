//Sep 26, 2018
//OUTPUT:
//30
//20
// FOO f = 20;  this line was able to compile and assign a private variable.
// Read the other file in this folder to fix this.
//
#include <iostream>

using namespace std;

class FOO{
    private:
        int X;
    public:
    
        FOO(int x){ X = x; }
        void print(){ cout << X << endl; }
};

void Print( FOO x )
{
    x.print();
}

int
main(void)
{
    FOO f(30);
    
    FOO g = 20;
    
    Print(f);
    Print(20);  // <====  Weird, but this calls constructor and sets it to 20.
    
    return 0;
}