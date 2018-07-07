//42 42 42 42 42
#include <iostream>

using namespace std;

int
main()
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;
    
    auto a = r;  //a is an int
    auto b = ci; //b is an int
    auto c = cr; //c is an int
    auto d = &i; //d is int *
    auto e = &ci;//e is const int *
    
    const auto f = ci; // f is const int
    auto &g = ci; // g binds to ci
    
    a = 42;
    b = 42;
    c = 42;
    //error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
    //d = 42;
    d = &c;
    
    //error: invalid conversion from ‘int’ to ‘const int*’ [-fpermissive]
    //e = 42;
    e = &c;
    
    //error: assignment of read-only variable ‘f’
    //f = 42;
    
    cout << a << " " << b << " " << c << " " << *d << " " << *e << endl;
    return 0;
}