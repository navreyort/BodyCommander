//
//  Register4.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/5/13.
//
//

#ifndef __BodyCommander__Register4__
#define __BodyCommander__Register4__

#include "Register.h"

class Register4 : public Register {
public:
    Register4(int x, int y, int w, int h):Register(kRegister4Name,x,y,w,h){};
    ~Register4(){
        delete lcxsenSlider;
    };
    
protected:
    void uiEvent(ofxUIEventArgs &e);
    void setupBody();
    void setGUIState();
    
private:
    ofxUISlider *lcxsenSlider;
};

inline void Register4::setupBody(){
    //string _name, float _min, float _max, float _value, float w, float h,
    lcxsenSlider = new ofxUISlider(kLcxSen, 0.0f, 15.0f, 0.0f, kCanvasWidth-10, 30);
    uiCanvas->addWidgetDown(lcxsenSlider);
}

inline void Register4::uiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
    if(name == kLcxSen){
        Register::receiver_settings->sensctl = (uint8_t) ofMap(((ofxUISlider*) e.widget)->getValue(), 0, 1, 0, 15);
        stringstream sout;
        sout << "Typical Input Channel (LCX) Sensitivity Reduction bit: " << ((int)Register::receiver_settings->sensctl);
        Terminal::sharedTerminal()->post(sout.str());
    }
}
inline void Register4::setGUIState(){
    lcxsenSlider->setValue(Register::receiver_settings->sensctl);
}
#endif /* defined(__BodyCommander__Register4__) */
