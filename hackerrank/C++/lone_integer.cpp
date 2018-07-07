#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lonelyinteger(const vector <int> &a) {

    int i;
    
    //A loner can be detected by the following logic ...
    for( i=0; i<a.size(); i=i+2){
        if(a[i] != a[i+1]) break;
    }
    
    return a[i];
}

int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    //sort the entire vector
    sort(_a.begin(), _a.end());
    res = lonelyinteger(_a);
    cout << res;
    
    return 0;
}
