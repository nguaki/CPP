// Hackerank
//
// Demonstrates vector erase() method.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N;
    vector<int> vi;
    cin >> N;
    
    while( N-- ){
        int iNum;
        
        cin >> iNum;
        vi.push_back(iNum);
    }
    
    int iEraseIndex;
    cin >> iEraseIndex;
    //cout << "iEraseNum:" << iEraseIndex << endl;
    int iLowBound, iHighBound;
    cin >> iLowBound;
    cin >> iHighBound;
    //cout << "iLowBound:" << iLowBound << endl;
    //cout << "iHBoighund:" << iHighBound << endl;
    
     vi.erase(vi.begin()+iEraseIndex-1); //Must negate one since the vector index starts with 0.
      //for( int i=0; i<vi.size(); ++i)
      //  cout << vi[i] << " ";
      //cout << "size = " << vi.size() << endl;

   
     vi.erase(vi.begin()+iLowBound-1, vi.begin()+iHighBound-1);   //Must negate one since vector index starts with 0.
                                                                  //Remember that high bound is not included.
    
     cout << vi.size() << endl;
     
     for( int i=0; i<vi.size(); ++i){
        cout << vi[i] << " ";
    }
    return 0;
}
