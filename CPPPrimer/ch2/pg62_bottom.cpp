//3.14  3.14
//9.9999 9.9999 
#include <iostream>

using namespace std;

int
main()
{
    const double cd = 3.14;
    const double *cpd = &cd;
    
    cout << cd << " " << *cpd << endl;
    
    //compilation error
    //invalid conversion from ‘const double*’ to ‘double*’ [-fpermissive]
    //double *pd1 = &cd;
    
    //compilation error
    //error: assignment of read-only location ‘* pd’
    //*cpd = 44.4;
    
    double dval = 9.9999;
    cpd = &dval;
    
    cout << dval << " " << *cpd << endl;
    return 0;
}