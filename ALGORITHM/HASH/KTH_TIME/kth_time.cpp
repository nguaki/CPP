//Aug 31, 2018
//There are multiple ways to solve this problem.
//This one uses hash map.
//There is an elegance in solving a problem using STL.
#include <iostream>
#include <unordered_map>

using namespace std;

int
main(void)
{
    int ia[] = { 1,2,3,2,3,4,5,6,7,7,7, 3,2};
    int ilen = sizeof(ia) / sizeof(ia[0]);
    unordered_map<int,int> um;
   
    int k = 3;
    
    for(int i=0; i<ilen; i++)
    {
        um[ia[i]]++;
        if (um[ia[i]] == k )
            cout << ia[i] << " has reached " << k << " times." << endl;
    } 
    
    return 0;
}
     
    