#ifndef _ENEMIES_H_
#define _ENEMIES_H_

#include <string>
#include "Coord.h"

using namespace std;

class ENEMIES
{
    public:
         ENEMIES(string, char, int, int);
         void vSetPosition( int, int );
         void vGetPosition(int &, int &);
         char cGetTile();
         void vSetTile(char);
         char cGetMove( int, int);
    private:
        string sName;
        COORD  strctPosition;
        char   cTile;
};
#endif