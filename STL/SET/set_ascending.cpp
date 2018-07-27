//July 9, 18
// 
//Demonstrating that set keeps in ascending order.
//So this DT is good for finding a key.
//
//OUTPUT
//1  2  3  4  5  6  7  8  9  10  
//1  2  3  4  5  7  8  9  10  
#include <iostream>
#include <set>

using namespace std;

int
main(void)
{
    set<int> si;
    int i;
    
    //Note that it is inserting 10, 9, 8, 7, ...
    for( i = 0; i < 10; i++ ) si.insert(10-i);
   
    for( auto &it : si ) cout << it << "  ";
    cout << endl;

    auto it1 = si.find(6);
    si.erase(it1);
    for( auto &it : si ) cout << it << "  ";
    return 0;
}
