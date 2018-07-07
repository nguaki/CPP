#ifndef _ROGUEGAME_H__
#define _ROGUEGAME_H__
#include <vector>

#include "Player.h"
#include "Map.h"
#include "Enemies.h"

using namespace std;

class RogueGame{
    public:
        RogueGame(const char *strFileName);
        void vPlayGame();
        void vDrawNewMap();
    private:
        PLAYER objPlayer;
        MAP objMap;
        vector<ENEMIES> vObjEnemies;
};
#endif