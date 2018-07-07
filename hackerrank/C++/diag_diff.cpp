//Hackerrank.com
// Title: Diagonal Difference
//
// Date: Oct 5, 2016
//
//Given a square matrix of size , calculate the absolute difference between the sums of its diagonals.
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n, iPrD = 0;  //Primary diagonal
    int    iSecD = 0; //Secondary diagonal
    
    cin >> n;
 
    //vector< vector<int> > a(n,vector<int>(n));  //Weird C++ NxN declaration.
    int a[n][n];
    
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
           if( a_i == a_j ){
               iPrD = iPrD + a[a_i][a_j];
           }
           if((a_i + a_j + 1) == n){
               iSecD = iSecD + a[a_i][a_j];
           }
       }
    }
    cout << abs(iPrD - iSecD);
    return 0;
}
