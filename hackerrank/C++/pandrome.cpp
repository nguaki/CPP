//Pandrome
//
//A string is made up of all 26 alphabets.
#include <cmath>
#include <cstdio>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string str;
    map <char,int> mAlpha; 
    
    //cin >> str;
    getline(cin, str);
    //cout << str << endl;
    for( auto c: str ){
        c = tolower(c);
        //cout << c << endl;
        if( isalpha(c))
            mAlpha[c] = 1;
    }
    
    map<char,int>::iterator itAlpha = mAlpha.begin();//Iterator
    
    while( itAlpha != mAlpha.end()){
        //cout << itAlpha->first << " " << itAlpha->second << endl;
        itAlpha++;
    }

    //cout << mAlpha.size() << endl;
    
    if(mAlpha.size() == 26)
        cout << "pangram" << endl;
    else
        cout << "not pangram" << endl;
    return 0;
}
