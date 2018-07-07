#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

void ITEM::vInit( string sName, int iPrice )
{ 
    _sName = sName; 
    _iPrice = iPrice; 
    _iCnt = 1;
}
