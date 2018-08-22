#include <iostream>

using namespace std;

int iIsHeap(int *, int );

/*
void
vSwap( int &iAtIndex, int &iAtLargest ) 
{
    int iTemp;
    
    iTemp            = iAtIndex;
    iAtIndex         = iAtLargest;
    iAtLargest       = iTemp;
}
*/

void
vHeapify( int *iArray, int iSize, int iIndex )
{
    int iLeftIndex = 2 * iIndex + 1;
    int iRightIndex = 2 * iIndex + 2;
    int iLargest = iIndex;
    
    if( iLeftIndex < iSize && iArray[iLeftIndex] > iArray[iLargest] )
        iLargest = iLeftIndex;
        
    
    if( iRightIndex < iSize && iArray[iRightIndex] > iArray[iLargest] )
        iLargest = iRightIndex;
    
    if( iLargest != iIndex ){
        //vSwap( iArray[iLargest], iArray[iIndex] );
        swap( iArray[iLargest], iArray[iIndex] );
        
        vHeapify( iArray, iSize, iLargest );
    } 
}    

void
vHeapSort(int *iArray, int iSize )
{
    int i;
    
    for( i=iSize/2 - 1; i >= 0; i-- )
        vHeapify( iArray, iSize, i );
        
    for( i=iSize-1; i>=0; i-- ){
        //vSwap( iArray[0], iArray[i]);
        swap( iArray[0], iArray[i]);
        vHeapify( iArray, i, 0 );
    }
}

int
iAscendSort(int *iArray, int iSize)
{
  
    for(int i=0; i<iSize-1; i++)
        if( !(iArray[i] <= iArray[i+1]) )
            return false;
    return true;
}

void
vPrintHeapArray( int *iArray, int iSize )
{
    int i;
    
    for( i=0; i<iSize; i++)
        cout << iArray[i] << endl;
}

int
main(void)
{
    int iArray[] = { 5, 10, 45, 11, 7, 9, 2 };
    
    int iSize = sizeof(iArray)/sizeof(iArray[0]);
    
    vHeapSort(iArray, iSize );
    
    vPrintHeapArray( iArray, iSize );
    
    if (iAscendSort(iArray, iSize))
        cout << "Is ascending \n";
    else
        cout << "Not ascending\n";
    
    
    return 0;
}