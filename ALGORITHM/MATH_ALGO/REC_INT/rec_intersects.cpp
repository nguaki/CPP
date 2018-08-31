#include <iostream>

using namespace std;

struct Point{
    int x, y;
};

bool
bRecIntersects( Point tl1, Point br1, Point tl2, Point br2 )
{
    //Check horizontal gap.
    //if there is a horizonal gap in top left point of a rectangle and bottom right point
    //of a rectangle, 2 rectangles don't intersect.
    if( tl2.x > br1.x || tl1.x > br2.x ) return false;
    
    //Check vertical gap.
    //if there is a vertical top gap in left point of a rectangle and bottom right point
    //of a rectangle, 2 rectangles don't intersect.
    if( br2.y > tl1.y || br1.y > tl2.y ) return false;
    
    return true;
}

int 
iCalArea( Point tl1, Point br1, Point tl2, Point br2 )
{
   //Area = horz distance * vert distance.
   //horz distance = max x of horiz line - min x of horiz line. 
   //vert distance = max y of vertical line - min y of vertical line
   
   return  ( max(tl2.x,br1.x) - min(tl2.x,br1.x) ) * ( max(tl2.y, br1.y) - min(tl2.y, br1.y));
}
    
int
main(void)
{
    Point tl1 = {0,10}, br1 = { 10, 0 };
    Point tl2 = {5,5},  br2 = {15, 0 };

    if( bRecIntersects(tl1, br1, tl2, br2 )){
        cout << "Intersects" << endl;
        cout << "Area: " << iCalArea(tl1,br1,tl2,br2) << endl;
    } 
    else cout << "Don't intersect";
    
    return 0;
}   