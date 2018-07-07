//3.14 3
#include <iostream>

using namespace std;

int
main()
{
    double dval = 3.14;
    const int &ri = dval;
    
    cout << dval << " "  << ri << endl;
    return 0;
}