//99 99
//3.14159 3.14159

#include <iostream>

using namespace std;

int
main()
{
    int i = 99;
    int *const pi1 = &i;
    
    cout << i << " " << *pi1 << endl;
    
    const double pi = 3.14159;
    const double    *const cppi = &pi;
    
    cout << pi << " " << *cppi << endl;
    return 0;
}