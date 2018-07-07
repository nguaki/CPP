//Hackerrank
//
//
//8
//1 9
//1 6
//1 10
//1 4
//3 6   <== Find if 6 exists
//3 14
//2 6   <== Erase 6
//3 6   <==  Find if 6 exists
//Sample Output
//
//Yes
//No
//No
//
#include <iostream>
#include <set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    set<int> setN;
    
    cin >> N;
    
    while(N--){
        int Q, iNum;
        
        cin >> Q >> iNum;
        
        switch(Q){
            case 1:
                setN.insert(iNum);
                break;
            case 2:
                setN.erase(iNum);
                break;
            case 3:
        
                cout << ( setN.find(iNum) == setN.end() ? "No":"Yes" )<< endl;  
            /*
            if( iset == setN.end() )
                    cout << "No" << endl;
                else
                    cout << "Yes" << endl;
            */
            break;
            default:
                break;
        }
        
    }
    return 0;
}