//POSITION: 3
//word
#include <iostream>
#include <string>

using namespace std;

int iFind( string sSource, char cSearch){
    for( int i = 0; i<sSource.length(); i++ ){
        if( sSource[i] == cSearch) return i;
    }
    return -1;
}

string sReplace( string sSource, char cChangeFrom, char cChangeTo ){
    
    int iPos = iFind(sSource,cChangeFrom);
    
    return sSource.substr(0,iPos) + cChangeTo + sSource.substr(iPos+1);
}

int
main()
{
    string s1 = "work";
    char   c  = 'k';
    
    cout << "POSITION: " << iFind(s1,c) << endl;
    
    cout << sReplace( s1, c, 'd') << endl;
    
    return 0;
}