// Sep 29, 16
//hello  world!
//helloworld!

#include <iostream>
#include <cstring>

using namespace std;

int
main()
{
    //2 ways of assigning character array.
    char c1[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
    char c2[] = "world!";
    
    cout << c1 << "  " << c2 << endl;
    
    strcat( c1, c2 );
    cout << c1 << endl;
}