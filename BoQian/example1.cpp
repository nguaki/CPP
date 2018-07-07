//9 9
//0x7ffe8479ac54 0x7ffe8479ac58
//-2072400808 9
//9 9
//0x7ffc341c14cc 0x7ffc341c14d0
//874255568 9
#include <iostream>

using namespace std;

int
main()
{
    const int i = 9;
    
    const int *p = &i;
    
    cout << *p << " " << i << endl;
    cout << p++ << " " << p << endl; //pointer was able to advance.
    cout << *p << " " << i << endl;  //pointer now prints a whatever is in that address.
    
    //Notice that the following declaration means the same.
    int const *p1 = &i;
    cout << *p1 << " " << i << endl;
    cout << p1++ << " " << p1 << endl; //pointer was able to advance.
    cout << *p1 << " " << i << endl;  //pointer now prints a whatever is in that address.
    
    return 0;
}