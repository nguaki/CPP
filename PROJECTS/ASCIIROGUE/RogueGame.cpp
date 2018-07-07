#ifndef _ROGUEGAME_CPP
#define _ROGUEGAME_CPP
/////////////////////////////////////////////////////////////////////////////
//g++ AR.cpp RogueGame.cpp Player.cpp Map.cpp Enemies.cpp -g -std=c++11
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

#include "RogueGame.h"

//RogueGame::RogueGame( string strFileName )
RogueGame::RogueGame( const char *strFileName )
{
    objMap.vLoad(strFileName);
}

void
RogueGame::vPlayGame()
{
    char cInput;
    
    objMap.vDrawNewMap();
    //objPlayer.vFindCurrPosition( vecLines );
    objMap.vFindCurrPosition(objPlayer, vObjEnemies);
    
    cout << "\033[2J\033[1;1H";
    while(1)
    {
        cInput = cin.get();
        cout << cInput << endl;
        
        cout << "\033[2J\033[1;1H";
        //vProcessPlayerMove(cInput);
        objMap.vProcessPlayerMove(cInput, objPlayer, vObjEnemies);
        objMap.vProcessEnemiesMove( objPlayer, vObjEnemies );
        objMap.vDrawNewMap();
    }
}
#endif
