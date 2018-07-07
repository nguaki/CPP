//10 10
//-1 0 
//100 100
//999 999
//9999 9999
#include <iostream>

using namespace std;

int 
main()
{
    //(a)illegal
    //compilation error
    //error: invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘int’
    //int i = -1, &r = 0;
    
    //(b)
    int i2 = 10;
    int *const pi2 = &i2;
    cout << i2 << " " << *pi2 << endl;
    
    //(c)
    const int i = -1, &r = 0;//with const, reference can assign a scalar value.
    cout << i << " " << r << " " << endl;
    
    //(d)
    int i3 = 100;
    const int *const pi3 = &i3;
    cout << i3 << " " << *pi3 << endl;
    
    //(e)
    int i4 = 999;
    const int *pi4 = &i4;
    cout << i4 << " " << *pi4 << endl;
    
    //(f)
    int i5 = 777l;
    //error: ‘const’ qualifiers cannot be applied to ‘const int&’
    //const int &const r2 = i5; 
    
    //(g)
    int i6 = 9999;
    const int i7 = i6, &r6 = i6;
    cout << i7 << " " << r6 << endl;
    return 0;
}