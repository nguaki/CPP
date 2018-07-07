//Hackerank
//
//make characters in a string unique.

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
   
    string s, sUniq, sTemp;
    int iEvenCnt, iOddCnt;
    int c[26] = {0};
    cin>>s;
     
    int flag = 0;
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string 
    
    cin >> s;
    
    
    //get uniq chars of s
    //count #of each char.
        
    //if every letter is an even #, it is a palindrome.
    //if just one letter is odd #, it is a pali.
    // otherwise, it is not.
        
    sUniq = s;
    
    //Sort characters within a string.
    sort(sUniq.begin(), sUniq.end());
    //cout << sUniq << endl;
    
    //Make each character unique.
    sUniq.erase(unique(sUniq.begin(), sUniq.end()),sUniq.end());
    //cout << "original str:" << s << endl;
    //cout << "uniq str:" << sUniq << endl;
    
    for( int i=0; i<sUniq.size(); i++){
        for( int j=0; j<s.size(); j++){
            if( sUniq[i] == s[j] )
                c[s[j]-'a']++;
        }  
    }
    
    iEvenCnt = 0;
    iOddCnt = 0;
    for( int i =0; i<26; i++){
        if( c[i] % 2 == 0 ){
            iEvenCnt++;
        } else
            iOddCnt++;
    }
    
    //for( int i =0; i<26; i++){
    //    cout << i << ":" << c[i] << endl;
    //} 
    
    //cout << "Even count: " << iEvenCnt <<endl;
    //cout << "Odd count: " << iOddCnt << endl;

    if( iOddCnt == 0 || iOddCnt == 1 ) flag = 1;
    
    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
