//Much improvement in O().  went from N^2 to N.
//Must compile with -std=c++11
#include <iostream>
#include <map>

using namespace std;

int
main(void)
{
    //int iA[] = { 3, 3, 4, 2, 4, 4, 2, 4, 4 };
    //int N = 9; 
    int iA[] = { 3, 3, 4, 2, 4, 4, 2, 4 };
    int N = 8; 
   
    map<int,int> mapDS;
    
    int i;
    bool bFound = false;
    
    float fMajority = N/2;
    for( i=0; i<N; i++)
    {
       mapDS[iA[i]]++; 
       if(mapDS[iA[i]] > fMajority ) {
           cout << iA[i] << " is majority" << endl; 
           bFound = true;
           break;
        }
        
    } 
    
    if(bFound == false) cout << "No majority"  << endl;
    
    for( auto &it : mapDS ) cout << it.first << "  "  << it.second << endl;
    
    return 0;
}