#include<iostream>
using namespace std;

void swap(int &x,int &y)
{
        int temp=x;
        x=y;
        y=temp;
}

int main()
{
    int a,b;
        //Get a and b
    a = 1;
    b = 2;
    swap(a,b);  

    cout << a << "  "  << b << endl;


}