#include <iostream>

using namespace std;

int A[3][4] = { {-3,-2,-1, 1 },
                {-2, 2, 3, 4 },
                { 4, 5, 7, 8 } };
                
int
main(void)
{
    int NRows = 3;
    int NCol  = 4;
    
    int iCntNeg = 0;
    int iRow = 0, iCol = NCol - 1;
   
    while( iRow < NRows && iCol >=0 ){
        //If current position of the row is negative, 
        //this means that everything to the left is also negative.
        //Therefore, we can count # of negative # at this point and
        //move to next row.
        if(A[iRow][iCol] < 0 ){
            //The number of negative # is related to iCol variable.
            //It is based on 0th index, so need to add 1.
            iCntNeg = iCntNeg + iCol +1;     
            iRow += 1;  
        }
        //If the current element is not a negative number
        //check the number to its left.
        else{
            iCol -= 1;
        }
    }   
    cout << iCntNeg << endl;
    
    return 0;
}