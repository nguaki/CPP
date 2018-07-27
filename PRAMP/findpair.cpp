#include <stdio.h>
#include <stdlib.h>

//void findPairsWithGivenDifference( int *arr, size_t arrLength, int k, int **out )
//void findPairsWithGivenDifference( int *arr, size_t arrLength, int k, int out[6][2] )
void findPairsWithGivenDifference( int *arr, size_t arrLength, int k, int ***out )
{
   // your code goes here
   int i, j;
   //int k;
 
  int count = 0;
  
  for(i=0; i<arrLength;i++)
  {
    for(j=0; j<arrLength;j++)
    {
      if( i != j ){
        
        if(arr[i] - arr[j] == k)
        {
            printf("%d - %d\n", arr[i], arr[j]);
            //found[0] = arr[i];
            //found[1] = arr[j];
            out[count][0] = arr[i];
            out[count][1] = arr[j];
            count ++;
        }
        else if( arr[j] - arr[i] == k )
        {
           //printf("%d - %d\n", arr[j], arr[i]);
           out[count][0] = arr[j];
            out[count][1] = arr[i];
           count ++;
        }
            

        
        }
      } 
      
  }
 }


int main() {
  
  int arr[] = { 0,-1, -2, 2, 1};
  int k =1;
 
  int ans1[20][2];
  
  int (*ans)[5];
  
  ans = &ans1;
  
  findPairsWithGivenDifference( arr, sizeof(arr)/sizeof(int), k, &ans);
  return 0;
}