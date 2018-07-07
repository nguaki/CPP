#include <iostream>
#include <list>

#include "Player.h"
#include "Item.h"
using namespace std;

void 
PLAYER::vAddItem( ITEM &objItem )
{
    list<ITEM>::iterator itItem;

    for( itItem = _Items.begin(); itItem != _Items.end(); itItem++)
    {
        if( itItem->sGetName() == objItem.sGetName())
        {
            itItem->vAddCnt();
            return;
        }
    }
    _Items.push_back(objItem);
}

void
PLAYER::vDisplayItems()
{
    list<ITEM>::iterator itItem;
    cout << "========================================================" << endl;
    cout << "NAME:" << _sName << endl;
    cout << "TOTAL MONEY:" << _iMoney << endl;
    
    for( itItem = _Items.begin(); itItem != _Items.end(); itItem++)
    {
        cout << itItem->sGetName() << "  " << itItem->iGetCnt() << "  "  << itItem->iGetPrice() << endl;
    }
    cout << "========================================================" << endl;

}

int
PLAYER::iGetPrice( string sItemName)
{
    list<ITEM>::iterator itItem;
    cout << "========================================================" << endl;
    cout << "NAME:" << _sName << endl;
    cout << "TOTAL MONEY:" << _iMoney << endl;
    
    for( itItem = _Items.begin(); itItem != _Items.end(); itItem++)
    {
        if( itItem->sGetName() == sItemName )
          return itItem->iGetPrice();
    }
    cout << "========================================================" << endl;
    
    return 0;

}

void
PLAYER::vDeleteItem( ITEM &objItem )
{
    list<ITEM>::iterator itItems;

    for( itItems = _Items.begin(); itItems != _Items.end(); itItems++ )
    {

        if( itItems->sGetName() == objItem.sGetName() )
        {   
                cout << "Selling " << itItems->sGetName() << endl;
                itItems->vSubCnt();
                if( itItems->iGetCnt() == 0)
                    _Items.erase(itItems);
                return;
        }
    }
}