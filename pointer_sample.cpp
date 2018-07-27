#include <stdio.h>
#include <stdlib.h>

void
print_array( int *x )
{
    for(int i=0; i<10;i++ )
        printf("%d\n", *x++ );
}

void
assign_array( int ***p )
{
    int i, j, k;
    
    for(i=0; i<10;i++)
        for(j=0; j<10; j++)  
            for(k=0; k<10; k++)
                p[i][j][k] = i*j*k;
}

void
assign_oneDimArray(int *oneDim)
{
    int i;
    for(i = 0; i < 10; i ++ ) oneDim[i] = i;
}
void
assign_twoDimArray(int **twoDim)
{
    
    int i, j;
    for(i = 0; i < 10; i ++ ) 
        for(j = 0; j < 10; j ++ ) 
            twoDim[i][j] = i*j;
    
}
int
main(void)
{
    int i2[5][2] = { { 1, 1 }, {2,2}, {3,3}, {4,4}, {5,5} };
   int i, j, k; 
   
    print_array((int *)&i2 );
    
    
   
   int *oneDim;
   
   oneDim = (int *)malloc( 10 * sizeof(int));
   
   assign_oneDimArray(oneDim);
   for( i = 0; i < 10; i++) printf("%d\n", oneDim[i]);
   
   int **twoDim;
   
   twoDim = (int **)malloc( 10 * sizeof(int *));
    for( i=0; i<10; i++)  twoDim[i] = (int *)malloc( 10 * sizeof(int));
    
   assign_twoDimArray(twoDim);
    for(i = 0; i < 10; i ++ ) 
        for(j = 0; j < 10; j ++ ) 
            printf("%d\n", twoDim[i][j] );
            
    int ***p;
    p = (int ***)malloc( 10 * sizeof(int **));
   
    for( i =0; i<10; i++) 
        p[i] = (int **)malloc( 10 * sizeof(int *));
        
    for( i=0; i<10; i++) 
        for( j = 0; j < 10; j++ ) p[i][j] = (int *)malloc( 10 * sizeof(int));
       
    assign_array( p );
    for( i = 0; i < 10; i++)
        for( j = 0; j<10; j++)
            for( k = 0; k<10; k++)
                printf("%d\n", p[i][j][k]);
    return 0;
}