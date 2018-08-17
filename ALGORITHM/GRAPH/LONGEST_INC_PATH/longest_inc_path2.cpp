#include <vector>
#include <iostream>
#include <map>
using namespace std;

map< pair<int,int>, int > dp;  //Dynamic program storage

pair<int,int> moves[] = {
                            {0,1},   //Right
                            {0,-1},  //Left
                            {1,0},   //Down
                            {-1,0}   //Up
                        };

int dfs(vector<vector<int>>&matrix, int r, int c, int n_rows, int n_cols){
    //p is (row,column)
    //p for point?
    pair<int,int> p = make_pair(r,c);
    
    //If out of boundary, return.
    if ( 0 > r || r > n_rows-1 || 0 > c || c > n_cols-1 ) return 0;
    
    //Check if dynamically stored?
    //if ( dp.count(p) ){
    //    return dp[p];
    if ( dp[p] != 0  ){
        return dp[p];
    }
    int mx = 0;
    
    //Try right, left, down, up
    for ( int i=0; i<4; ++i ){
        //Get next row if any
        int next_r = r+moves[i].first;
        //Get next column if any
        int next_c = c+moves[i].second;
         if ( 0<=next_r && next_r < n_rows && 0<=next_c && next_c < n_cols ){
      
            //Check the next move is inside the boundary.
            if ( matrix[next_r][next_c] > matrix[r][c] )
                mx = max(mx, dfs(matrix, next_r, next_c, n_rows, n_cols));
         }
    }
    
    mx++;  //Why add 1?
    dp[p] = mx;
    return mx;
}

int iFindMaxPath( vector<vector<int>> &matrix ){
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    int result = 0;
    for ( int i=0; i<rows; ++i ){
        for ( int j=0; j<cols; ++j ){
            result = max(result, dfs(matrix, i,j,rows,cols));
        }
    }
    //cout << result << endl;                                    
    return result;
}
void
vInitMap(vector<vector<int>> &M)
{
    int i = M.size();
    int j = M[0].size();
    
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
    vInitMap(matrix1);
    cout << iFindMaxPath( matrix1 ) << endl;
    vInitMap(matrix2);
    cout << iFindMaxPath( matrix2 ) << endl;
    vInitMap(matrix3);
    cout << iFindMaxPath( matrix3 ) << endl;
    
    return 0;    
}