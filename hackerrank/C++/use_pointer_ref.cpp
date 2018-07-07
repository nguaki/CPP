// Hackerrank
//  
// Uses pointer and references to update.
//
#include <iostream>
using namespace std;
/*
//Solution by pointer
void update(int *a,int *b) {
    // Complete this function 
    int iTemp = *a;
    
    *a = *a + *b;
    *b = abs(iTemp - *b);
}
*/
//Solution by reference
void update(int &a,int &b) {
    // Complete this function 
    int iTemp = a;
    
    a = a + b;
    b = abs(iTemp - b);
}

int main() {
    int a, b;
    /**
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
    **/
    int *pa = &a, *pb = &b;
    
    cin >> a >> b;
    update( a, b);
    cout << a << endl << b << endl;

    return 0;
}
