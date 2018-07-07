//  compiled time casting
//
//  5
//
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int
main()
{

    double d = sqrt(static_cast<double>(25));
    cout << d << endl;
    
    return 0;
}


