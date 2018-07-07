//Demonstration of string methods.
//pin found is position 2
//pin found is position 25
//Forbid character found at position 7

#include <iostream>
#include <string>

using namespace std;

int
main()
{
    string s1 = "a pin in the haystack. a pin in the haystack.";
    string s2 = "pin";
    
    //Forward find.
    int pos = s1.find(s2);
    
    if( pos >=0 )
        cout << s2 << " found is position " << pos << endl;
    else
        cout << s2 << " not found" << endl;

    //Reverse find.
    pos = s1.rfind(s2);
    
    if( pos >=0 )
        cout << s2 << " found is position " << pos << endl;
    else
        cout << s2 << " not found" << endl;
        
    string sName = "Matthew1";
    string sForbidChars = "0123456789";
    
    pos = sName.find_first_of(sForbidChars);
    if(pos >=0)
        cout << "Forbid character found at position " << pos << endl;
    else
        cout << "These characters are legit." << endl;
    return 0;
}