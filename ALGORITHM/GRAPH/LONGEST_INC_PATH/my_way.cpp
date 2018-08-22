#include <vector>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

map< pair<int,int>, int > dp;  //Dynamic program storage

pair<int,int> moves[] = {
                            {0,1},   //Right
                            {0,-1},  //Left
                            {1,0},   //Down
                            {-1,0}   //Up
                        };
struct Cell{
    int iRow, iCol, iData, iDist;
};

Cell stPackage( int r, int c, vector<vector<int>>&matrix, int iDist )
{
    Cell stCE;
    
    stCE.iRow  = r;
    stCE.iCol  = c;
    stCE.iData  = matrix[stCE.iRow][stCE.iCol];
    stCE.iDist = iDist;
    
    return stCE;
}

//curr_cell.first refers to row number  So checks for upper and lower bound
//curr_cell.second refers to column number
bool
bDeadEnd( pair<int,int>curr_cell, vector<vector<int>>&matrix)
{
    pair<int, int> temp;
    bool bCanGoUp=true, bCanGoDown=true,   bCanGoLeft=true, bCanGoRight=true;
   
    //if higher cell is either smaller or it is already dynamically memoized, cannot move up.
    if( curr_cell.first -1 >=0 ){
        temp = make_pair( curr_cell.first-1, curr_cell.second) ;
        
        if (( matrix[curr_cell.first][curr_cell.second] > matrix[curr_cell.first-1][curr_cell.second] )  || 
                    dp[temp] !=0 ) 
        bCanGoUp = false;
    }
    //Passed the left boundary.
    else{
        bCanGoUp = false;
    }   
   
    //if lower cell is either smaller or it is already dynamically memoized, cannot move down.
    if( curr_cell.first +1 <=2 ){
        temp = make_pair( curr_cell.first+1, curr_cell.second) ;
        
        if (( matrix[curr_cell.first][curr_cell.second] > matrix[curr_cell.first+1][curr_cell.second] )  || 
                    dp[temp] !=0 ) 
        bCanGoDown = false;
    }
    //Passed the left boundary.
    else{
        bCanGoDown = false;
    } 
   
    //Right boundary
    if( curr_cell.second +1 <=2 ){
        temp = make_pair( curr_cell.first, curr_cell.second + 1) ;
        
        if ( (matrix[curr_cell.first][curr_cell.second] > matrix[curr_cell.first][curr_cell.second+1] )  || 
                    dp[temp] !=0 ) 
        bCanGoRight = false;
    }
    //Passed the down boundary.
    else{
        bCanGoRight = false;
    }   
    
    
    //check left cell is smaller or already dynamically memoized, cannot move left.
    if( curr_cell.second -1 >=0 ){
        temp = make_pair( curr_cell.first, curr_cell.second - 1) ;
        
        if (( matrix[curr_cell.first][curr_cell.second] > matrix[curr_cell.first][curr_cell.second-1] )  || 
                    dp[temp] !=0 ) 
        bCanGoLeft = false;
    }      
    else{
        bCanGoLeft = false;
    }
   
    if( bCanGoDown == false && bCanGoUp == false && bCanGoLeft == false && bCanGoRight == false )
        return true;
    else
        return false;
}

