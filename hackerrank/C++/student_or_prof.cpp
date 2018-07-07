//Hackerrank
//
//Input
//4
//1
//Walter 56 99
//2
//Jesse 18 50 48 97 76 34 98
//2
//Pinkman 22 10 12 0 18 45 50
//1
//White 58 87
//
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int iStudentID = 0, iProfID = 0;

class Person{
    protected:
        string sName;
        int   iAge;
    public:
        virtual void getdata() = 0;
        virtual void putdata() = 0;
};

class Professor : public Person{
    private:
        int iPublicID;
        int iID;
    
    public:
        Professor(){
            iID = ++iProfID;   
        }
        void getdata(){
           cin >> sName >> iAge >> iPublicID;;
        }
    
        void putdata(){
            cout << sName << " " << iAge << " " << iPublicID << " " << iID << endl;
        }
};

class Student : public Person{
    private:
        int iScores[6];
        int iTotal;
        int iID;
    public:
        Student(){
            iID = ++iStudentID;
            iTotal = 0;
        }
        void getdata(){
            cin >> sName >> iAge;
            
            iTotal = 0;
            for(int i=0; i<6; i++){
                cin >> iScores[i];
                iTotal += iScores[i];
            }
        }
    
        void putdata(){
            cout << sName << " " << iAge << " " << iTotal << " " << iID << endl;
        }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];  //per is an array of pointer to Person base class.

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;  //Instantiate Professor object

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}