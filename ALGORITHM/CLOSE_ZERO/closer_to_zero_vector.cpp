//Using the Vector DS to solve this problem.
#include <iostream>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int
main(void)
{
    vector<int> vData = { -85, 7, 9, 12, 80, 5, 2, 1, 1 };
    int N = vData.size(); 
    int l = 0,r = N-1, iMinLeft, iMinRight, iMinSum = INT_MAX;
    int iSum;
    
    sort( vData.begin(), vData.end() );
    
    while(l < r ){
        iSum = vData[l]+vData[r];
            
        if( abs(iSum) < iMinSum )
        {
            iMinSum = abs(iSum);
            iMinLeft = l;
            iMinRight = r;
        }
        //Tricky part.
        //Increase the left index.
        //Decrease the right index.
        if( iSum < 0 ) l++;
        else r--;
    }     
            
    cout << "Min sum close to zero is " << iMinSum << endl;
    cout << "Sum of " << vData[iMinLeft] << "and"  << vData[iMinRight] << endl;
    
    return 0;    
}
