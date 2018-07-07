#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <list>
#include "Item.h"
using namespace std;

class PLAYER{
    
    public:
        void vInit(string sName, int iMoney){ vSetName(sName); vSetMoney(iMoney); }
        void vAddItem( ITEM &);
        void vDisplayItems();
        int  iGetPrice( string );
        void vDeleteItem( ITEM &);
        void vAdjustMoney( int iAdjMoney){ _iMoney = _iMoney + iAdjMoney; }
       
        //Setters
        void vSetName(string sName){ _sName = sName; }
        void vSetMoney( int iMoney){ _iMoney = iMoney; }
        
        //Getters
        string sGetName(){ return _sName; }
        int    iGetMoney(){ return _iMoney; }
    private:
        string _sName;
        int    _iMoney;
        list<ITEM> _Items;
};
#endif