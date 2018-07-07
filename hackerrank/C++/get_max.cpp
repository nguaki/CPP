// Hackerrank
//  
// Uses template to get the max value.
//
#include <iostream>
#include <cstdio>
using namespace std;

template <typename T>
T max_of_four( const T &a, const T &b, const T &c, const T &d ){
    T max;
    
    max = a;
    
    if( b > max){
        max = b;
    }
    
    if( c > max){
        max = c;
    }
    
    if( d > max){
        max = d;
    }
    
    return max;
}


int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int ans = max_of_four(a, b, c, d);
    cout << ans;
    return 0;
}
