//Aug 6, 2018
//
//Finding K-highest elements.
//Specifically K-highest distances from origin.
//
// 1. Create N objects of a class called Points in a form of a vector.
// 2. sort this vector.
//
// Must know how to creat a class with constructor.
// Must know how to instantiate N objects at once using {} operator.
// Must know how to sort a vector especially the usage of the compare function.
// Must know how the iterator works.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

class Points{
    private:
        int ix, iy;
        float fD;
    public:
        float getfD(){ return fD; }
        Points(int ix, int iy ){
            this->ix = ix;
            this->iy = iy;
            fD = sqrt( pow(ix,2) + pow(iy,2));
        }
};
// A class for Min Heap
class MaxHeap
{
    //int *harr; // pointer to array of elements in heap
    vector<Points> harr;
    int heap_size; // size of min heap
public:
    // Constructor
    MaxHeap(vector<Points> &a, int size);
 
    vector<Points> getharr(){ return harr; };
    
    // to heapify a subtree with root at given index
    void MaxHeapify(int );
 
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
 
    // to remove min (or root), add a new value x, and return old root
    void replaceMax(Points x);
 
    // to extract the root which is the minimum element
    Points extractMax();
};

MaxHeap::MaxHeap(vector<Points> &a, int size)
{
    heap_size = size;
    harr = a;  // store address of array
    int i = (heap_size - 1)/2; //Question:What if the calculation is a non-integer number?
                               //I don't understand why the index starts at the middle and
                               //goes to the root.
    while (i >= 0)
    {
        MaxHeapify(i);
        i--;
    }
}
 
Points MaxHeap::extractMax()
{
    Points root = harr[0];
    if (heap_size > 1)
    {
        harr[0] = harr[heap_size-1]; //Question:Not sure why the last node is set to root???
        heap_size--;
        MaxHeapify(0);
    }
    return root;
}
  
void MaxHeap::replaceMax(Points x)
{
    //Points root = harr[0];
    //harr[0] = x;
    if ( x.getfD() > harr[heap_size-1].getfD())
        swap(harr[heap_size-1], x);
        MaxHeapify(0);
    //return root;
}

void MaxHeap::MaxHeapify(int iIndex)
{
    int LeftIndex = left(iIndex);
    int RightIndex = right(iIndex);
    int largestIndex = iIndex;
    if (LeftIndex < heap_size && harr[LeftIndex].getfD() > harr[largestIndex].getfD())
        largestIndex = LeftIndex;
    if (RightIndex < heap_size && harr[RightIndex].getfD() > harr[largestIndex].getfD())
        largestIndex = RightIndex;
    if (largestIndex!= iIndex)
    {
        swap(harr[largestIndex], harr[iIndex]);
        MaxHeapify(largestIndex);
    }
}

// A utility function to swap two elements
void swap(Points &x, Points &y)
{
    Points temp = x;
    x = y;
    y = temp;
}
vector<Points> sortKMessedArray( const vector<Points>& arr, int k )
{
    // your code goes here
    int n = arr.size();
    cout << "size " << n << endl;
  
    vector<Points> harr;
    vector<Points> sorted_arr = {};
    //arr1 = arr;
  
    for (int i = 0; i<=k && i<n; i++) // i < n condition is needed when k > n
       // harr[i] = arr[i];
        harr.push_back(arr[i]);
   
    MaxHeap hp(harr, k+1);//Why +1?
    
    // i is index for remaining elements in arr[] and ti
    // is target index of for cuurent minimum element in
    // Min Heapm 'hp'.
    for(int i = k+1, ti = 0; ti < n; i++, ti++)
    {
        // If there are remaining elements, then place
        // root of heap at target index and add arr[i]
        // to Min Heap
        //if (i < n)
          //Push back the minimum from a b-tree.
          //Adjust the Min heap tree.
          //sorted_arr.push_back(hp.replaceMax(arr[i]));
          hp.replaceMax(arr[i]);
 
        // Otherwise place root at its target index and
        // reduce heap size
        //else
            //Extract the minimum value and readjusts heap.
            //sorted_arr.push_back(hp.extractMax());
    }

  return hp.getharr();
}
 
int
main(void)
{
    Points  pts[5]{ Points(1,1), Points(2,2), Points(3,3), Points(4,4), Points(5,5) };
    vector <Points> vP;
    
    int i;
    int k_highest;
    
    for( i=0; i<5; i++ ) vP.push_back(pts[i]);
    
    //sort(vP.begin(), vP.end(), comparePoints );   //This didn't work.
    //Sorts ascending order.
    sort(vP.begin(), vP.end(), [](Points a,Points b){ return (a.getfD()<b.getfD());});
    
    for( auto &it : vP ) cout << it.getfD() << endl;
    
    cout << "Enter K for highest K elements:";
    cin >> k_highest;
   
    i = 0; 
    
    //Start from the end;
    auto it = vP.rbegin();
    
    cout << "Using sort algorithm "<< endl;
    
    while( i<k_highest ){
        cout << it->getfD() << endl;
        i++;
        it++;//C++ is smart enough for the direction.
    } 
    
    Points  ptsA[5]{ Points(1,1), Points(2,2), Points(3,3), Points(4,4), Points(5,5) };
    vector <Points> vPA;
    
    for( i=0; i<5; i++ ) vPA.push_back(ptsA[i]);
 
    vector<Points> vAnswerA;
    
    //int n = vInt.size();
    vAnswerA = sortKMessedArray(vPA, k_highest);
 
    cout << "Following is sorted array using max heap sort:\n";
    //printArray (arr, n);
    
    for(int i=0; i<vAnswerA.size();i++) cout << vAnswerA[i].getfD() << endl;

    return 0;
}