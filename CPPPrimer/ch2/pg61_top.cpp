//100 100
#include <iostream>

using namespace std;


int
main()
{
    const int i = 100;
    const int &ri = i;
    cout << i << " " << ri << endl;
    //compilation error message
    //error: assignment of read-only reference ‘ri’
    //ri = 42;
    
    //compilation error message
    //error: invalid initialization of reference of type ‘int&’ from expression of type ‘const int’
    //int &r2 = i;
    
    return 0;
}