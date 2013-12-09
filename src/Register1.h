//
//  Register1.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/5/13.
//
//

#ifndef __BodyCommander__Register1__
#define __BodyCommander__Register1__

#include "Register.h"

class Register1 : public Register{

public:
    Register1(int x, int y, int w, int h):Register(kRegister1Name,x,y,w,h){};
    ~Register1(){
        delete datoutList;
        delete lcxtunSlider;
    };
    
protected:
    void uiEvent(ofxUIEventArgs &e);
    void setupBody();
    void setGUIState();
    
private:
    ofxUIDropDownList *datoutList;
    ofxUISlider *lcxtunSlider;
    vector<string> datouts;
};

inline void Register1::setupBody(){
    //List
    datouts.push_back("Demodulated output");datouts.push_back("Carrier clock output");datouts.push_back("RSSI output");
    datoutList = UIExt::createDropDownList(kDatout,datouts,uiCanvas);
    
    //string _name, float _min, float _max, float _value, float w, float h,
    lcxtunSlider = new ofxUISlider(kLcxtun, 0.0f, 63.0f, 0.0f, kCanvasWidth-10, 30);
    uiCanvas->addWidgetDown(lcxtunSlider);
}

inline void Register1::uiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
    
    if(name == kLcxtun){
        Register::receiver_settings->tunecap = (uint8_t) ofMap(((ofxUISlider*) e.widget)->getValue(), 0, 1, 0, 63);
        stringstream sout;
        sout << "LCX Tuning Capacitance bit: " << ((int)Register::receiver_settings->tunecap);
        Terminal::sharedTerminal()->post(sout.str());
    }
    else {
        switch (e.widget->getID()) {
            case 5:{
                Register::receiver_settings->datout = LFDATA_OUTPUT_DEMODULATED;
                break;
            }
            case 7:{
                Register::receiver_settings->datout = LFDATA_OUTPUT_CARRIER;
                break;
            }
            case 9:{
                Register::receiver_settings->datout = LFDATA_OUTPUT_RSSI;
                break;
            }
            case 11:{
                Register::receiver_settings->datout = LFDATA_OUTPUT_BITS_OFFSET;
                break;
            }
            default:
                break;
        }
        
        stringstream sout;
        sout << "LFDATA Output type bit: " << ((int)Register::receiver_settings->datout);
        Terminal::sharedTerminal()->post(sout.str());
    }
}

inline void Register1::setGUIState(){
    lcxtunSlider->setValue(Register::receiver_settings->tunecap);
    
    int index = 0;
    switch (Register::receiver_settings->oel) {
        case LFDATA_OUTPUT_DEMODULATED:
            index = 0;
            break;
        case LFDATA_OUTPUT_CARRIER:
            index = 1;
            break;
        case LFDATA_OUTPUT_RSSI:
            index = 2;
            break;
        case LFDATA_OUTPUT_BITS_OFFSET:
            index = 3;
            break;
        default:
            break;
    }
    datoutList->setLabelText(datouts.at(index));
    datoutList->activateToggle(datouts.at(index));
}

#endif /* defined(__BodyCommander__Register1__) */