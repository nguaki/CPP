//Hackerrank.com
// Title: Stair Case
//
// Date: Oct 5, 2016
//
//     #
//    ##
//   ###
//  ####
// #####
//######

#include <iostream>

using namespace std;


int main(){
    int n, k;
    char ca[10];
    
    cin >> n;
    for( int i = 1; i <=n; i++ ){
        for( k = 0; k<=(n-i); k++ ){
            ca[k] = ' ';
        }
        k--;
        for( ; k<=n; k++){
            ca[k] = '#';
        }
        ca[n] = '\0';
        cout << ca << endl;
    }
    return 0;
}
