///////////////////////////////////////////////////////////////////////////////
// 
// June 20, 18
//
//  Demonstrates construction of customized exception object.
//  Demonstrates try, throw and catch sequence.
//
//  OUTPUT
//Enter numerator:45                                                                                                       
//Enter denominator:0                                                                                                      
//Cannot divide by zero
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdexcept>

using namespace std;

class DivideByZero : public runtime_error{
    public:
        //Note this is instatiating an object run_time with a specific string.
        DivideByZero() : runtime_error("Cannot divide by zero"){};  
        
};

//Throws an exception if denominator is zero.
double dQuotient( double dNum, double dDenom ){
    if( dDenom == 0.0){
        //Note that this is actually instatiating an object on the fly without storing. 
        throw DivideByZero();  
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
    //Catches an exception. Note the reference.
    catch(DivideByZero &exception ){ 
        cout << exception.what();
    }
}