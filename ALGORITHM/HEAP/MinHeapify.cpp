#include <iostream>

using namespace std;

int iIsMinHeap(int *, int );

void
vSwap( int *iArray, int iLargest, int iIndex )
{
    int iTemp;
    
    iTemp            = iArray[iIndex];
    iArray[iIndex]   = iArray[iLargest];
    iArray[iLargest] = iTemp;
}


void
vMinHeapify( int *iArray, int iSize, int iIndex )
{
    int iLeftIndex = 2 * iIndex + 1;
    int iRightIndex = 2 * iIndex + 2;
    int iLargest = iIndex;
    
    if( iLeftIndex < iSize && iArray[iLeftIndex] < iArray[iLargest] )
        iLargest = iLeftIndex;
        
    
    //By checking if children are less tha parent, this created min heap.
    if( iRightIndex < iSize && iArray[iRightIndex] < iArray[iLargest] )
        iLargest = iRightIndex;
    
    if( iLargest != iIndex ){
        vSwap( iArray, iLargest, iIndex );
        
        vMinHeapify( iArray, iSize, iLargest );
    } 
}    

void
vMinHeap(int *iArray, int iSize )
{
    int i;
    
    for( i=iSize/2 - 1; i >= 0; i-- )
        vMinHeapify( iArray, iSize, i );
}

int
iIsMinHeap(int *iArray, int iSize)
{
    int iLeftChild, iRightChild;
    
    for(int i=0; i<iSize/2-1; i++)
    {
        iLeftChild  = 2 * i + 1;
        iRightChild = 2 * i + 2;
        
        if( !(iArray[i] <= iArray[iLeftChild] && iArray[i] <= iArray[iRightChild] ) )
            return false;
    }
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
    
    vMinHeap(iArray, iSize );
    
    vPrintHeapArray( iArray, iSize );
    
    if (iIsMinHeap(iArray, iSize))
        cout << "Is Heap\n";
    else
        cout << "Not a Heap\n";
    
    
    return 0;
}