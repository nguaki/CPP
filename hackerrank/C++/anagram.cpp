//Hackerrank
//
//anagram
// If 1st string can be rearrange to be 2nd string, it is considered anagram.
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string s1, s2;
    
    cin >> s1;
    cin >> s2;
    
    for(int i = 0; i < s1.size(); i++ ){
                
         char c = s1[i];
         int iPos = s2.find_first_of(c);       
                
          //If a character is found in s2. 
          //The position can be ZERO.
          if( iPos >= 0){
               s1.erase(i,1);
               i--;
               s2.erase(iPos,1);
           }
    }    
    cout << s1.size() + s2.size() << endl;
    
    return 0;
}