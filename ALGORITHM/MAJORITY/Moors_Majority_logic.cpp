#include <iostream>

using namespace std;

//Utilizes Moor's algo on majority vote.
// Read the comments below.
int
iFindCandidate(int *iA, int N)
{
    int iMajorIndex = 0; //Start the majority leader as index 0
    int iCnt = 1;        //Set the count to 0.
    int i;
    
    for( i=0; i<N; i++){
        if( iA[i] == iA[iMajorIndex] ) iCnt++;
        else iCnt--;
        //If iCnt is set to zero, change the MajorIndex.
        if(iCnt == 0){
            iMajorIndex = i;
            iCnt = 1;
        }
    }
    return iA[iMajorIndex];
}

int
main(void)
{
    int iA[] = { 3, 3, 4, 2, 4, 4, 2, 4, 4 };
    int N = 9; 
    //int iA[] = { 3, 3, 4, 2, 4, 4, 2, 4 };
    //int N = 8; 
    float fMajority = N/2;
    int i;
    bool bFound = false;
    int iCnt=0;
    
    int iCandidate = iFindCandidate(iA, N);
    
    for( i=0; i < N; i++ ){
        if( iCandidate == iA[i] ) iCnt++;
        if( (float)iCnt > fMajority )
        {
                cout << iA[i] << " is majority" << endl;
                bFound = true;
                break;
        } 
    }
    if( bFound == false )  cout << "There is no majority number." <<endl; 

    return 0;
}