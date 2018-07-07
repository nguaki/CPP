#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    private:
        int imAge;
        int imStandard;
        string smFirstName;
        string smLastName;
    public:
        Student(){
            imAge = 0;
            imStandard = 0;
            smFirstName.clear();
            smLastName.clear();
        }
    
        void set_age( int iAge ){imAge = iAge; }
        void set_standard( int iStandard ){ imStandard = iStandard; }
        void set_first_name( string sFirstName ){ smFirstName = sFirstName; }
        void set_last_name( string sLastName ){ smLastName = sLastName; }
        int get_age(){
            return imAge;
        }
        string get_last_name(){
            return smLastName;
        }    
        string get_first_name(){
            return smFirstName;
        }
        int get_standard(){
            return imStandard;
        }
    
        //Puts a string together and returns a string.
        string to_string(){
            stringstream ost;
            
            ost << imAge << ","  << smFirstName << "," << smLastName << "," << imStandard << endl; 
            return ost.str();
        }
    
    
    
};


int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
