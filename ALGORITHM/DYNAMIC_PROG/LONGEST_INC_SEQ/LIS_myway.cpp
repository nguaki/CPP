//My way failed to accomplish the task.
//This is where the power of algorithm comes to play.
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int
iFindLIS(int *iA, int iSize)
{
    vector<int> v[iSize];
    int i;
    
    for(int iStartingPoint = 0; iStartingPoint < iSize; iStartingPoint++ )
    {
        v[iStartingPoint].push_back(iA[iStartingPoint]);
        for(int j = iStartingPoint+1; j < iSize; j++)
        {
           if( v[iStartingPoint].back() < iA[j]) 
                v[iStartingPoint].push_back(iA[j]);
            else if( j < iSize - 1)
                j++;
        }
    }
  
    int iMax = 0; 
    for(int iStartingPoint = 0; iStartingPoint < iSize; iStartingPoint++ )
    {
       if(v[iStartingPoint].size() > iMax) iMax = v[iStartingPoint].size();
       for( int j=0; j<v[iStartingPoint].size(); j++){
           cout <<  v[iStartingPoint][j] << "   ";
       }
       cout << endl;
    } 
    
    cout << iMax << endl;
} 


int
main(void)
{
    int iA[] = { 3, 4, -1, 0, 6, 2, 3 };
    cout << iFindLIS(iA, sizeof(iA)/sizeof(iA[0]));
    
    return 0;
}