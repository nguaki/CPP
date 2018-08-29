#include <iostream>
#include <algorithm>

using namespace std;

void
vPrintMatrix( int iValueMatrix[][9], int iNumOfItems, int iKnapSackCap)
{
    for( int i = 0; i <= iNumOfItems; i++){
        for( int j = 0; j <= iKnapSackCap; j++){
            cout << iValueMatrix[i][j] << "    ";
        }
        cout << endl;
    }
}

int
main(void)
{
    int iWeights[] = {1,3,4,5};
    int iValues[]  = {1,4,5,7};
    int iKnapSackCap = 7;
    int iNumOfItems = sizeof(iWeights)/sizeof(iWeights[0]);
    int iValueMatrix[iNumOfItems+1][9];
    int iItem;
    int iWeight;

    for(iItem = 0; iItem <= iNumOfItems; iItem++ )
        for(iWeight=0; iWeight<= iKnapSackCap; iWeight++ )
            //These zero row and column play foundational rol in
            //building this matrix.
            if( iItem == 0 || iWeight == 0 ) 
                iValueMatrix[iItem][iWeight] = 0;
            else
                iValueMatrix[iItem][iWeight] = -1;
            
    vPrintMatrix( iValueMatrix, iNumOfItems, iKnapSackCap);
    
    for(iItem = 1; iItem <= iNumOfItems; iItem++ ){
        for(iWeight=1; iWeight<= iKnapSackCap; iWeight++ ){
            //If an item weight is greater than current capacity, the value
            //is same as before.
            if( iWeights[iItem-1] > iWeight )
                iValueMatrix[iItem][iWeight] = iValueMatrix[iItem-1][iWeight];
            else
                iValueMatrix[iItem][iWeight] = 
                            max(iValueMatrix[iItem-1][iWeight],
                                iValues[iItem-1] + iValueMatrix[iItem-1][iWeight-iWeights[iItem-1]] );
        }         
    }
    
    vPrintMatrix( iValueMatrix, iNumOfItems, iKnapSackCap);
    cout << iValueMatrix[iNumOfItems][iKnapSackCap] << endl;
    
    return 0;
}