/////////////////////////////////////////////////////////////////////
//Oct 6, 2016
//
// Uses set class to find out prime numbers.
//
//Output:
//Enter a number:100
//2  3  5  7  11  13  17  19  23  29  31  37  41  43  47  53  
//59  61  67  71  73  79  83  89  97 
//
//Use set DS to insert(), find(), erase() prime numbers.
//ALso utilizes iterator to print out all prime numbers.
//
//Vector DS can be used but Set is a better DS since the set 
//consists of unique numbers.
//
//
//June 20, 2018   Printing using index doesn't work.
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <set>

using namespace std;

//Generate prime number less than iNumber.
void 
vDisplayPrime( int iNumber ){
    
    set<int> stPrimeNums;
    
    //Insert all numbers into set data structure.
    for( int i=2; i<=iNumber; i++){
        stPrimeNums.insert(i);
    }
    
    set<int>::iterator itPrimeNums;
    
    for( int multiple = 2; multiple*multiple <= iNumber; multiple++ ){
        itPrimeNums = stPrimeNums.find(multiple);
        
        if( itPrimeNums != stPrimeNums.end() )
        {
            //Remove all multiples.
            for( int k = 2*multiple; k <= iNumber; k = k+multiple)
            {
                itPrimeNums = stPrimeNums.find(k);
                
                //Erase from set data structure all the multiple numbers.
                if( itPrimeNums != stPrimeNums.end() ){
                    stPrimeNums.erase(*itPrimeNums);
                }
            }
        }
    }
    
    for( set<int>::iterator itP = stPrimeNums.begin(); itP != stPrimeNums.end(); itP++ ){
        cout << *itP << "  "; 
    }
    //No match for operator[]. Following failed to compile.
    //for( int i=0; i<stPrimeNums.size(); i++)
    //    cout << stPrimeNums[i] << endl;
}

int
main(){
    int iNumber;
    
    cout << "Enter a number:";
    cin >> iNumber;
    
    vDisplayPrime( iNumber );
    
    return 0;
}