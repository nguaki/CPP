#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <algorithm>

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
dfs(int matrix[N][N], int min, int i, int j, int m, int n, int cache[N][N])
{
   if (i<0 || j<0 || i>= m || j>=n || matrix[i][j] <= min) {
       return 0;
   } 
   if (cache[i][j] != 0){
       return cache[i][j];
   }
   min = matrix[i][j];
   
   int a = dfs(matrix, min,  i-1,   j  ,  n, m, cache) + 1;
   int b = dfs(matrix, min,  i+1,   j  ,  n, m, cache) + 1;
   int c = dfs(matrix, min,  i  ,   j-1,  n, m, cache) + 1;
   int d = dfs(matrix, min,  i  ,   j+1,  n, m, cache) + 1;
   
   //int max = Math.max( a, Math.max( b, Math.max(c,d)));
   int max1 = max( a, max( b, max(c,d)));
   cache[i][j] = max1;
   
   return max1;
}

int
iLongestIncreasingPaths( int matrix[N][N])
{
    //if (matrix == NULL || matrix.length == 0 ) return 0;
    int res = 0;
    
    //int m = matrix.length, n = matrix[0].length;
    int m = N, n = N;
    //int cache[][N] = new int[m][n];
    int cache[N][N] = {{0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0}};
    
    for ( int i=0; i < m; i++ ){
        for( int j=0; j < n; j++ ){
            int max1 = dfs(matrix, -1, i, j, m, n, cache);
            res = max(res, max1);
        }
    }
    return res;
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
    
    assert( iLongestIncreasingPaths( M )==4); 
    assert( iLongestIncreasingPaths( M1 )==4); 
    assert( iLongestIncreasingPaths( M2 )==7); 
    return 0;
}












