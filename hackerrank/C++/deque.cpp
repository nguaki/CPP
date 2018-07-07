//  Hackerrank 
//  Deque
//
#include <iostream>
#include <deque> 
using namespace std;

//This requires a new way of thinking with a big data.
//Small data works great but not with big data.
//Implementation of new data structure to make this to work is essential.
//In this case implementing dque to make this work is genius.
//This is a genius logic.
//  empty(),
//  arr[i] >= arr[Qi.back()]
//  Qi.push_back(i);
//       cout << arr[Qi.front()] << " ";
//
// Remove the elements which are out of this window
//        while ( (!Qi.empty()) && Qi.front() <= i - k)
//            Qi.pop_front();  // Remove from front of queue

 

void printKMax(int arr[], int n, int k){
   
    deque<int>  Qi(k);
 
    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; ++i)
    {
        // For very element, the previous smaller elements are useless so
        // remove them from Qi
        
        //empty() return true if it is empty
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()]){
            Qi.pop_back();  // Remove from rear
            //cout << "Iam looping" << endl;
            
        }
        // Add new element at rear of queue. 
        // It is adding index of the element, not the actual element.
        //cout << "I am pushing " << i << endl;
        Qi.push_back(i);
    }
    //cout << "biggest number from first window = " << arr[Qi.front()] << endl;
 
    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for ( ; i < n; ++i)
    {
        // The element at the front of the queue is the largest element of
        // previous window, so print it
        cout << arr[Qi.front()] << " ";
 
        // Remove the elements which are out of this window
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();  // Remove from front of queue
 
        // Remove all elements smaller than the currently
        // being added element (remove useless elements)
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
 
         // Add current element at the rear of Qi.  Againg adding index, not the actual element.
        Qi.push_back(i);
    }
 
    // Print the maximum element of last window
    cout << arr[Qi.front()];
    cout << endl;
}
int main(){
  
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}
