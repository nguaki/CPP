//50 50 50
#include <iostream>

using namespace std;

int
main()
{
    int i;
    int *pi;
    int **ppi;
    
    i = 50;
    pi = &i;
    ppi = &pi;
    
    cout << i << " " << *pi << " " << **ppi << endl;
    return 0;
}