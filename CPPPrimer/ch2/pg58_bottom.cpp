//100 100 100
// 1000 1000 1000
#include <iostream>

using namespace std;

int
main()
{
    int i = 100;
    int *pi;
    int *&rpi = pi;
    
    pi = &i;
    
    cout << i << " " << *pi << " " << *rpi << endl; 
       //Interesting. when printing out reference to pointer, need to have * character.
       
    *rpi = 1000;
    cout << i << " " << *pi << " " << *rpi << endl; 

    return 0;
}