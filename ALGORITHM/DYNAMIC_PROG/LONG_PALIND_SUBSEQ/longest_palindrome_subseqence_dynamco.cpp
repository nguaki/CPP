//This needs work!!!
//Trying to implement dynamic programming but giving out wrong answer.
#include<iostream>
#include<stdio.h>
#include<string.h>
 
using namespace std;

// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }
 
void
vPrint(int iaDS[][14])
{
    for( int i=0; i<14; i++){
        
        for( int j=0; j<14; j++)
            cout << iaDS[i][j] << " ";
        cout << endl;
    }
} 
// Returns the length of the longest palindromic subsequence in seq
int lps(char *seq, int i, int j, int iaDS[][14])
{
   vPrint(iaDS);
   
   // Base Case 1: If there is only 1 character
   if (i == j)
   {
       iaDS[i][j] = 1;
       return 1;
   } 
   // Base Case 2: If there are only 2 characters and both are same
   if (seq[i] == seq[j] && i + 1 == j)
   {
       iaDS[i][j] = 1;
        return 2;
   } 
   if (iaDS[i][j] != 0 ) return iaDS[i][j];
   
   // If the first and last characters match
   if (seq[i] == seq[j])
   {
      iaDS[i][j] = lps(seq, i+1, j-1, iaDS) + 2;
      return iaDS[i][j];
   } 
   // If the first and last characters do not match
   iaDS[i][j] = max( lps(seq, i, j-1, iaDS), lps(seq, i+1, j, iaDS) );
   return  iaDS[i][j];
}
 
/* Driver program to test above functions */
int main()
{
    char seq[] = "GEEKSFORGEEKS";
    int n = strlen(seq);
    int iaDS[14][14];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        iaDS[i][j] = 0;
        
   vPrint(iaDS);
    printf ("The length of the LPS is %d", lps(seq, 0, n-1, iaDS));
    getchar();
    return 0;
}