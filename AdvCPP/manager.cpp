    // Aug 20, 2016
    // Demonstration of functional override.
    // Note that functional override is not polymorphism.
    // Functional override happens during the run time and the derived class
    // is declared as the base class.  
    // Polymorphism occurs when the correct function is executed during
    // the run time.
    //
    //XYZ:10
    //ABC:40000:1             <-- executes correct toString() method.
    //
    //XYZ:10
    //ABC:40000:1
    //Month paycheck :1600
    //Month Paycheck :40000    <-- executes  correct getMonthlyPay() method.
    
    #include <iostream>
    #include <sstream>
    
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
        
        cout << Emp1.toString() << endl;
        cout << Emp2.toString() << endl;
        
        cout << Emp1.getName() << ":" << Emp1.getPay() << endl;
        cout << Emp2.getName() << ":" << Emp2.getPay() << ":" << Emp2.getSalaried() << endl;
        
        cout << "Month paycheck :" << Emp1.getMonthlyPay(160) << endl;
        cout << "Month Paycheck :" << Emp2.getMonthlyPay(1000) << endl;
        return 0;
    }
