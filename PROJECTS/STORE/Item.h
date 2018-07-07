#ifndef _ITEM_H
#define _ITEM_H

#include <string>
using namespace std;
class ITEM
{
    public:
        //ITEM( string sName, int iPrice ){ vSetName(sName); vSetPrice(iPrice); }
        void vInit( string, int);
        //Getter
        string sGetName(){ return _sName; }
        int    iGetPrice(){ return _iPrice; }
        int    iGetCnt(){ return _iCnt; }
        //Setter
        void vSetName(string sName ){ _sName = sName; }
        void vSetPrice( int iPrice ){ _iPrice = iPrice; }
        void vAddCnt(){ _iCnt++; }
        void vSubCnt(){ cout << "Subtracting an item" << endl; _iCnt--; }
    private:
        string _sName;
        int    _iPrice;
        int    _iCnt;
};
#endif