// Aug 16, 2016
// Demonstration that polymorphism is  working with this code.
//  declaration of 'virtual' made it polymorphism to work.
//
//Print by Employee pointer
//NAME:XYZPAY:1600   <=== Employee Pointer
//NAME:ABCPAY:40000  <=== Manager Pointer
//
//Print by Vector data but without using pointer which is the
//wrong way.
//NAME:XYZPAY:1600
//NAME:ABCPAY:6.4e+06  <=== Wrong number
//
//Print
//NAME:XYZPAY:1600
//NAME:ABCPAY:40000
 
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
            
            //keyword virtual allows the power of polymorphism.
            virtual double getMonthlyPay( int iHours ){
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
            
            virtual double getMonthlyPay( int iHours ){
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
        vector<Employee> vEmployees;
        vector<Employee *> vptrEmployees;
        

        ptrEmp = &Emp1;
        
        cout << "NAME:" << ptrEmp->getName() << "PAY:" << ptrEmp->getMonthlyPay(160)<<endl;

        ptrEmp = &Emp2;
        
        cout << "NAME:" << ptrEmp->getName() << "PAY:" << ptrEmp->getMonthlyPay(160)<<endl;
        
        //This doesn't work.
        vEmployees.push_back(Emp1);
        vEmployees.push_back(Emp2);
        
        for( int i=0; i<vEmployees.size(); i++){
            cout << "NAME:" << vEmployees[i].getName() << "PAY:" << vEmployees[i].getMonthlyPay(160)<<endl;
        }

        //This works!!!  Vector has to be a pointer.
        vptrEmployees.push_back(&Emp1);
        vptrEmployees.push_back(&Emp2);
        
        for( int i=0; i<vptrEmployees.size(); i++){
            cout << "NAME:" << vptrEmployees[i]->getName() << "PAY:" << vptrEmployees[i]->getMonthlyPay(160)<<endl;
        }
        return 0;

    }