////////////////////////////////////////////////////////////////////////////////
// July 7, 18
//
// Demonstration of push_front(), insert() and erase() methods of list.
// Uses elegance of range print from c++17.
//
//=================================
//9   8   7   6   5   4   3   2   1   0   
//=================================
//9   8   7   6   5   4   3   2   1   0   
//=================================
//9   100   8   7   6   5   4   3   2   1   0   
//=================================
//9    100    8    7    6    5    3    2    1    0    
//
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int
main(void)
{

    list<int> l;
    int i;
    
    for(i=0; i<10; i++)
        l.push_front(i);
        
    cout  << "=================================" << endl;
    auto it = l.begin();
    while( it != l.end()){
        cout << *it << "   ";
        it++;
    }
    cout << endl;
    
    cout  << "=================================" << endl;
    for( auto &it : l ) cout << it << "   ";
    cout << endl;
    
    //Find 8 and insert 100 after 8.
    it = find(l.begin(), l.end(), 8);
    l.insert(it, 100);
   
    cout  << "=================================" << endl;
    for( auto &it : l ) cout << it << "   ";
    cout << endl;
    
    //Find 4 and delete it.
    it = find(l.begin(), l.end(), 4);
    l.erase(it);
   
    cout  << "=================================" << endl;
    for( auto &it : l ) cout << it << "    ";
    cout << endl;
    return 0;
}