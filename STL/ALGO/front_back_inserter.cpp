////////////////////////////////////////////////////////////////////////////////////////////
//Oct 6, 2016
//
//Demonstration of copy() function.
//
//OUTPUT
//1  2  3  4  5  6                                                                                                         
//6  5  4  3  2  1  
//
//Uses copy(  ,  ,  front_inserter())
// and copy(  ,  ,  back_inserter())
//to copy data from vector to vector and also
//             from vector to deque.
//
////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

//
//Uses template to input different type of inputs for vector data.
//
template <typename T>
void 
vDisplay(const vector<T> &vcValues){
    
    for(int i=0; i<vcValues.size();i++){
        cout << vcValues[i] << "  ";
    }
    cout << endl;
}

//
//Uses template to input different type of inputs for vector data.
//
template <typename T>
void 
vDisplayDeq(const deque<T> &deqValues){
    
    for(int i=0; i<deqValues.size();i++){
        cout << deqValues[i] << "  ";
    }
    cout << endl;
}

int 
main()
{
    vector<int>  vecValues1;
    
    vecValues1.push_back(1);
    vecValues1.push_back(2);
    vecValues1.push_back(3);
  
    vector<int>  vecValues2;
    
    vecValues2.push_back(4);
    vecValues2.push_back(5);
    vecValues2.push_back(6);


    //Current vecValues1: 1 2 3
    //back_inserter adds 4 5 6 to 1 2 3 in the back side.
    //So it becomes 1 2 3 4 5 6.
    //This is how to read this function:
    //Copy vecValues2 to the back of vecValues1.
    copy( vecValues2.begin(), vecValues2.end(), back_inserter(vecValues1));
    vDisplay(vecValues1);
    
    deque<int> deqValue2;
    deqValue2.push_front(1);
    deqValue2.push_front(2);
    deqValue2.push_front(3);
    
    //Current deqValue2: 3 2 1
    //front_inserter adds 4 5 6 to the front.
    //It becomes 6 5 4 3 2 1
    //Copy vecValue2 to the front of deqValue2.
    copy( vecValues2.begin(), vecValues2.end(), front_inserter(deqValue2));

    vDisplayDeq(deqValue2);
    return 0;
}
