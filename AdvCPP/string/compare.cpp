// Sep 29, 16
//
//OUTPUT:
//clear is greater than clear
//0
//clearA is greater than clear
//-1
//clearS is greater than clear
//1
//

#include <iostream>
#include <string>

using namespace std;

int
main()
{
    string s1 = "clear";
    string s2 = "clear";
    
    if(s1 > s2)
        cout << s1 << " is greater than " << s2 << endl;
    else
        cout << s2 << " is greater than " << s1 << endl;
    
    cout << s2.compare(s1) << endl;
    
    s1 = "clearA";
    s2 = "clear";
    
    if(s1 > s2)
        cout << s1 << " is greater than " << s2 << endl;
    else
        cout << s2 << " is greater than " << s1 << endl;
    
    cout << s2.compare(s1) << endl;

    s1 = "clear";
    s2 = "clearS";
    
    if(s1 > s2)
        cout << s1 << " is greater than " << s2 << endl;
    else
        cout << s2 << " is greater than " << s1 << endl;
    
    cout << s2.compare(s1) << endl;
    
    
    return 0;
}