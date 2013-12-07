//
//  Register2.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/5/13.
//
//

#ifndef __BodyCommander__Register2__
#define __BodyCommander__Register2__

#include "Register.h"

class Register2 : public Register {
public:
    Register2(int x, int y, int w, int h):Register(kRegister2Name,x,y,w,h){};
    ~Register2(){};
    
protected:
    void uiEvent(ofxUIEventArgs &e);
    void setupBody();
};

inline void Register2::setupBody(){
    uiCanvas->addWidgetDown(new ofxUIToggle(kToggleSize, kToggleSize, false, kRssiFet));
    uiCanvas->addWidgetRight(new ofxUIToggle(kToggleSize, kToggleSize, false, kClkDiv));
}

inline void Register2::uiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
    
    if(name == kRssiFet){
        if(((ofxUIToggle*)e.widget)->getValue()){
            Register::receiver_settings->rssifet = RSSI_PULL_DOWN_ON;
            Terminal::sharedTerminal()->post("RSSI pull down on");
        }
        else {
            Register::receiver_settings->rssifet = RSSI_PULL_DOWN_OFF;
            Terminal::sharedTerminal()->post("RSSI pull down off");
        }
    }
    else {
        if(((ofxUIToggle*)e.widget)->getValue()){
            Register::receiver_settings->clkdiv = CARRIER_CLOCK_DIVIDE_4;
            Terminal::sharedTerminal()->post("Carrier clock divide 4");
        }
        else {
            Register::receiver_settings->clkdiv = CARRIER_CLOCK_DIVIDE_1;
            Terminal::sharedTerminal()->post("Carrier clock divide 1");
        }
    }
}

#endif /* defined(__BodyCommander__Register2__) */
