#ifndef _MAP_CPP__
#define _MAP_CPP__

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>

#include "Player.h"
#include "Map.h"
#include "Enemies.h"

using namespace std;

void 
MAP::vLoad( const char *strFileName )
{
    ifstream ifMapSetting;
    string   strLine;
    char     cInput;
    int iRows, iColumns, i;
    
    ifMapSetting.open( strFileName );
    
    if( ifMapSetting.fail() )
    {
        cout << "Error opening a file." << endl;
        //exit(1);
    }
    
    while(getline(ifMapSetting, strLine)){
        vecLines.push_back(strLine);
    }
    ifMapSetting.close();
}

void    
MAP::vDrawNewMap()
{
    int i;
    for(i=0; i<vecLines.size(); i++)
            cout << vecLines[i] << endl ;
}

// Finds current position of the player.
// Remember than [row,column] => (y,x)
void    
MAP::vFindCurrPosition(PLAYER &objPlayer, vector<ENEMIES> &vObjEnemies )
{
    int i, j;
    string sTemp;
    char cTile;
    for( i=0; i<vecLines.size(); i++){
        for( j=0; j<vecLines[i].length(); j++){
            cTile = vecLines[i][j];
            switch(cTile)
            {
                case 'O':
                //if( vecLines[i][j] == 'O' ){
                    objPlayer.vSetPosition(j,i);   //ith row represents Y.
                                              //jth column represents X.
                    cout << "Found Circle at " << i << "th Row " << j << "th Column " << endl;
                    getchar();
                    break;
                case '#':
                case ' ':
                    break;
                default:
                    if( cTile == 'D') sTemp = "Dragon";
                    else if( cTile == 'S') sTemp = "Snake";
                    else if( cTile == 'B') sTemp = "Boom";
                    else sTemp ="Enemy";
                    
                    vObjEnemies.push_back( ENEMIES(sTemp,cTile,j,i));
                    cout << "Found enemy " << cTile << endl;
                    cout << "X = " << j << " Y = " << i << endl;
           }
        }
    }
}

void
MAP::vSetMap(char cNewPiece, PLAYER &objPlayer)
{
    int iX, iY;
    objPlayer.vGetPosition( iX, iY );
    vecLines[iY][iX] = cNewPiece;
}

/////////////////////////////////////////////////////////////
//Input: (X,Y) position.
//Process: Checks if Yth Row and Xth Column is a wall.
/////////////////////////////////////////////////////////////
bool 
MAP::bCheckIfWall(int iX, int iY)
{
    //vecLines[iX][iY] == '#'  ? return true : return false;
    
    if ( vecLines[iY][iX] == '#' ) 
        return true; 
    else
        return false;
    
}
bool 
MAP::bCheckIfEnemy(int iPlayerX, int iPlayerY, vector<ENEMIES> &vObjEnemies)
{
    int iEnemyX, iEnemyY;
    
    //vecLines[iX][iY] == '#'  ? return true : return false;
    for(int i=0; i<vObjEnemies.size(); i++)
    {
        vObjEnemies[i].vGetPosition(iEnemyX, iEnemyY);
        if( iPlayerX == iEnemyX  && iPlayerY == iEnemyY )
        {
            cout << "Met an enemy " << vObjEnemies[i].cGetTile() << endl;
            
            //Deleting the enemy vector by swapping with the last one and popping one.
            vObjEnemies[i] = vObjEnemies.back();
            vObjEnemies.pop_back();
            i--; //Must rewind one since the last one just got replaced and needs 
                 //to be processed.
            getchar();
            return true;
        }
    }
    return false;
}

void
MAP::vProcessMove( int iX, int iY, PLAYER &objPlayer, vector<ENEMIES> &vObjEnemies )
{
    if( bCheckIfWall(iX, iY) == false )
    {
        vSetMap( ' ', objPlayer );
        objPlayer.vSetPosition(iX, iY);
        vSetMap( 'O', objPlayer );
    }
    
    if( bCheckIfEnemy(iX,iY, vObjEnemies) == false )
    {
        vSetMap( ' ', objPlayer );
        objPlayer.vSetPosition(iX, iY);
        vSetMap( 'O', objPlayer );
      
    }
    else
    {
        cout << "Enemy destroyed." << endl;
        getchar();
    }
    
}

void 
MAP::vProcessPlayerMove( char cInput, PLAYER &objPlayer, vector<ENEMIES>&vObjEnemies )
{
    int iY, iX;
    
    objPlayer.vGetPosition( iX, iY );
    
    switch(cInput){
        case 'w':
            vProcessMove(iX,iY-1,objPlayer, vObjEnemies);
            break;
        case 's':
            vProcessMove(iX,iY+1,objPlayer, vObjEnemies);
            break;

        case 'a':
            vProcessMove(iX-1,iY,objPlayer, vObjEnemies);
            break;
        
        case 'd':
            vProcessMove(iX+1,iY,objPlayer, vObjEnemies);
            break;
        
        default:
                break;
    }
}
void MAP::vProcessActualEnemyMove( int iIndex, int iTargetX, int iTargetY, vector<ENEMIES> &vObjEnemies )
{
    int iPrevX, iPrevY;
    char cTile;
    
    vObjEnemies[iIndex].vGetPosition(iPrevX, iPrevY);
    cTile = vObjEnemies[iIndex].cGetTile();
    //If the target position is not a wall, make a move.
    if( bCheckIfWall(iTargetX, iTargetY) == false )
    {
        //Fill the new location with enemy symbol
        vecLines[iTargetY][iTargetX] = cTile;
        vObjEnemies[iIndex].vSetPosition(iTargetX,iTargetY); //Assign new location.
        vecLines[iPrevY][iPrevX]     = ' ';
    }
}
void MAP::vProcessEnemiesMove( PLAYER &objPlayer, vector<ENEMIES> &vObjEnemies )
{
    int i;
    int iDist;
    int iDx, iDy;
    int iADx, iADy;
    char cMove;
    int iPlayerX, iPlayerY;
    int iEnemyX, iEnemyY;
    
    objPlayer.vGetPosition( iPlayerX, iPlayerY );
    
    for( i=0; i<vObjEnemies.size(); i++)
    {
        cMove = vObjEnemies[i].cGetMove( iPlayerX, iPlayerY);
        vObjEnemies[i].vGetPosition(iEnemyX,iEnemyY);
        switch(cMove)
        { 
            case 'w':
                vProcessActualEnemyMove(i, iEnemyX, iEnemyY-1,vObjEnemies);
                break;
            case 's':
                vProcessActualEnemyMove(i, iEnemyX, iEnemyY+1,vObjEnemies);
                break;

            case 'a':
                vProcessActualEnemyMove(i, iEnemyX-1,iEnemyY,vObjEnemies);
                break;
        
            case 'd':
                vProcessActualEnemyMove(i,iEnemyX+1,iEnemyY,vObjEnemies);
                break;
        
            default:
                break;
        }
    }
}
#endif


