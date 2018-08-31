//Aug 31, 2018
//Can removal of one character make a string balanced?
//
#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

void
vCanOneCharDoMagic( string s )
{
    unordered_map<char, int>  um;
    
    for(int i=0; i<s.size(); i++)
        um[s[i]]++;
        
    int iMin = INT_MAX;
    int iMax = INT_MIN;
    int iDiff; 
     
    for(int i=0; i<s.size(); i++){
        iMin = min(iMin, um[s[i]]);
        iMax = max(iMax, um[s[i]]);
    }

    //cout << "MIN: " << iMin << "   MAX:" << iMax << endl;
   
    iDiff = abs(iMin-iMax);
    //cout << "ABS: " << iDiff << endl;
    
    if (iDiff != 1 ) cout << "Cannot do it \n";
    
    int iMinCnt = 0;
    int iMaxCnt = 0;
    
    string uniqChar = s;
    
    
    sort(uniqChar.begin(), uniqChar.end());
    //cout <<uniqChar<<endl;
   
    for(int i=0; i<uniqChar.size()-1;i++) 
        if( uniqChar[i] == uniqChar[i+1]) 
            uniqChar.erase(uniqChar.begin()+i);
       
    //cout << uniqChar << endl;
    char cMagicChar1, cMagicChar2;
    
    for(int i=0; i<uniqChar.size(); i++){
        if (um[uniqChar[i]] == iMin){
            cMagicChar1 = uniqChar[i];
            iMinCnt++;
        }
        else if (um[uniqChar[i]] == iMax){
            cMagicChar2 = uniqChar[i];
            iMaxCnt++;
        }
        else {
            cout << "Cannot do it" << endl;
        }
    }
    
    if (iMinCnt == 1 )
        cout << cMagicChar1 << " is the magic char.\n";
    else if(iMaxCnt == 1)
        cout << cMagicChar2 << " is the magic char.\n";
    else cout << "Cannot do it" << endl;
    
}

int
main(void)
{
    string s = "xyyz";
    
    vCanOneCharDoMagic( s );
    
    s = "xxyzz";
    vCanOneCharDoMagic( s );
    s = "abcdeefgh";
    vCanOneCharDoMagic( s );
    s = "aabbccddeffgghhii";
    vCanOneCharDoMagic( s );
    
    return 0;
}