// Aug 20, 16
// Defines abstract methods (aka pure virtual methods)
// Derived class must define these methods.
//
//Description:
//Draws circle at X=5Y=5radius=4.5
//
#include <iostream>

using namespace std;

class Shape{
    
    public:
        virtual void setX( int X) = 0;
        virtual void setY( int Y) = 0;
        virtual int getX() const = 0;
        virtual int getY() const = 0;
        virtual void vDraw() const = 0;
};

class Circle: public Shape{
      private:
        int iX, iY;
        double dRadius;
        
    public:
        Circle( int X, int Y, double R){
            iX = X;
            iY = Y;
            dRadius = R;
        }
        void setX( int X1 ){
            iX = X1;
        }
        void setY( int Y1){
            iY = Y1;
        }
        //Very important syntax.
        int getX() const{
            return iX;
        }
        int getY() const{
            return iY;
        }
        void vDraw() const{
            cout << "Draws circle at X=" << getX() << "Y=" << getY() << "radius=" << dRadius << endl;
        }
  
};

int 
main()
{
    Circle c(5,5,4.5);
    c.vDraw();
    return 0;
}