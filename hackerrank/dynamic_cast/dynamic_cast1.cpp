//
//
//
//
#include <iostream>
#include <exception>

using namespace std;

class base{
    protected:
        int x, y;
    
    public:
        virtual void display(){};
        void xyz(){ }
};

class derived : public base{
    public:
        void display(){ 
            cout << x << y << endl;
        }
};

int
main()
{
    base    *pbase    = new base();
    derived *pderived = new derived();

    derived *pd;
    
    try{
        pd = dynamic_cast<derived*>(pderived);
        
        if( pd == 0 )  cout << "cannot dynamic_cast derived" << endl;
        
        pd = dynamic_cast<derived*>(pbase);
        
        if( pd == 0 ) cout << "cannot dynamic_cast base" << endl;
        
    }catch( exception e){
        
        cout << e.what();
    }

    return 0;
}