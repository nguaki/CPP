//Hackerrank
//
//
// 8  <== # of int
// 1 1 2 2 6 9 9 15
// 4  <== # of Queries
// 1  <== find out if 1 exists.  if it does, which index?
// 4
// 9
// 15
//Sample Output
//
// Yes 1
// No 5
// Yes 6
// Yes 8
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N;
    vector<int> vi;
    int iNum;
 
    cin >> N;
    
    while(N--){
        
        
        cin >> iNum;
        
        vi.push_back(iNum);
        
    }
    
    int iQ;
    
    cin >> iQ;
    
    while(iQ--){
        int  iPos;
        
        cin >> iNum;
        
        vector<int>::iterator low;
        
        //Method 2: No bsearch()
        //Find index of first occurrence.
        low = lower_bound( vi.begin(), vi.end(), iNum ); //low is a pointer.
        
        //if( iNum == vi[low-vi.begin()] ){  //pointer address - pointer address = index
        if( iNum == *low ){  //pointer address - pointer address = index
              cout << "Yes " << low - vi.begin() + 1<< endl; //Get the index
        } else {
              cout << "No " << low - vi.begin() + 1<< endl; 
        }

    }
    return 0;
}
