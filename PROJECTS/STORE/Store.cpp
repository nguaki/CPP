#include <iostream>
#include "Store.h"
using namespace std;

void
STORE::vDisplayItems()
{
    list<ITEM>::iterator itItems;
    cout << "========================================================" << endl;
    cout << _sName << endl;
    for( itItems = _listItems.begin(); itItems != _listItems.end(); itItems++ )
    {
        cout << itItems->sGetName() << "   "  << itItems->iGetPrice() << "  " << itItems->iGetCnt() << endl;
    }
    cout << "========================================================" << endl;
}

void 
STORE::vAddItem( ITEM &objItem )
{
    list<ITEM>::iterator itItems;

    for( itItems = _listItems.begin(); itItems != _listItems.end(); itItems++ )
    {
        if( itItems->sGetName() == objItem.sGetName())
        {   
            itItems->vAddCnt();
            return;
        }
    }
    _listItems.push_back(objItem);
}

int STORE::iPurchaseItem(string sItemName, int iPlayerMoney)
{
    list<ITEM>::iterator itItems;

    for( itItems = _listItems.begin(); itItems != _listItems.end(); itItems++ )
    {
        if( itItems->sGetName() == sItemName )
        {   
            if( iPlayerMoney >= itItems->iGetPrice() )
            {
                cout << "Selling " << sItemName << endl;
                itItems->vSubCnt();
                if( itItems->iGetCnt() == 0)
                    _listItems.erase(itItems);
                return itItems->iGetPrice();
            }
            else
            {
                cout << "Not enough money!" << endl;
                return 0;
            }
            
        }
    }
    cout << "Such item does not exists:" << endl;
    return 0;
}