//5 5 
#include <iostream>

using namespace std;

int
main()
{
    int i;
    int &ri = i;
    
    double d;
    //double &rd1 = i; //causes compilation error.
    double &rd = d;
    
    i = 5;
    rd = i;  //note that it is okay for a double pointer to point to an int.  
             //however, cannot do this in initialization stage;
    
    cout << i << " " << rd << endl;
    
    return 0;
}