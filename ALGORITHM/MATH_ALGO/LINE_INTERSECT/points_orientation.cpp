#include <iostream>
#include <cassert>

using namespace std;

struct Point
{
    int x, y;
};

// To find orientation of ordered triplet (p1, p2, p3).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p1, Point p2, Point p3)
{
    // See 10th slides from following link for derivation
    // of the formula
    int val = (p2.y - p1.y) * (p3.x - p2.x) -
              (p2.x - p1.x) * (p3.y - p2.y);
 
    if (val == 0) return 0;  // colinear
 
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
void
vPrintOutOrientataion( int o )
{
    switch(o)
    {
        case 0:   
                cout << "Linear";
                break;
        case 1:
                cout << "Clockwise";
                break;
        case 2:
                cout << "CounterClockwise";
                break;
        default:
                break;
    }
    cout << "\n";
}

// Driver program to test above functions
int main()
{
    Point p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 2};
    int o = orientation(p1, p2, p3);
    vPrintOutOrientataion( o );
    
    assert( orientation(p1, p2, p3)==2 );
    
    p1 = {0, 0}, p2 = {4, 4}, p3 = {2, 2};
    o = orientation(p1, p2, p3);
    vPrintOutOrientataion( o );
    assert( orientation(p1, p2, p3)==0 );
    
    p1 = {0, 0}, p2 = {4, 4}, p3 = {5, 1};
    o = orientation(p1, p2, p3);
    vPrintOutOrientataion( o );
    assert( orientation(p1, p2, p3)==1 );
    
    return 0;
}
