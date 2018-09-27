//Sep 26, 2018
//explicit keyword causes compilation error:
//error: conversion from ‘int’ to non-scalar type ‘FOO’ requested
#include <iostream>

using namespace std;

class FOO{
    private:
        int X;
    public:
    
        explict FOO(int x){ X = x; }    //<==By declaring explicit,  lines (A)(B) have compilation error.
        void print(){ cout << X << endl; }
};

void Print( FOO x )
{
    x.print();
}

int
main(void)
{
    FOO f(30);
    
    FOO g = 20;   //(A)
    
    Print(f);
    Print(20);   //(B)
    
    return 0;
}