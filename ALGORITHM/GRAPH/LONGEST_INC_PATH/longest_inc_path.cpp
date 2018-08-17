#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>

using namespace std;

/*
wangk@amazon.com
Coding:
[9,9,4],
[6,6,8],
[2,1,1]

Start with any number in the 2D array, move up down left right, only move when the next number is 
greater than the current one till you cannot move, starting number to ending number is a path.   
4 -> 8
4 -> 9 
1 -> 2 -> 6 -> 9 , return 4

[3,4,5],
[3,2,6],
[2,2,1]
 
3 -> 4 - > 5 -> 6

Input: 2D array, dimension: N*M 
Output: find the longest path, return the length, an integer
*/
#define N 3

int
iGetNumOfPaths(int iRow, int iCol, int Matrix[N][N], int iVisited[N][N])
{
    int result = 0;
    
    cout << "visiting (" << iRow << "," << iCol << ")" << Matrix[iRow][iCol] << endl;
    
    if( iRow < 0 || iRow >=N || iCol < 0 || iCol >= N) return 0;
    
    if( iVisited[iRow][iCol] != -1 ) return iVisited[iRow][iCol];

            
    // (1 2 (6) 5 4 3 2 1) what is the length?    3  6  or 9?     length of the array?          
    //Go right
    if( iCol < N-1 && Matrix[iRow][iCol+1] > Matrix[iRow][iCol]) {
            cout << "Go right" << endl;
            //return iVisited[iRow][iCol] = 1 + iGetNumOfPaths(iRow, iCol+1, Matrix, iVisited);
            result = 1 + iGetNumOfPaths(iRow, iCol+1, Matrix, iVisited);
    }
    //Go left
    if( iCol > 0 && Matrix[iRow][iCol-1] > Matrix[iRow][iCol] ){
              //return iVisited[iRow][iCol] = 1 + iGetNumOfPaths(iRow, iCol-1, Matrix, iVisited);
            result = max( result, 1 + iGetNumOfPaths(iRow, iCol-1, Matrix, iVisited) );
    } 
    //Go Down
     if(  iRow < N-1  && Matrix[iRow+1][iCol] > Matrix[iRow][iCol])  {
            // return iVisited[iRow][iCol] = 1 + iGetNumOfPaths(iRow+1, iCol, Matrix, iVisited);
            result = max( result, 1 + iGetNumOfPaths(iRow+1, iCol, Matrix, iVisited) );
     }
    //Go Up
    if( iRow > 0  && Matrix[iRow-1][iCol] > Matrix[iRow][iCol]){
            //return iVisited[iRow][iCol] = 1 + iGetNumOfPaths(iRow-1, iCol, Matrix, iVisited);
            result = max( result, 1 + iGetNumOfPaths(iRow-1, iCol, Matrix, iVisited) );
    } 
    

    return iVisited[iRow][iCol] = result;
    
    
}

int 
iFindMaxPath( int Matrix[N][N])
{
    int iRow, iCol, iCnt;
    int iMax = 0;
    int iVisited[N][N] =     { {-1,-1,-1},
                               {-1,-1,-1},
                               {-1,-1,-1} };
    
    //memset( iVisited, -1, sizeof iVisited );
    
    for( iRow = 0; iRow <N; iRow++)
    {
        for( iCol = 0; iCol <N; iCol++){
             cout << endl << "Find out the path to " << iRow << "," << iCol << endl;
             iCnt = iGetNumOfPaths(iRow, iCol, Matrix, iVisited);
             cout << "(" << iRow << "," << iCol << ") Paths:" << iCnt << " "; 
             if(iCnt > iMax ) iMax = iCnt;
        }
        cout << endl;
    }
    cout << "===================================="  << endl;
    return iMax;
}

int
main(void)
{
    int M[N][N] = {  {9,9,4},
                     {6,6,8},
                     {2,1,1} };
    
    //cout <<  iFindMaxPath( M ) << endl;
    int M1[N][N] = { {3,4,5},
                     {3,2,6},
                     {2,2,1} };
    //cout <<  iFindMaxPath( M1 ) << endl;
    int M2[N][N] = { {1,2,9},
                     {5,3,8},
                     {4,6,7} };
    
    //assert( iFindMaxPath( M )==4); 
    //assert( iFindMaxPath( M1 )==4); 
    //assert( iFindMaxPath( M2 )==7); 
    cout <<  iFindMaxPath( M ) << endl; 
    cout <<  iFindMaxPath( M1 ) << endl; 
    cout << iFindMaxPath( M2 ) << endl; 
    return 0;
}












