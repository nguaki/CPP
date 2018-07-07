#include <iostream>

using namespace std;

int
main()
{
    int i = 100;
    
    //const is Top level.
    const int v2 = 999;
    
    int v1 = v2;
    
    int *p1 = &v1, &r1 = v1;
    
    //p2 is a pointer to const int - const is Low level.
    const int *p2 = &v2,
    //p3 is a const pointer to const int  - left const is Low level, right const is Top level.
              *const p3 = &i,
    //r2 is a low level since it is a reference.              
              &r2 = v2;
              
    //reference r1 gets const int v2.
    r1 = v2;
    
    //compilation error.
    //ex2.30.cpp:27:8: error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
    //p1 = p2;
    
    //There is auto conversion from 'int' to 'const int',
    p2 = p1;
    
    //ex2.30.cpp:34:8: error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
    //p1 = p3;
    
    //This is legal since these variables have same Lower level const.
    p2 = p3;
    
    return 0;
}