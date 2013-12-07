//
//  Register5.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/5/13.
//
//

#ifndef __BodyCommander__Register5__
#define __BodyCommander__Register5__

#include "Register.h"

class Register5 : public Register {
public:
    Register5(int x, int y, int w, int h):Register(kRegister5Name,x,y,w,h){};
    ~Register5(){
        delete modMinList;
    };

protected:
    void uiEvent(ofxUIEventArgs &e);
    void setupBody();

private:
    ofxUIDropDownList *modMinList;
    
};

inline void Register5::setupBody(){
    uiCanvas->addWidgetDown(new ofxUIToggle(kToggleSize, kToggleSize, false, kAgcSig));
    
    vector<string> modMins;
    modMins.push_back("33%");modMins.push_back("60%");modMins.push_back("14%");modMins.push_back("8%");
    modMinList = UIExt::createDropDownList(kModMin,modMins,uiCanvas);
}

inline void Register5::uiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
    
    if(name == kAgcSig){
        if(((ofxUIToggle*)e.widget)->getValue()){
            Register::receiver_settings->agcsig = DEMOD_OUTPUT_AGC_DEPENDENT_ENABLE;
            Terminal::sharedTerminal()->post("Demodulator Output Enable bit enable");
        }
        else {
            Register::receiver_settings->agcsig = DEMOD_OUTPUT_AGC_DEPENDENT_DISABLE;
            Terminal::sharedTerminal()->post("Demodulator Output Enable bit disable");
        }
    }
    else {
        switch (e.widget->getID()) {
            case 6:{
                Register::receiver_settings->modmin = MIN_MOD_DEPTH_33_PCT;
                break;
            }
            case 8:{
                Register::receiver_settings->modmin = MIN_MOD_DEPTH_60_PCT;
                break;
            }
            case 10:{
                Register::receiver_settings->modmin = MIN_MOD_DEPTH_14_PCT;
                break;
            }
            case 12:{
                Register::receiver_settings->modmin = MIN_MOD_DEPTH_8_PCT;
                break;
            }
            default:
                break;
        }
        
        stringstream sout;
        sout << "Minimum Modulation Depth bit: " << ((int)Register::receiver_settings->modmin);
        Terminal::sharedTerminal()->post(sout.str());
    }
}


#endif /* defined(__BodyCommander__Register5__) */
