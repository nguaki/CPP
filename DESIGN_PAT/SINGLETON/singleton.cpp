///////////////////////////////////////////////////////////////////////////////
// June 25, 2018
//
// Demonstration of singleton pattern. 
// This compile option is  needed to compile nullptr: -std=c++0x 
//
//          |-----------------------|
//          | - static instance     |   <--------------  Call getInstance
//          |-----------------------|
//          | + static getInstance()|
//          |-----------------------|
//
// 
//Note that singleton can be used in DB connection, log file, Video Setting.
//
//OUTPUT
//400    
//200    
//100   
//400     <-- Shows that this is same object.
//200    
//1000 
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class Setting{
    int _iWidth;
    int _iHeight;
    int _iBrightness;
    static Setting *_instanceSetting;
    
    public:
        static Setting * getInstance(){
            if( _instanceSetting == nullptr )
                _instanceSetting = new Setting;
                return _instanceSetting;
        }
                
        void vSetiWidth(int  iWidth ){ _iWidth = iWidth; }
        void vSetiHeight(int iHeight ){ _iHeight = iHeight; };
        void vSetiBrightness(int  iBrightness ){ _iBrightness = iBrightness; };
       void vDisp(){ cout << _iWidth << "    " << endl
                          << _iHeight << "    " << endl
                          << _iBrightness << "   "  << endl;
                   }
};

Setting * Setting::_instanceSetting = nullptr;

void
vSomeFunc()
{
    Setting *objSetting = Setting::getInstance();
    objSetting->vSetiBrightness(1000); 
    //Shows that same object is used.
    objSetting->vDisp();
}
int
main(void)
{
    Setting *objSetting = Setting::getInstance();
    
    objSetting->vSetiBrightness(100);
    objSetting->vSetiHeight(200);
    objSetting->vSetiWidth(400);
    
    objSetting->vDisp();
    
    vSomeFunc();
    
    return 0;
}