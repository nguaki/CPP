// Hackerrank.com
// Title : Simple array sum
// Category: C++
//Given an array of  integers, can you find the sum of its elements?

//Input Format

//The first line contains an integer, , denoting the size of the array. 
//The second line contains  space-separated integers representing the array's elements.

//Output Format

//Print the sum of the array's elements as a single integer.

//Sample Input

//6
//1 2 3 4 10 11
//Sample Output

//31
#include <vector>
#include <iostream>

using namespace std;


int main(){
    int n;
    int iSum = 0;
    
    cin >> n;
    
    
    //method 1:
    //This is the simplest solution.
    while(n--){
        int i;
        cin >> i;
        iSum += i;
    }
    cout << iSum;
    
   
    /*
    method 2:
    This method works but it doesn't demonstrate the usage of vector.
   vector<int> arr(n);   <== In order for the this loop to work, arr(n) must be declared otherwise segmentation fault.
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       iSum = iSum + arr[arr_i];
    }
   */
    
    /*
    method 3:
    vector<int> arr;
    for(int arr_i = 0;arr_i < n;arr_i++){
       int iInput;
        cin >> iInput; 
        arr.push_back(iInput);
    }
    
    vector<int>::iterator vit = arr.begin();
    
    while( vit != arr.end()){
        iSum += *vit++;
    }  
    method 4:
    iSum = 0;    
    for( int i = 0; i < arr.size(); i++ ){
        iSum += arr[i];   //Although, vector<int> arr; the subscription is allowed since vector grows with push_back().
    }
    
    method 5:
    iSum= 0;
    for( auto i : arr )
        iSum += i;
    
    cout << iSum;
    */
    return 0;
}
