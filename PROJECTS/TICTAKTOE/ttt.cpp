#include <iostream>
#include "ttt.h"

using namespace std;

int
main()
{
    TTT objTTT;
    
    do{
    }while(objTTT.bStartGame() == false &&  objTTT.bCheckEmptySpace());
    
    return 0;
}