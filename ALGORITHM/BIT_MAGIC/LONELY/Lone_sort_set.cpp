// The usage of multiset.
// multiset automatically keeps the data in an order.
// Just keep the pair of numbers and check equality.

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int
main(void)
{
    
    multiset<int> iNum = { 1, 4, 2, 2, 3, 4, 1 };
    
    int iLoneNum = 0;
    
    int i, j, iPair1, iPair2;
   
    j = 0;
    
    for( auto &i : iNum ){
        if( j%2 == 0 ) iPair1 = i;
        else{
            iPair2 = i;
            if( iPair1 != iPair2 )  break;
        } 
        j++;
    } 
    cout << iPair1 << " is lonely data." << endl;
    
   return 0;
    
}