//Now the root node has the maximum value.
//Mimics Heap binary tree in a form of a vector.
//Remember that the minimum heap tree is established when parent node is less than 
//its children nodes.
//
#include <iostream>
#include <vector>

using namespace std;

//void printArray(int arr[], int size);
// Prototype of a utility function to swap two integers
//void swap(int *x, int *y);
void swap(int &x, int &y);


// A class for Min Heap
class MaxHeap
{
    //int *harr; // pointer to array of elements in heap
    vector<int> harr;
    int heap_size; // size of min heap
public:
    // Constructor
    MaxHeap(vector<int> &a, int size);
 
    // to heapify a subtree with root at given index
    void MaxHeapify(int );
 
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
 
    // to remove min (or root), add a new value x, and return old root
    int replaceMax(int x);
 
    // to extract the root which is the minimum element
    int extractMax();
};
 

 
// FOLLOWING ARE IMPLEMENTATIONS OF STANDARD MIN HEAP METHODS FROM CMEN BOOK
// Constructor: Builds a heap from a given array a[] of given size
//MinHeap::MinHeap(int a[], int size)
MaxHeap::MaxHeap(vector<int> &a, int size)
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
 
// Method to remove minimum element (or root) from min heap
// Restore the Min heap by placing the lowest number at the root.
int MaxHeap::extractMax()
{
    int root = harr[0];
    if (heap_size > 1)
    {
        harr[0] = harr[heap_size-1]; //Question:Not sure why the last node is set to root???
        heap_size--;
        MaxHeapify(0);
    }
    return root;
}
 
// Method to change root with given value x, and return the old root
int MaxHeap::replaceMax(int x)
{
    int root = harr[0];
    harr[0] = x;
    if (root > x)
        MaxHeapify(0);
    return root;
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
//Since this is Minimum Heap using the Vector Data structure,
//0th index must have the minimum number.
void MaxHeap::MaxHeapify(int iIndex)
{
    int LeftIndex = left(iIndex);
    int RightIndex = right(iIndex);
    int largestIndex = iIndex;
    if (LeftIndex < heap_size && harr[LeftIndex] > harr[largestIndex])
        largestIndex = LeftIndex;
    if (RightIndex < heap_size && harr[RightIndex] > harr[largestIndex])
        largestIndex = RightIndex;
    if (largestIndex!= iIndex)
    {
        swap(harr[largestIndex], harr[iIndex]);
        MaxHeapify(largestIndex);
    }
}

vector<int> sortKMessedArray( const vector<int>& arr, int k )
{
    // your code goes here
    int n = arr.size();
    cout << "size " << n << endl;
  
    vector<int> harr;
    vector<int> sorted_arr = {};
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
        if (i < n)
          //Push back the minimum from a b-tree.
          //Adjust the Min heap tree.
          sorted_arr.push_back(hp.replaceMax(arr[i]));
 
        // Otherwise place root at its target index and
        // reduce heap size
        else
            //Extract the minimum value and readjusts heap.
            sorted_arr.push_back(hp.extractMax());
    }

  return sorted_arr;
}
 
/*
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    
}
*/

// A utility function to swap two elements
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
// Driver program to test above functions
int main()
{
    int k = 2;
    vector<int> vInt = {12, 56, 2, 6, 8, 3};
    vector<int> vAnswer;
    
    //int n = vInt.size();
    vAnswer = sortKMessedArray(vInt, k);
 
    cout << "Following is sorted array:\n";
    //printArray (arr, n);
    
    for(int i=0; i<vAnswer.size();i++) cout << vAnswer[i] << endl;
    
    return 0;
}