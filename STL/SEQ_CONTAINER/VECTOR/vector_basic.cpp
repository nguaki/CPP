//July 27, 18
//Basic of Vector.
//Very important things about vector.

#include <iostream>
#include <vector>

using namespace std;

int
main(void)
{
	vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	//2 ways of accessing an element.
	cout << vec[2] << endl;  //Does not throw range exception if index is out of boundary.
	cout << vec.at(2) << endl;//Throws range exception.

	cout << "==============================================" << endl;
	//Can access an element like an array. This is a random access which does take longer
	//that continuous iterator.
	for(int i=0; i<vec.size(); i++)
		cout << vec[i] << endl;

	cout << "==============================================" << endl;
	vector<int>::iterator it, itBegin, itEnd;

	itBegin = vec.begin();
	itEnd   = vec.end();

    //Faster than the random access. This does pointer arithmetic to get to the 
    //next element.
    for(  it = itBegin; it != itEnd; ++it )
		cout << *it << endl;
	
	cout << "==============================================" << endl;
	for(auto it1:vec)	
		cout << it1 << endl;
	cout << "==============================================" << endl;
	int *p;
	p = &vec[0];
	p[2] = 10;
	
    for(  it = itBegin; it != itEnd; ++it )
		cout << *it << endl;
	cout << "==============================================" << endl;
	
	if(vec.empty()) 
		cout << "Empty" << endl;
	else
		cout << "Not Empty" << endl;
	cout << "==============================================" << endl;

	vector<int> vec1(vec);

	for( auto it2 = vec1.begin(); it2 != vec1.end(); ++it2 )	
		cout << *it2 << endl;
	
	cout << "==============================================" << endl;
	cout << vec1.size() << endl;
	cout << "==============================================" << endl;

	vec1.clear();
	for( auto it2 = vec1.begin(); it2 != vec1.end(); ++it2 )	
		cout << *it2 << endl;
	cout << "==============================================" << endl;
	
	vec.swap(vec1);  //vec now becomes empty.
	cout << "==============================================" << endl;
	for( auto it2 = vec1.begin(); it2 != vec1.end(); ++it2 )	
		cout << *it2 << endl;
}