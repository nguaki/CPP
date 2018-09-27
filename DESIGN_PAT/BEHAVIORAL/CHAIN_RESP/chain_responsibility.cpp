//OUTPUT
//Handler 2 handled the request of 18 which is within my max limit of 20
//Sorry, I am the last handler (3) and I can't handle the request.
//
//Sep 26, 2018
//According Wiki:
//Chain of Responsibility pattern has the intent to avoid coupling the sender of a request to its receiver 
//by giving more than one object a chance to handle the nrequest. Chains the receiving objects and passes the 
//requests along the chain until an object handles it.
//What? Sounds very philosophical.
//When would you use this pattern.
//One thing that is good is to see how objects interact each other.
//
// h1                      h2                       h3
// |-------------|  |---> |--------------|  |---> |----------------|
// |myLimit=10   |  |     |myLimit=20    |  |     |myLimit = 30    |
// |myID = 1     |  |     |myID = 2      |  |     |myID = 3        |
// |-------------|  |     |--------------|  |     |----------------|
// |next *       |---     | next *       |---     | next *         |
// |-------------|        |--------------|        |----------------|
//
// when h1.request(18) is called
// (1) 18 < 10 ? No 
// (2) next == NULL ? NO
//     Calls next->request(18)
//     next is pointing at h2.
//     (2.1) 18 < 20 ? yes
//           prints out the following:
//           Handler 2 handled the request of 18 which is within my max limit of 20
//
// when h2.request(40) is called
// (1) 40 < 10 ? No
// (2) next == NULL ? No
//     Calls next->request(40)
//     next is pointing at h2.
//     (2.1) 40 < 10 ? No
//     (2.2) next == NULL? No
//          Calls next->request(40)
//          next is pointing at h3.
//          (2.1.1)40 < 30 ? No
//          (2.1.2)next == NULL?Yes
//          (2.1.3)prints out 
//                  Sorry, I am the last handler (3) and I can't handle the request.
#include <iostream>

using namespace std;

//This is like a linked list.
//Handler is an abstract class since it has one pure abstract function.
//It is not an interface since it has one function that is defined.
class Handler {
    protected:
        Handler *next;

    public:
        Handler() { 
            next = NULL; 
        }

        virtual ~Handler() { }

        //pure virtual function
        virtual void request(int value) = 0;

        //Note that the parameter is   Polymorphic.
        //Type is Handler but it accepts its derived class.
        void setNextHandler(Handler *nextInLine) {
            next = nextInLine;
        }
};

class SpecialHandler : public Handler {
    private:
        int myLimit;
        int myId;

    public:
        SpecialHandler(int limit, int id) {
            myLimit = limit;
            myId = id;
        }

        ~SpecialHandler() { }

        void request(int value) {
            if(value < myLimit) {
                cout << "Handler " << myId << " handled the request of " << value << " which is within my max limit of " << myLimit << endl;
            } else if(next != NULL) {
                //It is calling this function using next object.
                //In a way, it is recursive with different object.
                next->request(value);
            } else {
                cout << "Sorry, I am the last handler (" << myId << ") and I can't handle the request." << endl;
            }
        }
};

int main () {
    Handler *h1 = new SpecialHandler(10, 1);
    Handler *h2 = new SpecialHandler(20, 2);
    Handler *h3 = new SpecialHandler(30, 3);

    h1->setNextHandler(h2);
    h2->setNextHandler(h3);

    h1->request(18);
    h1->request(40);

    h2->request(25);
    
    delete h1;
    delete h2;
    delete h3;

    return 0;
}