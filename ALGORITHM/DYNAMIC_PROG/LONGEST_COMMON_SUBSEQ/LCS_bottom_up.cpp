#include <iostream>

using namespace std;

void
vPrint(int iaDS[][14])
{
    for( int i=0; i<14; i++){
        
        for( int j=0; j<14; j++)
            cout << iaDS[i][j] << " ";
        cout << endl;
    }
} 
int
iLCS( string S1, string S2 )
{
    int iLength1 = S1.length();
    int iLength2 = S2.length();
    int iCol, iRow;
    
    int M[iLength1+1][iLength2+1];
    
    for (iCol=0; iCol<iLength1; iCol++)
        M[0][iCol] = 0;
        
    for (iRow=0; iRow<=iLength2; iRow++)
        M[iRow][0] = 0;
        
    for (iRow=1; iRow<=iLength1; iRow++){
        for (iCol=1; iCol<=iLength2; iCol++){
            if(S1[iRow] == S2[iCol])
                M[iRow][iCol] = 1 + M[iRow-1][iCol-1];
            else
                M[iRow][iCol] = max(M[iRow-1][iCol], M[iRow][iCol-1]);
        }
    }
   
    for (iRow=0; iRow<=iLength1; iRow++){
        for (iCol=0; iCol<=iLength2; iCol++){
            cout << M[iRow][iCol] << "  ";
        }
        cout << endl;
    }
    
    return M[iLength1][iLength2]; 
}

int
main(void)
{
    string S1 = "abcdaf";
    string S2 = "acbcf";
    
    cout << iLCS(S1, S2);
    
    return 0;
}