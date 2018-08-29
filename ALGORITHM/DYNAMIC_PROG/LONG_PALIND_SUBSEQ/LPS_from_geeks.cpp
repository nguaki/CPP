#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

// Returns the length of the longest palindromic subsequence in seq
int lps(char *str)
{
   int n = strlen(str);
   int i, j, cl;
   int L[n][n];  // Create a table to store results of subproblems
   int iInterval; 
 
   // Strings of length 1 are palindrome of length 1
   // Initiate the diagonal of a matrix to be 1.
   //This is bottom up approach so it is imperative, this gets
   //initiated.
   for (i = 0; i < n; i++)
      L[i][i] = 1;

    //This keeps track of the gap between starting and ending characters.
    //Remember, we are trying to get the Longest Palindrome with a small gap
    //and let it grow to be full string.
    iInterval = 1;
    
    while( iInterval < n )
    {
        for (i=0; i<n-iInterval+1; i++)
        {
            for (j = i+iInterval; j<n; j++ )
            {
                if (str[i] == str[j] && iInterval == 1)
                    L[i][j] = 2;
                else if (str[i] == str[j])
                    L[i][j] = L[i+1][j-1] + 2;
                else
                    L[i][j] = max(L[i][j-1], L[i+1][j]);
            }
        }
        iInterval++;
    }
 
    return L[0][n-1];
}
 
/* Driver program to test above functions */
int main()
{
    char seq[] = "GEEKS FOR GEEKS";
    int n = strlen(seq);
    printf ("The lnegth of the LPS is %d", lps(seq));
    getchar();
    return 0;
}