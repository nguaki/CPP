// reverse_string.cpp
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    string str, rStr;
    int iCnt, i, iStrLen;
    
    cin >> n;
    
    while(n--){
        cin >> str;
        
        rStr = string( str.rbegin(), str.rend() );
        
        //cout << "str: " << str << endl;
        //cout << "rstr: " << rStr << endl;
        
        iStrLen = str.size();
        iCnt = 0;
        if( str == rStr ){
            cout << 0 << endl;
        } else {
            for( i = 0; i < iStrLen; i++ ){
                
                //cout << "comparing: " << str[i] << endl;
                //cout << "with: " << rStr[i] << endl;
                
                //Comparing character to character
                while( str[i] != rStr[i] ){
                    if( str[i] > rStr[i]){
                        str[i] = str[i] - 1;
                        //Decrement character:  b -> a
                        rStr[iStrLen-i-1] = rStr[iStrLen-i-1] - 1;
                        
                    }else{
                        rStr[i] = rStr[i] -1;
                        str[iStrLen-i-1] = str[iStrLen-i-1] - 1;
                    }
                    iCnt++;
                    
                }
                
                
            }
            cout << iCnt << endl;
        }
        
    }
    return 0;
}