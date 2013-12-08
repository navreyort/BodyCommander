//
//  Register7.h
//  BodyCommander
//
//  Created by Akito van Troyer on 17/5/13.
//
//

#ifndef __BodyCommander__Register7__
#define __BodyCommander__Register7__

#include "Register.h"

class Register7 : public Register {
public:
    Register7(int x, int y, int w, int h):Register(kRegister7Name,x,y,w,h){};
    ~Register7(){};
    
protected:
    void uiEvent(ofxUIEventArgs &e);
    void setupBody();
    void setGUIState();
    
private:
    vector<string> registerNames;
};

inline void Register7::setupBody(){
    registerNames.push_back(kChzact);registerNames.push_back(kChyact);registerNames.push_back(kChxact);
    registerNames.push_back(kAgcAct);registerNames.push_back(kWakex);registerNames.push_back(kAlarm);
    registerNames.push_back(kPei);
    
    for (int i=0; i<7; i++) {
        if(i % 3 != 0){
            uiCanvas->addWidgetRight(new ofxUIToggle(kToggleSize, kToggleSize, false, registerNames[i]));
        }
        else{
            uiCanvas->addWidgetDown(new ofxUIToggle(kToggleSize, kToggleSize, false, registerNames[i]));
        }
    }
}

inline void Register7::uiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
}

inline void Register7::setGUIState(){}
#endif /* defined(__BodyCommander__Register7__) */
