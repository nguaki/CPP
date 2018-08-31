//Date: Aug 3, 2018
//
//Using CPP's reference variables, rather than pointers.
//By including <cstdio> which is C++ version of C <stdio.h>
//we can use bool type which makes my life so much easier.
//
//Compilation:  g++ Sudoku4By4_CPP.cpp

#include <cstdio>

#define N           4
#define SIZE        2  
#define UNDEFINED   0
#define TRUE        1
#define FALSE       0

void vPrintFinal(int SUDOKU_MATRIX[N][N]);

bool bMatrixIsComplete( int SUDOKU_MATRIX[N][N], int &iRow, int &iCol );

bool bFillInUndefined(int SUDOKU_MATRIX[N][N]);

bool sSafeToAssign( int SUDOKU_MATRIX[N][N], int iRow, int iCol, int iNum );

bool bCheckBoxIfNumAlreadyExists( int SUDOKU_MATRIX[N][N], int iRow, int iCol, int iNum );
bool bCheckColumnIfNumAlreadyExists( int SUDOKU_MATRIX[N][N], int iCol, int iNum );
bool bCheckRowIfNumAlreadyExists( int SUDOKU_MATRIX[N][N], int iRow, int iNum );

bool
bFillInUndefined(int SUDOKU_MATRIX[N][N])
{
   int iNum, iRow, iCol;
   
   if( bMatrixIsComplete( SUDOKU_MATRIX, iRow, iCol ) == true )
        return true;
        
   for( iNum=1; iNum<=N; iNum++ )
   {
       if( bSafeToAssign( SUDOKU_MATRIX, iRow, iCol, iNum ) == true )
       {
           SUDOKU_MATRIX[iRow][iCol] = iNum;
           printf("In Progress\n");
           vPrintFinal(SUDOKU_MATRIX);
           printf("Recursive calling\n" );
           if( bFillInUndefined( SUDOKU_MATRIX ) == true )
                return 1;
           SUDOKU_MATRIX[iRow][iCol] = UNDEFINED;
       }
   }
   printf("Back tracing\n");
   return 0; //Triggers backtracing.
}

bool
bMatrixIsComplete( int SUDOKU_MATRIX[N][N], int &iRow, int &iCol )
{
    int i, j;
    
    for( i = 0; i < N; i ++ )
        for( j = 0; j < N; j ++ )
        {
            if( SUDOKU_MATRIX[i][j] == UNDEFINED )
            {
                iRow = i;
                iCol = j;
                return 0;
            }
        }
    return 1;
}

//Checks if a number already exists in a row.
//OUTPUT:
bool
bCheckRowIfNumAlreadyExists( int SUDOKU_MATRIX[N][N], int iRow, int iNum )
{
    int iCol;
    
    for( iCol = 0; iCol < N; iCol ++ )
        if( SUDOKU_MATRIX[iRow][iCol] == iNum )
            return 1;
    return 0;
    
}

bool
bCheckColumnIfNumAlreadyExists( int SUDOKU_MATRIX[N][N], int iCol, int iNum )
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
bool
bCheckBoxIfNumAlreadyExists( int SUDOKU_MATRIX[N][N], int iRow, int iCol, int iNum )
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
                return true;
    return false;
    
}

//OUTPUT
//   1 : Can assign 
bool 
bSafeToAssign( int SUDOKU_MATRIX[N][N], int iRow, int iCol, int iNum )
{
    if( bCheckRowIfNumAlreadyExists( SUDOKU_MATRIX, iRow, iNum ) == true  ||
            bCheckColumnIfNumAlreadyExists( SUDOKU_MATRIX, iCol, iNum ) == true  ||
                bCheckBoxIfNumAlreadyExists( SUDOKU_MATRIX, iRow - iRow%(N/SIZE), iCol - iCol%(N/SIZE), iNum ) == true )
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

    bFillInUndefined(SUDOKU_MATRIX);
   
    vPrintFinal(SUDOKU_MATRIX);
    
    return 0;
}