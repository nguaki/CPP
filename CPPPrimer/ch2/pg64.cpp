//99 99
//42 42
//42
//42
//42
//42
//42 

#include <iostream>

using namespace std;

int
main()
{
    int i = 99;
    
    //const is Top level - pointer is a constant.
    int *const p1 = &i;
    cout << i << " " << *p1 << endl;
    
    //const is Top level - object itself is a constant.
    const int ci = 42;
    
    //const is lower level since pointer is pointing at a const.
    const int *p2 = &ci;
    cout << ci << " " << *p2 << endl;
    
    //Right const is Top level since pointer is constant.
    //Left  const is Lower level since pointer is pointing at a const.
    const int *const p3 = p2;
    cout << *p3 << endl;
    
    //const is lower level since it is a reference.
    const int &r1 = ci;
    cout << r1 << endl;
    
    i = ci;// integer variable gets assigned a constant integer.
    cout << i << endl;
    
    p2 = p3;  // p2 is a pointer to const int.
              // p3 is a const pointer to const int.
              //According to the book, Top level gets ignored.
              //p3 right const is Top level.  So when it is ignored,
              //"const int *const p3" becomes "const int p3".
              //p2 doens't have Top level..
              
    cout << *p2 << endl;
    
    //Compilation error
    //pg64.cpp:42:14: error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
    //Explanation:
    //p3 has a Lower level const of "const int" but p doesn't.
    //int *p = p3;
    
    //The following is legal since both have same Low level const which is 'const int'.
    p2= p3;
    
    //p2 is a pointer to const int but i is not a const. 
    //How is this legal?
    //This is an exception: There is automatic conversion from int to 'const int'.
    p2 = &i;
    
    //pg64.cpp:56:14: error: invalid initialization of reference of type ‘int&’ from expression of 
    //type ‘const int’
    //According to the book, the Top level const is ignored.  In this case ci is a Top level const.
    //Strictly from the book, this should work.  
    //int &r = ci;
    
    // This works. This is an exception also. There is auto conversion from int to
    // const int.
    const int &r2 = i;
    
    cout << r2 << " " << endl;
    
    return 0;
}