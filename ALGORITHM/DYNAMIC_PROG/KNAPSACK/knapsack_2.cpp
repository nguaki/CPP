//Pesky indexes.
//Starting from 0 or 1 is not a guessing game.
//Logic can be perfect but whether index starts from 0 or 1 can make
//break the program.
//Since keys are unique. This is a great situation to apply map DS.
#include <iostream>
#include <algorithm>
#include <map>

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
    int iWeights[] = {0, 1,3,4,5};
    //int iValues[]  = {0, 1,4,5,7};
    map<int,int> mValues;
    int iKnapSackCap = 7;
    int iNumOfItems = sizeof(iWeights)/sizeof(iWeights[0]);
    int iValueMatrix[iNumOfItems+1][9];
    int iItem;
    int iWeight;

    mValues[0] = 0;
    mValues[1] = 1;
    mValues[3] = 4;
    mValues[4] = 5;
    mValues[5] = 7;
    
    for(iItem = 0; iItem <= iNumOfItems; iItem++ ){
        for(iWeight=0; iWeight<= iKnapSackCap; iWeight++ ){
            //These zero row and column play foundational rol in
            //building this matrix.
            if( iItem == 0 || iWeight == 0 ) 
                iValueMatrix[iItem][iWeight] = 0;
            //If an item weight is greater than current capacity, the value
            //is same as before.
            else if( iWeights[iItem] > iWeight )
                iValueMatrix[iItem][iWeight] = iValueMatrix[iItem-1][iWeight];
            else
                iValueMatrix[iItem][iWeight] = 
                            max(iValueMatrix[iItem-1][iWeight],
                                //iValues[iItem] + iValueMatrix[iItem-1][iWeight-iWeights[iItem]] );
                                mValues[iWeights[iItem]] + iValueMatrix[iItem-1][iWeight-iWeights[iItem]] );
        }         
    }
    
    vPrintMatrix( iValueMatrix, iNumOfItems, iKnapSackCap);
    cout << "Maximum capacity:" << iValueMatrix[iNumOfItems][iKnapSackCap] << endl;
    
    int iMaxValue = iValueMatrix[iNumOfItems][iKnapSackCap];
    iWeight = iKnapSackCap;
    
    for( iItem = iNumOfItems; iItem > 0 && iMaxValue > 0; iItem-- ) 
    {
        if( iMaxValue != iValueMatrix[iItem-1][iWeight] )
        {
            //cout << "Weight:" << iWeights[iItem] << "   Value:" << iValues[iItem] << endl;
            cout << "Weight:" << iWeights[iItem] << "   Value:" << mValues[iWeights[iItem]] << endl;
            iWeight = iWeight - iWeights[iItem];
            //iMaxValue = iMaxValue - iValues[iItem];
            iMaxValue = iMaxValue - mValues[iWeights[iItem]];
        } 
    }
    
    return 0;
}