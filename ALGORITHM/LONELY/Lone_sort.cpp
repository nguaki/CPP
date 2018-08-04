//This is using sorting method.
//This is time complexity of O(nlogn) + O(n).
//Very efficient.
#include <iostream>
#include <algorithm>

using namespace std;

int
main(void)
{
    int iNum[] = { 1, 4, 2, 2, 3, 4, 1 };
    
    int iLoneNum = 0;
    
    int i, j;
   
    sort( iNum, iNum+7);  
    
    for( i = 0; i < 6; i=i+2 )
        if( iNum[i] != iNum[i+1]) break;
        
   cout << iNum[i] << " is lonely.";
   
   return 0;
    
}