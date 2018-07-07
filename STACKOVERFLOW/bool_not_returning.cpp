#include <iostream>
#include <cstdlib>

using namespace std; 

class genericClassName{
	bool genericArray [3][3]; 
	public:
		genericClassName()
		{
			int i, j;
			for( i=0;i<3;i++)
				for(j=0;j<3;j++)
					genericArray[i][i] = false;
/*genericArray = 
			{
				{ false, false, false },
				{ false, false, false },
				{ false, false, false },
			};
*/
			//genericArray[3][3] = {false};
		}
		bool getterFunction (int row, int column)
		{
		    return genericArray[row][column];
		}
};

int
main(void)
{
	genericClassName objectName;

	cout << objectName.getterFunction (1, 1) << endl;
	return 0;
}
