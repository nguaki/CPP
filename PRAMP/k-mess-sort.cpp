#include <iostream>
#include <vector>

using namespace std;

//void printArray(int arr[], int size);
// Prototype of a utility function to swap two integers
void swap(int *x, int *y);


// A class for Min Heap
class MinHeap
{
    //int *harr; // pointer to array of elements in heap
    vector<int> harr;
    int heap_size; // size of min heap
public:
    // Constructor
    MinHeap(vector<int> &a, int size);
 
    // to heapify a subtree with root at given index
    void MinHeapify(int );
 
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
 
    // to remove min (or root), add a new value x, and return old root
    int replaceMin(int x);
 
    // to extract the root which is the minimum element
    int extractMin();
};
 

 
// FOLLOWING ARE IMPLEMENTATIONS OF STANDARD MIN HEAP METHODS FROM CORMEN BOOK
// Constructor: Builds a heap from a given array a[] of given size
//MinHeap::MinHeap(int a[], int size)
MinHeap::MinHeap(vector<int> &a, int size)
{
    heap_size = size;
    harr = a;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}
 
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    int root = harr[0];
    if (heap_size > 1)
    {
        harr[0] = harr[heap_size-1];
        heap_size--;
        MinHeapify(0);
    }
    return root;
}
 
// Method to change root with given value x, and return the old root
int MinHeap::replaceMin(int x)
{
    int root = harr[0];
    harr[0] = x;
    if (root < x)
        MinHeapify(0);
    return root;
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

vector<int> sortKMessedArray( const vector<int>& arr, int k ) 
{
  // your code goes here
  int n = arr.size();
  cout << "size " << n << endl;
  
     //int *harr = new int[k+1];
    vector<int> harr;
    vector<int> arr1 = {};
  //arr1 = arr;
  
  for (int i = 0; i<=k && i<n; i++) // i < n condition is needed when k > n
       // harr[i] = arr[i];
        harr.push_back(arr[i]);
    MinHeap hp(harr, k+1);
 
    // i is index for remaining elements in arr[] and ti
    // is target index of for cuurent minimum element in
    // Min Heapm 'hp'.
    for(int i = k+1, ti = 0; ti < n; i++, ti++)
    {
        // If there are remaining elements, then place
        // root of heap at target index and add arr[i]
        // to Min Heap
        if (i < n)
          //arr1[ti] = hp.replaceMin(arr[i]);
          arr1.push_back(hp.replaceMin(arr[i]));
 
        // Otherwise place root at its target index and
        // reduce heap size
        else
            //arr1[ti] = hp.extractMin();
            arr1.push_back(hp.extractMin());
    }

  return arr1;
}
 
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
// Driver program to test above functions
int main()
{
    int k = 3;
    vector<int> vInt = {2, 6, 3, 12, 56, 8};
    vector<int> vAnswer;
    
    //int n = vInt.size();
    vAnswer = sortKMessedArray(vInt, k);
 
    cout << "Following is sorted array:\n";
    //printArray (arr, n);
  for(int i=0; i<vAnswer.size();i++) cout << vAnswer[i] << endl;
    return 0;
}