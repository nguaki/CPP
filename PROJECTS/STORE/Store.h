#ifndef __STORE_H
#define __STORE_H

#include <string>
#include <list>
#include "Item.h"
using namespace std;

class STORE
{
    public:
    
        int iPurchaseItem(string, int);
        //setters
        void vSetName( string sName ){ _sName = sName; }
        void vAddItem( ITEM & );
        //getters
        string sGetName(){ return _sName; }
        void   vDisplayItems();
    private:
        string _sName;
        list<ITEM> _listItems;
};
#endif