#include <iostream>
#include <vector>
using namespace std;
class STACK{
public:
	void vPush(int iX);
	void vDisplay();
	int  iPop();

private:
	vector<int> vStack;
};

void STACK::vDisplay()
{
	vector<int>::iterator  itV;

	for(itV=vStack.begin(); itV!=vStack.end(); itV++)
		cout << *itV << endl;
}
void STACK::vPush( int i)
{
	vStack.push_back(i);
}
int STACK::iPop()
{
	int iTop;
	
	iTop = vStack.back();
	vStack.pop_back();
	return iTop;
}
int
main()
{
	STACK  objStack;
	int    i;

	for( i=0; i<10; i++ )
		objStack.vPush(i);

	objStack.vDisplay();
	cout << "Popping " << objStack.iPop() << endl;
	objStack.vDisplay();
	
	return 0;	
}
