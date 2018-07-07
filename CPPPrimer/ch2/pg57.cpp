//1024 1024 1024
//1000 1000 1000
//1100 1100 1100
//9999 9999 9999
#include <iostream>

using namespace std;

int
main()
{
    int i = 1024, *p = &i, &r = i;
    
    cout << i << " " << *p << " " << r << endl;
    
    r = 1000;
    cout << i << " " << *p << " " << r << endl;
    
    *p = 1100;
    cout << i << " " << *p << " " << r << endl;
    
    i = 9999;
    cout << i << " " << *p << " " << r << endl;
    
    return 0;
}