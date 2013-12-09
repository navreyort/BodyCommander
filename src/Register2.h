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
    void setGUIState();
    
private:
    ofxUIToggle *rssiToggle;
    ofxUIToggle *clkDivToggle;
};

inline void Register2::setupBody(){
    rssiToggle = new ofxUIToggle(kToggleSize, kToggleSize, false, kRssiFet);
    uiCanvas->addWidgetDown(rssiToggle);
    clkDivToggle = new ofxUIToggle(kToggleSize, kToggleSize, false, kClkDiv);
    uiCanvas->addWidgetRight(clkDivToggle);
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

inline void Register2::setGUIState(){

    if(Register::receiver_settings->rssifet == RSSI_PULL_DOWN_ON){
        rssiToggle->setValue(true);
        rssiToggle->setState(1);
    }
    else {
        rssiToggle->setValue(false);
        rssiToggle->setState(0);
    }
    
    if(Register::receiver_settings->clkdiv == CARRIER_CLOCK_DIVIDE_4){
        clkDivToggle->setValue(true);
        clkDivToggle->setState(1);
    }
    else {
        clkDivToggle->setValue(false);
        clkDivToggle->setState(0);
    }
}
#endif /* defined(__BodyCommander__Register2__) */
