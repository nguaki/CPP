#include <iostream>

using namespace std;

int
main()
{
    int i = 5, &r1 = i;
    double d = 1.1, &r2 = d;
    
    cout << i << " " << r1 << endl; // 5   5
    cout << d << " " << r2 << endl; // 1.1 1.1
    
    r2 = 3.14159;
    cout << d << " " << r2 << endl; // 3.14159 3.14159
    
    r2 = r1; 
    cout << r1 << " " << r2 << " "  << i << " " << d << endl;  // 5 5 5 5   note that d becomes 5.
  
    r2 = 4;
    i = r2;
    cout << r1 << " " << r2 << " "  << i << " " << d << endl;  // 4 4 4 4
    
    r1 = d;
    cout << r1 << " " << d << endl;  // 5 5

    return 0;
}