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
        delete agcSigToggle;
    };

protected:
    void uiEvent(ofxUIEventArgs &e);
    void setupBody();
    void setGUIState();
    
private:
    ofxUIDropDownList *modMinList;
    vector<string> modMins;
    ofxUIToggle *agcSigToggle;
};

inline void Register5::setupBody(){
    agcSigToggle = new ofxUIToggle(kToggleSize, kToggleSize, false, kAgcSig);
    uiCanvas->addWidgetDown(agcSigToggle);
    
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
        cout << e.widget->getID() << endl;
        switch (e.widget->getID()) {
            case 7:{
                Register::receiver_settings->modmin = MIN_MOD_DEPTH_33_PCT;
                break;
            }
            case 9:{
                Register::receiver_settings->modmin = MIN_MOD_DEPTH_60_PCT;
                break;
            }
            case 11:{
                Register::receiver_settings->modmin = MIN_MOD_DEPTH_14_PCT;
                break;
            }
            case 13:{
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

inline void Register5::setGUIState(){
    
    if(Register::receiver_settings->agcsig == DEMOD_OUTPUT_AGC_DEPENDENT_ENABLE){
        agcSigToggle->setValue(true);
        agcSigToggle->setState(1);
    }
    else {
        agcSigToggle->setValue(false);
        agcSigToggle->setState(0);
    }
    
    int index = 0;
    switch (Register::receiver_settings->modmin) {
        case MIN_MOD_DEPTH_33_PCT:
            index = 0;
            break;
        case MIN_MOD_DEPTH_60_PCT:
            index = 1;
            break;
        case MIN_MOD_DEPTH_14_PCT:
            index = 2;
            break;
        case MIN_MOD_DEPTH_8_PCT:
            index = 3;
            break;
        default:
            break;
    }
    modMinList->setLabelText(modMins.at(index));
    modMinList->activateToggle(modMins.at(index));
}
#endif /* defined(__BodyCommander__Register5__) */
