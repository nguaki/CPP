//Hackerrank.com
// Title: Circular Array Rotation 
//
// Date: Oct 5, 2016
//

#include <deque>
#include <iostream>
using namespace std;


int main() {
    
    int N, k, q;
    int iANum;
    int iRightMostInt;
    deque<int> dqInt;
   
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    
    cin >> N >> k >> q;
    
    while( N-- ){
        cin >> iANum;
        dqInt.push_back(iANum);
    }

    //Move right most element to left.
    while( k-- ){
        iRightMostInt = dqInt.back();
        dqInt.pop_back();
        dqInt.push_front(iRightMostInt);
    }
        
    while( q-- ){
        int m;
        cin >> m;
        cout << dqInt[m] << endl;
    }
   
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

