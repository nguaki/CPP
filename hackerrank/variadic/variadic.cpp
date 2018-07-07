#include <iostream>
#include <math.h>

using namespace std;
// Enter your code for reversed_binary_value<bool...>()
template <bool ...digits>
int reversed_binary_value()
{
    const size_t size = sizeof...(digits);
    bool bits[size] = { digits... };
    int iRes = 0;
    
    //cout << "size = " << size << endl;
    for( auto i = 0; i < size; ++i ){
        //cout << bits[i] << " "; 
        //iRes = iRes + pow(bits[i],i);
    }
    //cout << endl;

    for( auto i = 0; i < size; ++i ){
        //cout << bits[i] << " "; 
        iRes = iRes + bits[i]*pow(2,i);
    }
    //cout << iRes << endl;
    // reverse order of array
    
    // convert bit array into integer number
    
    // return number
    return iRes;
}

////////////////////////////////////////////////////////////////////////////////
//This template is used when the first parameter is an integer and the rest 
//is 0 or more boolean parameters.
////////////////////////////////////////////////////////////////////////////////
template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
  	    const int size = sizeof...(digits);  //Gets the number of elements digits.
  	                                         //Syntax is weird.  ...(elipse) is outside
  	                                         //parenthesis.
  	    bool bits[size] = {digits...};       //Assigns the values.
  	                                         //In this case, the elipse is after.
  	    
  	    for( auto i = 0; i < size; ++i ){
  	        cout << bits[i] << " ";
  	    }
  	    cout<< endl;
  	    //Below is a recursive call
  	    //cout << "above n=" << n << " x=" << x << " y=" << y << endl;
    	CheckValues<n-1, 0, digits...>::check(x, y);  //Whenever n-1==0, the bottom struct 
    	                                              //will be called.  The second parameter 
    	                                              //which is zero will be used as the 1st
    	                                              //boolean parameter.
    	                                              //Once the call from the bottom structure
    	                                              //has returned, the following will be executed.
    	//cout << "in between CheckValues<>" << endl;
  	    //cout << "in between n=" << n << " x=" << x << " y=" << y << endl;
    	CheckValues<n-1, 1, digits...>::check(x, y);
    	//cout << "after 2nd CheckValues<>" << endl;  //Once at this point, if there is any recursive
    	                                              //function(s) is left on the stack memory,
    	                                              //it will execute that function call on the top
    	                                              //of the stack.
  	}
};

////////////////////////////////////////////////////////////////////////////////
//
//This is a specialized template.
//This means that whenever CheckValues<> first parameter is 0, this will be 
//called instead of the one above.
//In this program, there are 2 struct with same names.
//When CheckValues<1, 0, digits...> is called, the above is used.
//
////////////////////////////////////////////////////////////////////////////////
template <bool...digits>  //Defines type to be boolean and it can have 0 or 
                          //more boolean parameters.
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
  	    //cout << "below " << endl;
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);  //This is an boolean expression.  Prints 1 if true otherwise 0.
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<0>::check(x, y); //This will call the first CheckValues struct since
    	                             //the parameter is a non-zero integer.
    	                             //If it was a zero integer, the second struct will be called.
    	cout << "\n";
  	}
}
