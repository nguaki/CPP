#ifndef _PLAYER_H__
#define _PLAYER_H__
#include "Coord.h"
using namespace std;


 
class PLAYER
{
    public:
        void vSetPosition(int,int);
        void vGetPosition(int &,int &);
        void vPrintPlayerPosition();

    private:
        COORD strctCurrPosition;
};
#endif