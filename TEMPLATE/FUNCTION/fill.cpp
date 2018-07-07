////////////////////////////////////////////////////////////////////////////////
//  Oct 6, 16
//
// Demonstrates general function using template key word.
//
//OUTPUT
//0  1  2  3  4  5  6  7  8  9  
//0  0  0  0  0  0  0  0  0  0  
//receive  recieve  recieve  receive  
//recieve  recieve  recieve  recieve  
//
// size(), push_back(), methods
// fill(), replace algorithms
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

///////////////////////////////////////////////////
//Can accept any type of vector.
///////////////////////////////////////////////////
template <typename T> void
vDisplay( const vector<T> &vecValues ){
    
    for(int i = 0; i< vecValues.size(); i++){
        cout << vecValues[i] << "  ";
    }
}

int
main()
{
    vector<int> vecNumbers;
    
    for( int i = 0; i < 10; i ++){
        vecNumbers.push_back(i);
    }
    
    vDisplay(vecNumbers);
    cout << endl;
    
    fill( vecNumbers.begin(), vecNumbers.end(), 0);  //Fill 0 in every vector.
    vDisplay(vecNumbers);
    cout << endl;
    
    vector<string> vecString;
    
    vecString.push_back("receive");
    vecString.push_back("recieve");
    vecString.push_back("recieve");
    vecString.push_back("receive");
    
    vDisplay(vecString);
    cout << endl;
    
    
    //Replace a string.
    replace(vecString.begin(), vecString.end(), "receive", "recieve");
    vDisplay(vecString);
    cout << endl;
    
    return 0;
}