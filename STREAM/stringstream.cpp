////////////////////////////////////////////////////////////////////////////////
//Date:  June 21, 2018
//Description:  Demonstrates string stream
//Output:
//         XYZ:50000
//         ABC:40000
//
// Utilizes str() method.
//
// 
////////////////////////////////////////////////////////////////////////////////
    #include <iostream>
    #include <sstream>
    
    using namespace std;
    
    class Employee{
        private:
            string Emp;
            double Pay1;
        public:
            Employee( string Name, double Pay){
                Emp = Name;
                Pay1 = Pay;
            }
            
            string toString(){
                stringstream ss;
                //In C++, cannot concatenate a string with a numeric value.
                //This is the only way to concatenate a string and a number,
                ss << Emp << ":" << Pay1;
                return ss.str();
            }
    };
    
    int
    main()
    {
        Employee Emp1( "XYZ", 50000);
        Employee Emp2( "ABC", 40000);
        
        cout << Emp1.toString() << endl;
        cout << Emp2.toString() << endl;
        return 0;
    }
