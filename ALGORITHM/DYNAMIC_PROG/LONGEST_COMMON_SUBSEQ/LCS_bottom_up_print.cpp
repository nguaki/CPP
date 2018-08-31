//Prints out longest common subsequence using stack.
//Aug 29, 18
#include <iostream>
#include <stack>

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
    
    for (iCol=0; iCol<=iLength1; iCol++)
        M[0][iCol] = 0;
        
    for (iRow=0; iRow<=iLength2; iRow++)
        M[iRow][0] = 0;
        
    for (iRow=1; iRow<=iLength1; iRow++){
        
        for (iCol=1; iCol<=iLength2; iCol++){
            
            if(S1[iRow-1] == S2[iCol-1])
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
    
    int iLSCLength = M[iLength1][iLength2]; 
    iRow = iLength1;
    iCol = iLength2;
    stack<char> stChar;
    
    while( iRow > 0 && iCol > 0 ){
       if ( S1[iRow-1] == S2[iCol-1] ){
           stChar.push(S1[iRow-1]);
           iRow--; iCol--;
       }else if( M[iRow-1][iCol] > M[iRow][iCol-1] )
           iRow--;
       else
           iCol--;
    }
    
    while( stChar.size() ){
        cout << stChar.top();
        stChar.pop();
    }
    return iLSCLength;
}

int
main(void)
{
    string S1 = "abcdaf";
    string S2 = "acbcf";
    
    cout << iLCS(S1, S2);
    
    return 0;
}