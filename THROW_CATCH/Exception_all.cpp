////////////////////////////////////////////////////////////////////////////////
// Oct 6, 16
//
// Demonstration of catch all exception.
//
//Enter numerator:34                                                                                                       
//Enter denominator:0                                                                                                      
//Exception Caught                                                                                                         
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdexcept>

using namespace std;

class DivideByZero : public runtime_error{
    public:
        DivideByZero() : runtime_error("Cannot divide by zero"){};  //Note the calling of runtime_error() constructor and the empty body.
        
};

double dQuotient( double dNum, double dDenom ){
    if( dDenom == 0.0){
        throw DivideByZero();  //Note that this is actually calling constructor. How is this possible without instatiating an object?
    } else {
        return dNum/dDenom;
    }
}

int
main(){
    
    double dNum, dDenom, dRatio;
    cout << "Enter numerator:";
    cin >> dNum;
    cout << "Enter denominator:";
    cin >> dDenom;
    
    try{
        dRatio = dQuotient(dNum,dDenom);
        cout << dRatio;
    }
    catch(...){ //Catches all exceptions
        cout << "Exception Caught" << endl;
    }
}