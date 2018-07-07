///////////////////////////////////////////////////////////////////////////////
//  July 2, 2018
//
// Illustration of dependency injection.
//
//   [  class A ]   ===>  [ class B ]
//  Class A uses class B.
//
//  Class A depends on class B.
//  For some fucken reason, developers makes a big deal!!!
//
//  Instead of using,  inject object B into class A.
//  Here is the thing: Don't instantiate any object within class A.
//
// OUTPUT:
//Circle
//Rectangle
//Draw circle.
//Draw Rectangle.
//                                   [      Shape        ]
//                                      ^            ^
//                                      |            |
//        [ Drawing ]    =====>  [ Circle ]     [ Rectangle ]
//
//   Here Drawing class uses Circle or Rectangle objects.
//   Rectangle and Circle are derived class of Shape which is an abstract class.
//
//   An address of Circle is injected into Drawing object as an instance of
//   Shape object.
//   An address of Rectangle is injected into Drawing object as an instance of
//   Shape object.
//   From Drawing Object, it determines which one to draw.
//
//   What is a big deal?  There is no code change needed for Drawing.
//   All you need is to inject an address of an object which is derived from
//   Shape object.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

class Shape{
	public:
	virtual void vDraw()=0;
//{ cout << "Virtual" << endl; }
};

class Circle: public Shape{
	public:
	Circle(){ cout << "Circle" << endl; }
	void vDraw(){ cout << "Draw circle." <<endl;}
};

class Rectangle: public Shape{
	public:
	Rectangle(){ cout << "Rectangle" << endl; }
	void vDraw(){ cout << "Draw Rectangle." <<endl; }
};

class Draw{ 
	private :
		Shape *shape;
	public:
	void vSet(Shape *aShape){ this->shape = aShape; } 
	void vDraw(){ this->shape->vDraw(); }
};

int
main(void)
{
	Draw draw; 
	//Circle *circle = new Circle();
	//Rectangle *rectangle = new Rectangle();
	Circle circle;
	Rectangle rectangle;

	//Must send address for polymorphism to work.
	draw.vSet(&circle);
	draw.vDraw();
	draw.vSet(&rectangle);
	draw.vDraw();

	return 0;
}
