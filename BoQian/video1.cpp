//////////////////////////////////////////////////////////////////////
//July 27, 2018
//
// Demonstration of executing template function with or without <> bracket.
// An important note is that although a function is defined once,
// after the compilation. this function is actually multiple functions.
// There is a terminology for this: 'bloated'.
//
// One major difference between class and functional template is that
// with class template, the data type must be explicitly declared.
//
//OUTPUT
//25
//30.25
//25
//30.25
//=============================================
//1
//2
//3
//4
//5
//=============================================
//1.1
//2.2
//3.3
//4.4
//5.5
//=============================================
//1.1
//2.2
//3.3
//4.4
//5.5
//=============================================
//1.21
//4.84
//10.89
//19.36
//30.25
//1.21
//4.84
//10.89
//19.36
//30.25
//////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////
//Template function.
//T can be a simple object like int, double.
//T can also be a complicated class object.
//There is a overload * operator on Class BoVector.
//When this is sent, the overload operator function is triggered.
//////////////////////////////////////////////////////////////////////
template <typename T>
T tSquare( T t )
{
	return t * t;
}

//////////////////////////////////////////////////////////////////////
// Class template
//
// Note that the memory allocation is replaced.
// THe reason for this is that the function cannot send 
// an object where the memory is allocated.
//////////////////////////////////////////////////////////////////////
template <typename T>
class BoVector
{ 
	//T  *aVal; 
	T  aVal[10]; 
	int size;
	
	public:
	    //Allocating memory to any type.
		/*
		BoVector(int iMax) : size(0){
			aVal = (T *)malloc(iMax * sizeof(T));
		}
		~BoVector(){
			delete[] aVal;
		}
		*/
		BoVector() : size(0){ }
		
		void vPush(T aVal)
		{
			this->aVal[size] = aVal;
			size++;
		}				
		void vPrint() const{
			for( int i=0; i<size; i++)	cout << this->aVal[i] << endl;
		}
		int iGetSize() const{ return size;}
		T tGetVal( int i ) const{ return aVal[i]; }
};

/////////////////////////////////////////////////////////////////////////
//Note that memory allocation didn't work.
//The reason behind this is that the destructor is triggered when
//this function returns.  When the destructor is triggered, it loses
//the memory allocation of the result object.
/////////////////////////////////////////////////////////////////////////
template <typename T>
BoVector<T> operator * ( BoVector<T> &vec1, BoVector<T> &vec2 )
//void operator * ( BoVector<T> &vec1, BoVector<T> &vec2, BoVector<T> &result )
{
	//BoVector<T> result(5);
	BoVector<T> result;
	
	int iSize = vec1.iGetSize();	

	for( int i=0; i<iSize; i++ )
	{
		result.vPush( vec1.tGetVal(i) * vec2.tGetVal(i) );
	}
	
	return result;
}

int
main(void)
{
	cout << tSquare<int>(5) << endl;
	cout << tSquare<double>(5.5) << endl;

	cout << tSquare(5) << endl;   //Note that <> is not needed. Without it, C++ infers that this is int.
	cout << tSquare(5.5) << endl;

	cout << "=============================================" << endl;
	
	//BoVector<int>  objBo(5);
	BoVector<int>  objBo;

	objBo.vPush(1);
	objBo.vPush(2);
	objBo.vPush(3);
	objBo.vPush(4);
	objBo.vPush(5);

	objBo.vPrint();

	cout << "=============================================" << endl;
	//BoVector<double>  objBo2(5);
	BoVector<double>  objBo2;

	objBo2.vPush(1.1);
	objBo2.vPush(2.2);
	objBo2.vPush(3.3);
	objBo2.vPush(4.4);
	objBo2.vPush(5.5);

	objBo2.vPrint();
	cout << "=============================================" << endl;
	
	//BoVector<double>  objBo3(5);
	BoVector<double>  objBo3;

	objBo3.vPush(1.1);
	objBo3.vPush(2.2);
	objBo3.vPush(3.3);
	objBo3.vPush(4.4);
	objBo3.vPush(5.5);

	objBo3.vPrint();
	cout << "=============================================" << endl;


	//BoVector<double> objResult(5);
	BoVector<double> objResult;
	objResult = objBo2 * objBo3;
	objResult.vPrint();


	//This is really requires deep understanding how parameters are 
	//received.
	//1. objBo2 is of ObVector<double> type.
	//2. When tSquare receives this object, it actually instatiates the object 
	//   once again.
	//3. Since there is * operator overload function, it will call the function.
	//4. An object will be returned to tSquare.
	//5. From tSquare, this same object is returned.
	
	objResult = tSquare(objBo2);
	objResult.vPrint();
	
	return 0;
	
}