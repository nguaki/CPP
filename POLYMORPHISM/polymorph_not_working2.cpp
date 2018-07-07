    // Aug 16, 2016
    // Demonstration that polymorphism is not working with this code.
    //
    //NAME:XYZPAY:1600
    //NAME:ABCPAY:6.4e+06   <== Utilizing base function's getMonthlyPay() method.

    #include <iostream>
    #include <sstream>
    #include <vector>
    
    using namespace std;
    
    class Employee{
        protected:
            string sName;
            double dPay;
        public:
            Employee( string sName1, double dPay1){
                sName = sName1;
                dPay = dPay1;
            }
            
            Employee(){}
            ~Employee(){}
            
            string toString(){
                stringstream ss;
                
                ss << sName << ":" << dPay;
                return ss.str();
            }
            
            string getName(){
                return sName; 
            }
            
            double getPay(){
                return dPay;
            }
            
            double getMonthlyPay( int iHours ){
                return iHours * dPay;
            }
    };
    
    class Manager : public Employee {
        private:
            bool bSalaried;
        public:
            //Interesting way of assigning private boolean variable.
            //Note that Employee() default constructor must be defined.
            Manager() : bSalaried(true){ }
            
            Manager( string sName, double dSalaryAmt, bool bSalaried1 ):Employee(sName,dSalaryAmt){
                bSalaried = bSalaried1;
            }
        
            ~Manager(){}
            
            bool getSalaried(){
                return bSalaried;
            }
            
            double getMonthlyPay( int iHours ){
                if( bSalaried ) {
                    return dPay;
                } else {
                    return iHours * dPay;   
                }
            }
            
            string toString(){
                stringstream ss;
                
                ss << sName << ":" << dPay << ":" << bSalaried << endl;
                return ss.str();
            }
    };
    
    
    int
    main()
    {

        Employee Emp1( "XYZ", 10);
        Manager  Emp2( "ABC", 40000, true);
        Employee *ptrEmp;
        
        ptrEmp = &Emp1;
        
        cout << "NAME:" << ptrEmp->getName() << "PAY:" << ptrEmp->getMonthlyPay(160)<<endl;

        ptrEmp = &Emp2;
        
        cout << "NAME:" << ptrEmp->getName() << "PAY:" << ptrEmp->getMonthlyPay(160)<<endl;
        
        return 0;
    }