//Using vector.erase() and push_back() to move zeroes to the end.
#include <iostream>
#include <vector>

using namespace std;

int 
main(void)
{
    vector<int> vData = { 1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9 };
    int i; 
    int iNumZeros = 0;
    
    for( i=0; i<vData.size(); i++){
        if(vData[i] == 0 ){
            //Delete ith element.
            vData.erase(vData.begin()+i); //There should be a way to delete a vector item
                                          //using an index.
            i--;
            iNumZeros++;
        }
    }
    
    for( i=0; i<iNumZeros;i++)  vData.push_back(0);
    
    for( auto &it: vData ) cout << it << "  ";
    return 0;
}





    