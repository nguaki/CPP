#ifndef _ENEMIES_CPP_
#define _ENEMIES_CPP
#include <iostream>
#include <random>

#include "Enemies.h"
ENEMIES::ENEMIES( string sName1, char cTile, int iX, int iY )
{
    sName = sName1;
    vSetTile(cTile);
    vSetPosition(iX,iY);
}

void ENEMIES::vSetTile(char cTile1)
{
    cTile = cTile1;
}
char ENEMIES::cGetTile()
{
    return cTile;
}
void ENEMIES::vSetPosition(int iX, int iY)
{
    strctPosition.iX = iX;
    strctPosition.iY = iY;
}

void ENEMIES::vGetPosition(int &iX, int &iY)
{
    iX = strctPosition.iX;
    iY = strctPosition.iY;
}

char ENEMIES::cGetMove( int iPlayerX, int iPlayerY)
{
    static default_random_engine randomEngine(time(0));
    uniform_int_distribution<int> moveRoll(0,6);

    int iDX = strctPosition.iX - iPlayerX;
    int iDY = strctPosition.iY - iPlayerY;
    
    int iABSDX = abs(iDX);
    int iABSDY = abs(iDY);
    
    int iDistance;
    
    iDistance = iABSDX + iABSDY;
    
    if(iDistance <= 5)
    {
        //If horizontal direction is less than vertical direction.
        if( iABSDX < iABSDY )
        {
            //If enemy is right of player, move left.
            if(iDX > 0 )
                return 'a'; //Have enemy move right
            else 
                return 'd'; //Have enemy move left
        }
        else
        {
            //If enemy is underneath of a player, move left.
            if(iDY > 0 )
                return 'w';  //Have enemy move up
            else    
                return 's'; //Have enemy move down.
            
        }
    }    
    //If far away to a player, move randomly.
    int iRandom = moveRoll(randomEngine); //between 0..6
    switch(iRandom)
    {
        case 0:
            return 'a';
        case 1:
            return 'w';
        case 2:
            return 's';
        case 3:
            return 'd';
        default:
            return ' ';
    }
}

#endif