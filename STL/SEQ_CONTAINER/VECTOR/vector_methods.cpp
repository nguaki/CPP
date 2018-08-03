///////////////////////////////////////////////////////////////////////////////
// July 7 ,18
//
// Demonstration of various methods of vector class.
// Note that the size of vector is not fixed.
// - push_back() means it will increase its size.
// - resize() dynamically change the size of vector.
// - 2 ways of coping a vector.
//
//OUTPUT
//vector size: 10
//0  10  20  30  40  50  60  70  80  90  
//Adding a new value
//vector size: 11  
//0  10  20  30  40  50  60  70  80  90  150  
//Assignment by copy constructor
//Printing vi1
//0  10  20  30  40  50  60  70  80  90  150  
//Assignment by equal operator
//0  10  20  30  40  50  60  70  80  90  150  
//After resizing
//0  10  20  30  40  50  60  70  80  90  150  0  0  0  0  
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
using namespace std;

int
main(void)
{
    vector <int> vi(10);
    int i;
    
    cout << "vector size: " << vi.size() << endl;
    
    for( i=0; i<vi.size(); i++) vi[i] = i*10;
    
    for( i=0; i<vi.size(); i++) cout << vi[i] << "  ";
    cout << endl;
   
    cout << "Adding a new value"  << endl;
    vi.push_back(150);
    
    cout << "vector size: " << vi.size() << "  ";
    cout << endl; 
    
    for( i=0; i<vi.size(); i++) cout << vi[i] << "  ";
    cout << endl;
    
    cout << "Assignment by copy constructor" << endl;
    vector<int> vi1(vi);
    
    cout << "Printing vi1" << endl;
    for( i=0; i<vi1.size(); i++) cout << vi1[i] << "  ";
    cout << endl;
    
    
    cout << "Assignment by equal operator" << endl;
    vector<int> vi2 = vi;
    for( i=0; i<vi2.size(); i++) cout << vi2[i] << "  ";
    cout << endl;
   
    vi2.resize(15);
    cout<< "After resizing" << endl;
    for( i=0; i<vi2.size(); i++) cout << vi2[i] << "  ";
    cout << endl;
   
    return 0; 
}