//palindrome
// abcba  is plaindrome.  forward and reverse reading are same.
#include <iostream>
#include <string>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, i, iStrLen;
    string str, rStr, tempStr, tempRStr;
    
    cin >> n;
    
    while(n--){
        
        cin >> str;
        
        //reverse a string
        rStr = string ( str.rbegin(), str.rend() );
        //cout << "str:" << str << endl;
        //cout << "reverse:" << rStr << endl;
        iStrLen = str.size();
        

        if( str == rStr ) {
           cout << -1 << endl;
        } else {
            for( i = 0; i < iStrLen; i++ ){
                char c, crv;
                
                //Store the character that will be deleted.
                c   = str[i];
                crv = rStr[iStrLen-i-1];
                               
                //Delete the character.
                str.erase(i, 1);
                rStr.erase(iStrLen-i-1,1);
                
                if( str == rStr ) break;
                
                //Restore back the character.
                str.insert(i, 1, c );
                rStr.insert(iStrLen-i-1, 1, crv );
                
            }
            cout << i << endl;
        }
        
    }
    return 0;
}
