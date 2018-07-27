//July 9, 18
// 
//Demonstrating that multi set keeps repeated number.
//
//OUTPUT 
//5  5  5  5  5  5  5  5  5  5  
#include <iostream>
#include <set>

using namespace std;

int
main(void)
{
    multiset<int> si;
    int i;
    
    //Note that it is inserting 5 ten times
    for( i = 0; i < 10; i++ ) si.insert(5);
   
    for( auto &it : si ) cout << it << "  ";
    cout << endl;

    return 0;
}