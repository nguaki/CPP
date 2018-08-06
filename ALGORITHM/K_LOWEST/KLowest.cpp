//Aug 6, 2018
//
//Finding K-lowest elements.
//Specifically K-lowest distances from origin.
//
// 1. Create N objects of a class called Points in a form of a vector.
// 2. sort this vector.
//
// Must know how to creat a class with constructor.
// Must know how to instantiate N objects at once using {} operator.
// Must know how to sort a vector.

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
/*
int
comparePoints(const Points *lhs, const Points *rhs)
{
    return lhs->getfD() < rhs->getfD();
}
*/
int
main(void)
{
    Points  pts[5]{ Points(1,1), Points(2,2), Points(3,3), Points(4,4), Points(5,5) };
    vector <Points> vP;
    
    int i;
    int k_lowest;
    
    for( i=0; i<5; i++ ) vP.push_back(pts[i]);
    
    //sort(vP.begin(), vP.end(), comparePoints );   //This didn't work.
    sort(vP.begin(), vP.end(), [](Points a,Points b){ return (a.getfD()<b.getfD());});
    
    for( auto &it : vP ) cout << it.getfD() << endl;
    
    cout << "Enter K for lowest K elements:";
    cin >> k_lowest;
   
    i = 0; 
    for( auto &it : vP ){
        if( i<k_lowest ){
            cout << it.getfD() << endl;
            i++;
        }            
    } 
     
    return 0;
}