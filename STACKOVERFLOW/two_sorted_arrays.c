#include <iostream>
#include <vector>
#include <climits>

using namespace std;

double max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
double min(int a,int b)
{
    if(a>b)
        return b;
    return a;
}
//double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int n = A.size(), m = B.size();
    int start = 0, end = n,i,j;
    double ans;
    while(start<=end)
    {
        i = start + (end - start)/2;
        j = (n+m+1)/2 - i;

        int maxleftA = (i==0)?INT_MIN:A[i-1];
        int maxleftB = (j==0)?INT_MIN:B[j-1];
        int minrightA = (i==n)?INT_MAX:A[i];
        int minrightB = (j==m)?INT_MAX:B[j];

        if(maxleftA<=minrightB && maxleftB<=minrightA)
        {
            if((n+m)%2 == 0)
                return (max(maxleftA,maxleftB) + min(minrightA,minrightB))/2;
            else
                return max(maxleftA,maxleftB);
        }
        else if(maxleftA>minrightB)
            end = i-1;
        else
            start = i+1;
    }
    return -1;
}

int
main()
{
    vector<int> A, B;
    
    
    /*
    A.push_back(1);
    A.push_back(4);
    A.push_back(5);
    B.push_back(2);
    B.push_back(3);
    cout << findMedianSortedArrays(A,B) << endl;
    */
    
    A.clear();
    B.clear();
    A.push_back(-35);
    A.push_back(5);
    A.push_back(11);
    A.push_back(34);
    A.push_back(35);
    
    cout << findMedianSortedArrays(A,B) << endl;

    return 0;
}