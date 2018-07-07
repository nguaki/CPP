//Oct 10, 16
//
// Demonstrates inheritance.
//
//balance : 100
//balance : 150
//balance : 200
//balance : 149.5
//Insufficient Funds
//balance : 149.5

#include <iostream>

using namespace std;

class Account{
    protected:
        double dBalance;
    public:
        Account(){ 
            dBalance = 0.0; 
        }
        
        Account( double dBalance1 ){
            if( dBalance1 > 0 ){
                dBalance = dBalance1;   
            } else {
                dBalance = 0.0;
            }
        }
        
        //Same as deposit.
        double getCredit( double dCredAmt ){
            dBalance = dBalance + dCredAmt;
        }
        
        //Same as withdraw.
        void getDebit( double dDbtAmt ){
            if( dBalance > dDbtAmt ){
                dBalance = dBalance - dDbtAmt;
            } else {
                cout << "Insufficient Funds" << endl;
            }
        }
        
        double getBalance(){
            return dBalance;
        }
};

class Checking : public Account{
    private:
        double dFee;
    public:
        Checking() : dFee(0.0) {}
        Checking( double dBalance1, double dFee1 ) : Account( dBalance1){
            if( dFee1 > 0.0 ) {
                dFee = dFee1;
            } else {
                dFee = 0.0;
            }
        }
        
        //Same as withdraw.
        double getDebit( double dDbtAmt ){
            if( dBalance > dDbtAmt ){
                dBalance = dBalance - dDbtAmt - dFee;
            } else {
                cout << "Insufficient Funds" << endl;
            }
        }
};

int
main()
{
    Checking oCheck1(100, 0.50);
    
    cout << "balance : " << oCheck1.getBalance() << endl;
    
    oCheck1.getCredit(50);
    cout << "balance : " << oCheck1.getBalance() << endl;
    
    oCheck1.getCredit(50);
    cout << "balance : " << oCheck1.getBalance() << endl;

    oCheck1.getDebit(50);
    cout << "balance : " << oCheck1.getBalance() << endl;

   oCheck1.getDebit(150);
    cout << "balance : " << oCheck1.getBalance() << endl;
    return 0;
}