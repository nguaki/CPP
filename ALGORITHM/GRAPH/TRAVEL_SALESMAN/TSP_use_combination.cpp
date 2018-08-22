//Aug 21, 2018
//Using brute force method to come up with shortest path of travelling salesman
//algorithm.
//Although, this is brute force, implementation required next_permutation algo.
//If this algo wasn't available, had to write permutation recursive in a loop
//function.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int
iCalShortestPath(int iaG[][4], int iDepartVertex )
{
    vector<int> vecNeedToVisit;
    int iVertices;
    int iaShortDistVerticies[6];
    int iaVistedVerticies[6];
    
    iaShortDistVerticies[0] = iDepartVertex;
    iaShortDistVerticies[5] = iDepartVertex;
    
    int iLen = sizeof(iaG[0])/sizeof(iaG[0][0]);
    
    for( iVertices=0; iVertices<iLen; iVertices++)
        if( iVertices != iDepartVertex ) vecNeedToVisit.push_back(iVertices);
   
    //Since, this is automatically sorted, don't need to sort. 
    
    int iMinLength = INT_MAX;
    int iDepVertex = iDepartVertex;
    int iTotalTraveled; 
    
    do{
        int iTotalTraveled = 0; 
        for( iVertices = 0; iVertices<iLen; iVertices++ ){
            iTotalTraveled += iaG[iDepVertex][vecNeedToVisit[iVertices]];
            iDepVertex = vecNeedToVisit[iVertices];
            iaVistedVerticies[iVertices] = iDepVertex;
        }
        if( iTotalTraveled < iMinLength )
        {
            iMinLength = min(iTotalTraveled, iMinLength ); 
            for( iVertices = 0; iVertices<iLen; iVertices++ )
                    iaShortDistVerticies[iVertices+1] = iaVistedVerticies[iVertices];
            
        }
    }while( next_permutation(vecNeedToVisit.begin(), vecNeedToVisit.end()));
   
    for( size_t i=0; i < 6; i ++ ) cout << iaShortDistVerticies[i] << "  ";
    cout << endl;
    
    return iMinLength;
}

main(void)
{
    int iaGraph[][4] = { {0 , 10, 15, 20 },
                        {10,  0, 35, 25 },
                        {15, 35, 0,  30 },
                        {20, 25, 30, 0  } };
                        
    cout << iCalShortestPath(iaGraph, 0 ) << endl;
    
    return 0;
}