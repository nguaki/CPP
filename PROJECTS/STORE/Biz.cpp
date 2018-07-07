#include <iostream>
#include <string>
#include "Store.h"
#include "Player.h"
#include "Item.h"

using namespace std;

void vSetPlayer( PLAYER &objPlayer );
void vSetStores( list<STORE> & );
STORE *objDisplayStoreItems(string sStoreName, list<STORE> &listStores);



int
main()
{
    PLAYER       objPlayer;
    list<STORE>  listStores;
    string       sStoreName;
    char         cBS;
    string       sBuyItemName;
    STORE        *objStore;
    int          iTranPrice;
    ITEM         objItem;
    string       sSellItemName;
    
    vSetStores( listStores );
    vSetPlayer( objPlayer );
    
    while(1)
    {
        cout << "Enter store name:";
        //getline(cin,sStoreName, '\n');
        cin >> sStoreName;
        objStore = objDisplayStoreItems(sStoreName, listStores);
        cout << "Welcome to ddd " << objStore->sGetName() << endl;

        cout << "B/S?:";
        cin >> cBS;
        
        if( cBS == 'B')
        {
            cout << "What?";
            cin  >> sBuyItemName;
            iTranPrice = objStore->iPurchaseItem( sBuyItemName, objPlayer.iGetMoney());
            if( iTranPrice != 0 )
            {
                objItem.vInit(sBuyItemName, iTranPrice);
                objPlayer.vAddItem(objItem);
                objPlayer.vAdjustMoney(-iTranPrice);
                objPlayer.vDisplayItems();
            }
        }
        else
        {
            cout << "Sell What?";
            cin >> sSellItemName;
            
            iTranPrice = objPlayer.iGetPrice(sSellItemName);
            if( iTranPrice > 0 )
            {
                objItem.vInit(sSellItemName, iTranPrice);
                objStore->vAddItem(objItem);
                objPlayer.vDeleteItem(objItem);
                objPlayer.vAdjustMoney(iTranPrice);
                objPlayer.vDisplayItems();

            }            
        }
    }
    return 1;
}

STORE * objDisplayStoreItems( string sStoreName, list<STORE> &listStores)
{
    list<STORE>::iterator itStore;
    
    for( itStore = listStores.begin(); itStore != listStores.end(); itStore++)
    {
        if( itStore->sGetName() == sStoreName)
        {
            cout << "Welcome to " << itStore->sGetName() << endl;
            itStore->vDisplayItems();
            
            return &(*itStore);
        }
    }
    cout << "Cannot locate this store." << endl;
}

void vSetStores( list<STORE> &listStores )
{
    STORE objStore;
    ITEM  objItem;
    list<STORE>::iterator itStore;
    
    objStore.vSetName("Chinese");
    listStores.push_back(objStore); 
    objItem.vInit("JanpPong", 10);
    listStores.back().vAddItem( objItem );
    objItem.vInit("JaJaMyung", 15);
    listStores.back().vAddItem( objItem );
    objItem.vInit("PalBoChae", 20);
    listStores.back().vAddItem( objItem );
    
    objStore.vSetName("Japanese");
    listStores.push_back(objStore); 
     objItem.vInit("Tuna", 10);
    listStores.back().vAddItem( objItem );
    objItem.vInit("Salmon", 15);
    listStores.back().vAddItem( objItem );
    objItem.vInit("Salmon", 15);
    listStores.back().vAddItem( objItem );
    objItem.vInit("Salmon", 15);
    listStores.back().vAddItem( objItem );
    objItem.vInit("YellowTail", 20);
    listStores.back().vAddItem( objItem );
    objItem.vInit("YellowTail", 20);
    listStores.back().vAddItem( objItem );
    
    objStore.vSetName("Korean");
    listStores.push_back(objStore); 
    objItem.vInit("KimBob", 20);
    listStores.back().vAddItem( objItem );
    objItem.vInit("KimChi", 20);
    listStores.back().vAddItem( objItem );
    
    for( itStore = listStores.begin(); itStore != listStores.end(); itStore++ )
    {
        itStore->vDisplayItems();
    }

}

void vSetPlayer( PLAYER &objPlayer )
{    
    string sName;
    int    iMoney;
    char   cMore = 'Y';
    ITEM objItem;


    cout << "Please enter your name:" << endl;
    cin >> sName;
    cout << "Please enter your worth in gold coins:" << endl;
    cin >> iMoney;
    objPlayer.vInit(sName,iMoney);
    objItem.vInit( "glove", 20);
   objPlayer.vAddItem(objItem);
   objItem.vInit( "hat", 10);
   objPlayer.vAddItem(objItem);
   objItem.vInit( "shoes", 20);
   objPlayer.vAddItem(objItem);
 /*while( cMore == 'Y' )
    {
        ITEM objItem;
        bool bMore;
        cout << "Enter item name you currently have:";
        cin >> sName;
        cout << "Enter price:";
        cin >> iMoney;
        objItem.vInit(sName,iMoney);
        objPlayer.vAddItem(objItem);
        cout << "More?";
        cin >> cMore;
    }*/
    objPlayer.vDisplayItems();
}