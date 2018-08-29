//This algo goes from strlen to 0.
//DP cannot be applied since the data cannot be built like this.
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b);
 
void
vPrint( int m[][5] )
{
    for(int i=0; i<6; i++)
    {
    for(int j=0; j<5; j++)
        cout << m[i][j] << "   ";
    cout << endl;
  }
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n, int M[][5] )
{
    vPrint( M );
   if (m == 0 || n == 0)
   {
       return 0;
   }
   
    if( M[m-1][n-1] != -1 ) return M[m-1][n-1];
    
    if (X[m-1] == Y[n-1])
    {   
         M[m-1][n-1] = 1 + lcs(X, Y, m-2, n-2, M);
         return M[m-1][n-1];
    }
    else
    {
      M[m-1][n-1] = max(lcs(X, Y, m-1, n-2, M), lcs(X, Y, m-2, n-1, M));
      return M[m-1][n-1];
    }
}
 
/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Driver program to test above function */
int main()
{
  char X[] = "abcdaf";
  char Y[] = "acbcf";
 
  int m = strlen(X);
  int n = strlen(Y);

  int M[m][5]; 
 
    for(int i=0; i<m; i++ ) M[i][0] = 0;
    for(int j=0; j<n; j++ ) M[0][j] = 0;
  for(int i=1; i<m; i++) 
    for(int j=1; j<n; j++) 
        M[i][j] = -1;
  
  printf("Length of LCS is %d", lcs( X, Y, m, n, M ) );
  cout << endl;
  
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
        cout << M[i][j] << "   ";
    cout << endl;
  }
  return 0;
}