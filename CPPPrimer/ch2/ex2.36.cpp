//1000 1000
#include <iostream>

using namespace std;

int
main()
{
    int a = 999, b = 1000;

    decltype(a) c = a;   //c is int
    decltype((b)) d = a; //d is a ref to a
    
    c++;
    d++;
    
    cout << c << " " << d << endl;
    
    return 0;
}