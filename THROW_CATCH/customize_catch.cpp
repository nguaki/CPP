#include <iostream>
#include <exception>

using namespace std;

class OverSpeed : public exception{
	int iSpeed;
	public:
		//OverSpeed( int iSpeed ){ this->iSpeed = iSpeed; }
		void vSetSpeed(int i){ iSpeed = i; }
		int  iGetSpeed(){ return iSpeed; }
		const char *cpWhat(){ return "Too fast, slow down!"; }
};

class Car
{
	int iSpeed;
	public:
		Car(){ iSpeed = 0; };
		void vAccelerate();
};

void Car::vAccelerate()
{
	while(1)
	{
		iSpeed += 10;
		cout << "Speed = " << iSpeed << endl;

		if( iSpeed > 250 ){
			OverSpeed objOS;
			objOS.vSetSpeed(iSpeed);
			throw(objOS);
		}
	}
}

int
main(void)
{
	Car objCar;

	try{
		objCar.vAccelerate();

	}catch( OverSpeed S ){
		cout << S.cpWhat();
		cout << S.iGetSpeed();
	}
	
	return 0;	  		
}
