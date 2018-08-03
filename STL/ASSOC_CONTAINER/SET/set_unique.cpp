//July 9, 18
// 
//Demonstrating that set keeps just unique number.
//
//OUTPUT 
//5
#include <iostream>
#include <set>

using namespace std;

int
main(void)
{
    set<int> si;
    int i;
    
    //Note that it is inserting 5 ten times
    for( i = 0; i < 10; i++ ) si.insert(5);
   
    for( auto &it : si ) cout << it << "  ";
    cout << endl;

    return 0;
}