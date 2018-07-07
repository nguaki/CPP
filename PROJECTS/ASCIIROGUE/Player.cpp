#ifndef _PLAYER_CPP_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Player.h"
using namespace std;

void PLAYER::vPrintPlayerPosition()
{
    cout << "X = " << strctCurrPosition.iX << endl;
    cout << "Y = " << strctCurrPosition.iY << endl;
    
}

///////////////////////////////////////////////
//Stores (X,Y) position of a player. 
//Not Row, Colulmn
///////////////////////////////////////////////
void PLAYER::vSetPosition( int iX, int iY)
{
    strctCurrPosition.iX = iX;
    strctCurrPosition.iY = iY;
    vPrintPlayerPosition();
    
}
///////////////////////////////////////////////
//Retrieves (X,Y) position of a player. 
//Not Row, Colulmn
///////////////////////////////////////////////
void PLAYER::vGetPosition( int &iX, int &iY)
{
    iX = strctCurrPosition.iX;
    iY = strctCurrPosition.iY;
    vPrintPlayerPosition();
    //getchar();
}


#endif