int
iGetHighestDP(pair<int,int>curr_cell, vector<vector<int>>&matrix){
   int iValue1, iValue2, iValue3, iValue4;
   
   pair<int,int> temp;
   
   temp = make_pair(curr_cell.first-1, curr_cell.second);
   if( dp.find(temp) != dp.end() ) iValue1 = dp[temp];
   else iValue1= 0;
   
   temp = make_pair(curr_cell.first+1, curr_cell.second);
   if( dp.find(temp) != dp.end() ) iValue2 = dp[temp];
   else iValue2= 0;
   
   temp = make_pair(curr_cell.first, curr_cell.second-1);
   if( dp.find(temp) != dp.end() ) iValue3 = dp[temp];
   else iValue3= 0;
   
   temp = make_pair(curr_cell.first, curr_cell.second+1);
   if( dp.find(temp) != dp.end() ) iValue4 = dp[temp];
   else iValue4= 0;
   
   return max(iValue1, max(iValue2, max(iValue3, iValue4 ))); 
}
int dfs(vector<vector<int>>&matrix, int r, int c, int n_rows, int n_cols)
{
    pair<int,int> next_cell;
    pair<int,int> curr_cell;
    pair<int,int> orig_cell;
    int iMax = 0;
    
    queue<Cell> Q;
    Cell stCE, stTemp;
    
    stCE = stPackage( r, c, matrix, 1 );
  
    curr_cell = make_pair(r,c);
    orig_cell = curr_cell;
    
    if(dp[curr_cell] != 0 ) return dp[curr_cell];
    
    Q.push(stCE); 
     
    while(!Q.empty()){
         
         int iNumOfPaths = 0;
         //Try right, left, down, up
         for ( int i=0; i<4; ++i ){
             
             next_cell = make_pair(curr_cell.first+moves[i].first, curr_cell.second+moves[i].second); 
             //If within boundary
             if ( 0<=next_cell.first && next_cell.first < n_rows && 0<=next_cell.second && next_cell.second < n_cols ){
                    //Calculate only if dynamic memoization is not available.
                    if( dp[next_cell] == 0 ){
                        //Check the next move is inside the boundary.
                        if ( matrix[next_cell.first][next_cell.second] > matrix[curr_cell.first][curr_cell.second] ){
                           
                           stTemp = Q.front();
                           stCE.iDist = stTemp.iDist + 1;
                           
                           if( stCE.iDist > iMax ) iMax = stCE.iDist;
                           
                           stCE = stPackage( next_cell.first, next_cell.second, matrix, stTemp.iDist+1);
                           
                           Q.push(stCE); 
                           
                           iNumOfPaths++;
                        }       
                    }
                    if( dp[next_cell] != 0 ) 
                    {
                       //Add 1 to already computed distance.
                       //The power of dynamic programming.  Awesome!!!
                        //Only if current cell is dead end.
                        if( bDeadEnd( curr_cell, matrix ) ){
                             dp[curr_cell] = 1 + iGetHighestDP(curr_cell, matrix);
                             iMax = dp[curr_cell];
                             break;
                        }
                    }
                }
         }       
         if (iNumOfPaths == 0 )//No path from this cell. No way out cell. 
         {
            if(dp[curr_cell] == 0 ) dp[curr_cell] = 1;
         }
         Q.pop(); 
         stTemp = Q.front();
         curr_cell = make_pair(stTemp.iRow,stTemp.iCol);
    }
    dp[orig_cell]  = iMax;
    return iMax;

}

int iFindMaxPath( vector<vector<int>> &matrix ){
        
    int rows = matrix.size();
    int cols = matrix[0].size();
    int result = 0;
    int iMax = 0;
    for ( int i=0; i<rows; ++i ){
        for ( int j=0; j<cols; ++j ){
              
            result = dfs(matrix, i,j,rows,cols);
            cout << i << " " << j << ":" << result << endl;
            if(result > iMax) iMax = result;
        }
    }
    cout << "MAX is" << result << endl;                                    
    return iMax;
}
void
vInitMap(vector<vector<int>> &M)
{
    size_t i = M.size();
    size_t j = M[0].size();
    
    for( i=0; i<M.size(); i++)  
        for( j=0; j<M[0].size(); j++){
            pair<int,int> p = make_pair(i,j);
            dp[p] = 0; 
        }
}

int
main(void)
{
    vector<vector<int> > matrix1 = { {3,4,5},
                                    {3,2,6},
                                    {2,2,1}};
    vector<vector<int> > matrix2 = { {9,9,4},
                                    {6,6,8},
                                    {2,1,1}};
    vector<vector<int> > matrix3 = { {1,2,9},
                                    {5,3,8},
                                   {4,6,7}};
    /*
    vInitMap(matrix1);
    cout << iFindMaxPath( matrix1 ) << endl;
    vInitMap(matrix2);
    cout << iFindMaxPath( matrix2 ) << endl;
    */
    vInitMap(matrix3);
    cout << iFindMaxPath( matrix3 ) << endl;
    
    return 0;    
}