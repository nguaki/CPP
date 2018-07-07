// Hackerank
//
// Find if a common character between 2 strings.
//
//
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N, iSubExists;
    string sInput1, sInput2, sResult;
    
    cin >> N;
    while(N--){
        
       cin >> sInput1;
       cin >> sInput2;
        
       //cout << sInput1 << endl;
       //cout << sInput2 << endl;
        
       iSubExists = 0;
        
       for( int i = 0; i < sInput1.size(); i++){
           int iPos = sInput2.find_first_of(sInput1[i]);
           if( iPos >= 0 ){
               iSubExists = 1;
               break;
           }
           //for( int j=0; j < sInput2.size() && !iSubExists; j++){
           //    if( sInput1[i] == sInput2[j]){
           //        iSubExists = 1;
           //    }
           //}
       }
       sResult = iSubExists ? "YES" : "NO";
        
       cout << sResult << endl;
    }
    return 0;
}