// Oct 12, 16  
//
// Find a lonely integer. 
// This uses xor operation to get a lonely integer.
//
// The input is pairs of numbers and one number is without a pair.
// e.g.  4 4 5 5 6   
// Above case, 6 is the lonely element.
//
// The concept behind xor is
//    a. 7 ^ 7 = 0  
//    b. commutative property.
//    c. 0 ^ 7 = 7
//
// In the above example,
//  4 ^ 4 ^ 5 ^ 5 ^ 6 = 0 ^ 0 ^ 6 = 0 ^ 6 = 6

#include <iostream>
#include <vector>

using namespace std;

int
main()
{

    int i;
    vector<int> vi;
    do{
        
        cin >> i;
        vi.push_back(i);
    
    }while (i != 0 );
    
    vi.pop_back();  //remove the last entry which is 0.
    
    int iOdd = 0;  //Initialization is very important.
    for( int i = 0;  i<vi.size(); ++i){
        iOdd = iOdd ^ vi[i];
    }
    
    cout << "odd number is " << iOdd; 
    
    return 0;
}