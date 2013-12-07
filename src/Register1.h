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
    
private:
    ofxUIDropDownList *datoutList;
    ofxUISlider *lcxtunSlider;
    
    //Status variables
    Byte curDatout;
    Byte curLcxtun;
};

inline void Register1::setupBody(){
    //List
    vector<string> datouts;
    datouts.push_back("Demodulated output");datouts.push_back("Carrier clock output");datouts.push_back("RSSI output");
    datoutList = UIExt::createDropDownList(kDatout,datouts,uiCanvas);
    
    //string _name, float _min, float _max, float _value, float w, float h,
    lcxtunSlider = new ofxUISlider(kLcxtun, 0.0f, 5.0f, 0.0f, kCanvasWidth-10, 30);
    uiCanvas->addWidgetDown(lcxtunSlider);
}

inline void Register1::uiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
    
    if(name == kLcxtun){
        Register::receiver_settings->tunecap = (uint8_t) ofMap(((ofxUISlider*) e.widget)->getValue(), 0, 1, 0, 5);
        stringstream sout;
        sout << "LCX Tuning Capacitance bit: " << ((int)Register::receiver_settings->tunecap);
        Terminal::sharedTerminal()->post(sout.str());
    }
    else {
        switch (e.widget->getID()) {
            case 6:{
                Register::receiver_settings->datout = LFDATA_OUTPUT_DEMODULATED;
                break;
            }
            case 8:{
                Register::receiver_settings->datout = LFDATA_OUTPUT_CARRIER;
                break;
            }
            case 10:{
                Register::receiver_settings->datout = LFDATA_OUTPUT_RSSI;
                break;
            }
            case 12:{
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

#endif /* defined(__BodyCommander__Register1__) */