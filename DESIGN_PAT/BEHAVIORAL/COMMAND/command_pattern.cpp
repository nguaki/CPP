//
//Wiki:
//Command pattern is an Object behavioral pattern that decouples sender and receiver by encapsulating a 
//request as an object, thereby letting you parameterize clients with different requests, queue or log 
//requests, and support undo-able operations. It can also be thought as an object oriented equivalent of call back method.
//
//Call Back: It is a function that is registered to be called at later point of time based on user actions.
//
//Q:Who is the sender object?  Switch
//Q:Who is the receiver object? Light
//Q:Encapsulating a request as an object? How? 
//A:Requests are switchUp and switchDown. They are in objects of FlipUpCommand class and FlipDownCommand class.
//                              
//
//    FlipUpCommand is Command
//    FlipDownCommand is Command
//
//    FlipUpCommand has Light (Composite)
//    FlipDownCommand has Light(Composite)
//
//    Switch has FlipUpCommand (Composite)
//    Switch has FlipDownCommand (Composite)
//
//
//                            [Command Interface]
//                               ^            ^
//                               |            |
//     [Light]<>-----[FlipUpCommand]        [FlipDownCommand]--------<>[Light]
//                             ^                ^
//                             V                V
//                             ----[Switch]------
//    [Light] is one class 
//    
//    Sender (Switch) and Receiver (Light) are decoupled by request object (FlipUpCommand and FlipDownCommand)
//
//
//	s.flipUp();
//     (1)flipUpCommand.execute();
//     (2)theLight.turnOn();
//	s.flipDown();
//     (1)flipDownCommand.execute();
//     (2)theLight.turnOff();
#include <iostream>

using namespace std;

/*the Command interface*/
class Command 
{
public:
	virtual void execute()=0;
};

/*Receiver class*/
class Light {

public:
	Light() {  }

	void turnOn() 
	{
		cout << "The light is on" << endl;
	}

	void turnOff() 
	{
		cout << "The light is off" << endl;
	}
};

/*the Command for turning on the light*/
//FlipUpCommand and Light Classes are composite relationship.
//Without Light Class, this class will not work.
//
//
//   [FlipUpCommand]   -------- <> [Light]
//
class FlipUpCommand: public Command 
{
public:

	FlipUpCommand(Light& light):theLight(light)
	{

	}

	virtual void execute()
	{
		theLight.turnOn();
	}

private:
	Light& theLight;
};

/*the Command for turning off the light*/
//FlipDownCommand and Light Classes are composite relationship.
//Without Light Class, this class will not work.
//
//
//   [ FlipDownCommand ]   -------- <> [Light]
//
class FlipDownCommand: public Command
{
public:   
	FlipDownCommand(Light& light) :theLight(light)
	{

	}
	virtual void execute() 
	{
		theLight.turnOff();
	}
private:
	Light& theLight;
};

//Switch class and derived classes of Command(FlipUpCommand, FlipDownCommand) have composite relationship.
//Without these classes, Switch class cannot exist.
//
//
//        [FlipUpCommand]            [FlipDownCommand]
//             ^                             ^
//             V                             V
//             |                             |
//             |                             |
//             --------[Switch]---------------
//               
class Switch {
public:
	Switch(Command& flipUpCmd, Command& flipDownCmd)
	:flipUpCommand(flipUpCmd),flipDownCommand(flipDownCmd)
	{

	}

	void flipUp()
	{
		flipUpCommand.execute();
	}

	void flipDown()
	{
		flipDownCommand.execute();
	}

private:
    //Below are polymorphism statements since flipUpCommand is of class FlipUpCommand
    //which is derived from Command interface.
	Command& flipUpCommand;
	Command& flipDownCommand;
};

 
/*The test class or client*/
int main() 
{
	Light lamp;
	FlipUpCommand switchUp(lamp);
	FlipDownCommand switchDown(lamp);

	Switch s(switchUp, switchDown);
	s.flipUp();
	s.flipDown();
}