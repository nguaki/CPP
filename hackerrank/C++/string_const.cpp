//  string_const.cpp
//
#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

//this question explanation sounds more difficult as it really 
//is.
//
// abab can be obtained from
// aba   <== add 'a' substr   (cost = free)
// abab  <== add 'b' substr   (cost = free)
//
// abab  doesn't need to add 'ab' which makes algo very complex.
int main(){
    int n;
    string p, tempStr;
    int iTryCnt = 0, iSubStrCnt;
    int i;
    typedef vector<string> stringContainer;
	typedef stringContainer::iterator stringIterator;
    stringContainer vSubStr;
    stringIterator sI;

    cin >> n;
    while( n-- ){
        string s;
        cin >> s;
        
        //p = s.substr(0,1);
        //cout << "p: " << p << endl;
        iTryCnt = 0;
        //sMatch = 0;
        
        for( i = 0; i < s.size(); i ++ ){               
            //if new character is not yet in vector.
            tempStr = s.substr(i,1);
            //cout << "orig char:" << tempStr << endl;
            
            //Find a character from a vector.
            sI =  find( vSubStr.begin(), vSubStr.end(), tempStr);
            
            //If a new character
            if( sI == vSubStr.end() ) {
                    //Concat a new character
                    p = p + tempStr;
                    //Add try count.
                    iTryCnt++;
                    //Add a character to a vector.
                    vSubStr.push_back(tempStr);
             } else {
                //If it is from vector set, add from a vector.
                p.append(*sI);
             }
            //cout << "p = " << p << endl;
         }
         //clear string
         p.clear();     
         //clear vector
         vSubStr.clear();
         cout << iTryCnt << endl; 
    }
    
    return 0;
}
