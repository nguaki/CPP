//Compilation: g++ Sudoku.cpp
//Reference variables didn't work.
//Had to use pointers.
//Also, bool type didn't work.

#include <stdio.h>
#include <assert.h>

#define N           4
#define SIZE        2  
#define UNDEFINED   0
#define TRUE        1
#define FALSE       0

void vPrintFinal(int SUDOKU_MATRIX[N][N]);

short sMatrixIsComplete( int SUDOKU_MATRIX[N][N], int *iRow, int *iCol );

short sFillInUndefined(int SUDOKU_MATRIX[N][N]);

short sSafeToAssign( int SUDOKU_MATRIX[N][N], int iRow, int iCol, int iNum );

short sCheckBoxIfNumAlreadyExists( int SUDOKU_MATRIX[N][N], int iRow, int iCol, int iNum );
short sCheckColumnIfNumAlreadyExists( int SUDOKU_MATRIX[N][N], int iCol, int iNum );
short sCheckRowIfNumAlreadyExists( int SUDOKU_MATRIX[N][N], int iRow, int iNum );

short
sFillInUndefined(int SUDOKU_MATRIX[N][N])
{
   int iNum, iRow, iCol;
  
  //Always there must be a baseline in recursive function.
   if( sMatrixIsComplete( SUDOKU_MATRIX, &iRow, &iCol ) == 1 )
        return 1;
        
   for( iNum=1; iNum<=N; iNum++ )
   {
       if( sSafeToAssign( SUDOKU_MATRIX, iRow, iCol, iNum ) == 1 )
       {
           SUDOKU_MATRIX[iRow][iCol] = iNum;
           printf("In Progress\n");
           vPrintFinal(SUDOKU_MATRIX);
           printf("Recursive calling\n" );
           //////////////////////////////////////////////////
           //Checks if every position of the matrix is filled.
           //sFillInUndefined() will return 1 only if every matrix
           //is filled.
           //////////////////////////////////////////////////
           if( sFillInUndefined( SUDOKU_MATRIX ) == 1 )
                return 1;
           //Must undo the previous setup since the number didn't work out.
           //This line gets executed when the recursive call returns 0.
           //It is actually continuation of return 0 at the end of this 
           //function.
           SUDOKU_MATRIX[iRow][iCol] = UNDEFINED;
       }
   }
   printf("Back tracing\n");
   return 0; //Triggers backtracing.
}

short
sMatrixIsComplete( int SUDOKU_MATRIX[N][N], int *iRow, int *iCol )
{
    int i, j;
    
    for( i = 0; i < N; i ++ )
        for( j = 0; j < N; j ++ )
        {
            if( SUDOKU_MATRIX[i][j] == UNDEFINED )
            {
                *iRow = i;
                *iCol = j;
                return 0;
            }
        }
    return 1;
}

//Checks if a number already exists in a row.
//OUTPUT:
short
sCheckRowIfNumAlreadyExists( int SUDOKU_MATRIX[N][N], int iRow, int iNum )
{
    int iCol;
    
    for( iCol = 0; iCol < N; iCol ++ )
        if( SUDOKU_MATRIX[iRow][iCol] == iNum )
            return 1;
    return 0;
    
}

short
sCheckColumnIfNumAlreadyExists( int SUDOKU_MATRIX[N][N], int iCol, int iNum )
{
    int iRow;
    
    for( iRow = 0; iRow < N; iRow ++ )
        if( SUDOKU_MATRIX[iRow][iCol] == iNum )
            return 1;
    return 0;
}

// OUTPUT:
//    0   if no such number is present.
//        this means that a new number can be assigned.
//    1   if such number is present.
//        this means that a new number cannot be assigned.
short
sCheckBoxIfNumAlreadyExists( int SUDOKU_MATRIX[N][N], int iRow, int iCol, int iNum )
{
    int i, j;
    
    /*
    for( i = 0; i < N/2; i++ )
        for( j = 0; j < N/2; j++ )
            if( SUDOKU_MATRIX[i][j] == iNum )
                return 1;
    return 0;
    */
    for( i = iRow; i < (iRow+SIZE); i++ )
        for( j = iCol; j < (iCol+SIZE); j++ )
            if( SUDOKU_MATRIX[i][j] == iNum )
                return 1;
    return 0;
    
}

// Checks if the number is assignable at (iRow,iNum)
//OUTPUT
//   1 : Can assign 
short 
sSafeToAssign( int SUDOKU_MATRIX[N][N], int iRow, int iCol, int iNum )
{
    if( sCheckRowIfNumAlreadyExists( SUDOKU_MATRIX, iRow, iNum ) == 1  ||
            sCheckColumnIfNumAlreadyExists( SUDOKU_MATRIX, iCol, iNum ) == 1  ||
                sCheckBoxIfNumAlreadyExists( SUDOKU_MATRIX, iRow - iRow%(N/SIZE), iCol - iCol%(N/SIZE), iNum ) == 1 )
    return 0;
    
    return 1;
}

void
vPrintFinal(int SUDOKU_MATRIX[N][N])
{
    int iRow, iCol;
    
    for( iRow = 0; iRow < N; iRow++ )
    {
        for( iCol = 0; iCol < N; iCol++ )
            printf("%d    ", SUDOKU_MATRIX[iRow][iCol] );
        printf("\n");
    }        
}

int
main(void)
{
    int SUDOKU_MATRIX[N][N] = { 
                                {1, 0, 3, 0 },
                                {0, 0, 2, 1 },
                                {0, 1, 0, 2 },
                                {2, 4, 0, 0 }
                                              };

    sFillInUndefined(SUDOKU_MATRIX);
   
    vPrintFinal(SUDOKU_MATRIX);
    
    assert( SUDOKU_MATRIX[0][1] == 2 );
    assert( SUDOKU_MATRIX[0][3] == 4 );
    assert( SUDOKU_MATRIX[1][0] == 4 );
    assert( SUDOKU_MATRIX[1][1] == 3 );
    assert( SUDOKU_MATRIX[2][0] == 3 );
    assert( SUDOKU_MATRIX[2][2] == 4 );
    assert( SUDOKU_MATRIX[3][2] == 1 );
    assert( SUDOKU_MATRIX[3][3] == 3 );
    
    return 0;
}