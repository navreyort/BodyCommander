//
//  Register.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/5/13.
//
//

#ifndef __BodyCommander__Register__
#define __BodyCommander__Register__
#include "UIExt.h"
#include "Terminal.h"

class Register : public UIExt {
    
public:
    Register(string name, int x, int y, int w, int h):UIExt(name, x, y, w, h){};
    virtual ~Register(){};

    static SEND_DATA_STRUCTURE *receiver_settings;
    static SEND_DATA_STRUCTURE *sentData;
    static bool checkData();
    static void copyData();
    static bool didSend;
    virtual void setGUIState(){};
    static void print();
    
protected:
    virtual void uiEvent(ofxUIEventArgs &e){};
    virtual void setupBody(){};
    
};

inline bool Register::checkData(){
    Register::didSend = false;
    if((Register::sentData->oeh == Register::receiver_settings->oeh) &&
       (Register::sentData->oel == Register::receiver_settings->oel) &&
        (Register::sentData->alrtind == Register::receiver_settings->alrtind) &&
        (Register::sentData->lcxen == Register::receiver_settings->lcxen) &&
        (Register::sentData->datout == Register::receiver_settings->datout) &&
        (Register::sentData->tunecap == Register::receiver_settings->tunecap) &&
        (Register::sentData->rssifet == Register::receiver_settings->rssifet) &&
        (Register::sentData->clkdiv == Register::receiver_settings->clkdiv) &&
        (Register::sentData->sensctl == Register::receiver_settings->sensctl) &&
        (Register::sentData->agcsig == Register::receiver_settings->agcsig) &&
        (Register::sentData->modmin == Register::receiver_settings->modmin) &&
        (Register::sentData->led == Register::receiver_settings->led)){
        return true;
    }
    return false;
}

inline void Register::copyData(){
    Register::sentData->oeh = Register::receiver_settings->oeh;
    Register::sentData->oel = Register::receiver_settings->oel;
    Register::sentData->alrtind = Register::receiver_settings->alrtind;
    Register::sentData->lcxen = Register::receiver_settings->lcxen;
    Register::sentData->datout = Register::receiver_settings->datout;
    Register::sentData->tunecap = Register::receiver_settings->tunecap;
    Register::sentData->rssifet = Register::receiver_settings->rssifet;
    Register::sentData->clkdiv = Register::receiver_settings->clkdiv;
    Register::sentData->sensctl = Register::receiver_settings->sensctl;
    Register::sentData->agcsig = Register::receiver_settings->agcsig;
    Register::sentData->modmin = Register::receiver_settings->modmin;
    Register::sentData->led = Register::receiver_settings->led;
    
    Register::didSend = true;
}

inline void print(){
    cout << Register::receiver_settings->oeh
    << ((int)Register::receiver_settings->oel)
    << ((int)Register::receiver_settings->alrtind)
    << ((int)Register::receiver_settings->lcxen)
    << ((int)Register::receiver_settings->datout)
    << ((int)Register::receiver_settings->tunecap)
    << ((int)Register::receiver_settings->rssifet)
    << ((int)Register::receiver_settings->clkdiv)
    << ((int)Register::receiver_settings->sensctl)
    << ((int)Register::receiver_settings->agcsig)
    << ((int)Register::receiver_settings->modmin)
    << ((int)Register::receiver_settings->led) << endl;
}

#endif /* defined(__BodyCommander__Register__) */
