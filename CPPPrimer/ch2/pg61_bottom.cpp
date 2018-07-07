#include <iostream>

using namespace std;

int
main()
{
    int i = 100;
    const int &ri1 = i;
    const int &ri2 = ri1 * 2;
    
    cout << i << " " << ri1 << " "  << ri2 << endl;
    
    const int &ri3 = 200;
    
    cout << ri3 << endl;
    
    //compilation error
    //error: invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘int’
    int &ri4 = ri3 * 2;
    
    return 0;
}