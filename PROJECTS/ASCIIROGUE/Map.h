#ifndef _MAP_H__
#define _MAP_H__
#include <vector>
#include "Player.h"
#include "Enemies.h"

using namespace std;

class MAP
{
    public: 
        //void vLoad( const char *, vector<string> &);
        void vLoad( const char * );
        void vDrawNewMap();
        void vFindCurrPosition( PLAYER &, vector<ENEMIES> &);
        void vProcessPlayerMove(char, PLAYER &, vector<ENEMIES> &);
        bool bCheckIfWall(int, int);
        bool bCheckIfEnemy(int, int, vector<ENEMIES> &);

        void vSetMap( char, PLAYER & );
        void vProcessMove(int, int, PLAYER &, vector<ENEMIES> &);
        void vProcessEnemiesMove( PLAYER &objPlayer, vector<ENEMIES> &bjEnemies );
        void vProcessActualEnemyMove( int, int, int , vector<ENEMIES> & );

    private:
        vector<string> vecLines;

};
#endif