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
    
    while( i<k_highest ){
        cout << it->getfD() << endl;
        i++;
        it++;//C++ is smart enough for the direction.
    } 
     
    return 0;
}