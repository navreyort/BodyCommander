//
//  OutputEnableFilter.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/5/13.
//
//

#ifndef __BodyCommander__OutputEnableFilter__
#define __BodyCommander__OutputEnableFilter__

#include "Register.h"

class Register0 : public Register {
public:
    Register0(int x, int y, int w, int h):Register(kRegister0Name,x,y,w,h){};
    
    ~Register0(){
        delete oefhtList;
        delete oefltList;
    };
   
protected:
    void uiEvent(ofxUIEventArgs &e);
    void setupBody();
    
private:
    ofxUIDropDownList *oefhtList;
    ofxUIDropDownList *oefltList;
};

inline void Register0::setupBody(){
    
    //list
    vector<string> oefhts;
    oefhts.push_back("Disable");oefhts.push_back("1ms");oefhts.push_back("2ms");oefhts.push_back("4ms");
    oefhtList = UIExt::createDropDownList(kOEFHT,oefhts,uiCanvas);
    
    //list
    vector<string> oeflts;
    oeflts.push_back("1ms");oeflts.push_back("2ms");oeflts.push_back("4ms");
    oefhtList = UIExt::createDropDownList(kOEFLT,oeflts,uiCanvas);
    
    //toggle buttons
    uiCanvas->addWidgetDown(new ofxUIToggle(kToggleSize, kToggleSize, false, kAlertTrigger));
    uiCanvas->addWidgetRight(new ofxUIToggle(kToggleSize, kToggleSize, false, kInputChannel));
}

inline void Register0::uiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
    int id = e.widget->getID();
    stringstream sout;
    
    switch (id) {
        case 6:{
            Register::receiver_settings->oeh = OUTPUT_ENABLE_FILTER_HIGH_DISABLED;
            sout << "Output Enable Filter High Time (TOEH) bit: " << ((int)Register::receiver_settings->oeh);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 8:{
            Register::receiver_settings->oeh = OUTPUT_ENABLE_FILTER_HIGH_1MS;
            sout << "Output Enable Filter High Time (TOEH) bit: " << ((int)Register::receiver_settings->oeh);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 10:{
            Register::receiver_settings->oeh = OUTPUT_ENABLE_FILTER_HIGH_2MS;
            sout << "Output Enable Filter High Time (TOEH) bit: " << ((int)Register::receiver_settings->oeh);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 12:{
            Register::receiver_settings->oeh = OUTPUT_ENABLE_FILTER_HIGH_4MS;
            sout << "Output Enable Filter High Time (TOEH) bit: " << ((int)Register::receiver_settings->oeh);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 15:{
            Register::receiver_settings->oel = OUTPUT_ENABLE_FILTER_LOW_1MS;
            sout << "Output Enable Filter Low Time (TOEL) bit: " << ((int)Register::receiver_settings->oeh);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 17:{
            Register::receiver_settings->oel = OUTPUT_ENABLE_FILTER_LOW_2MS;
            sout << "Output Enable Filter Low Time (TOEL) bit: " << ((int)Register::receiver_settings->oeh);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 19:{
            Register::receiver_settings->oel = OUTPUT_ENABLE_FILTER_LOW_4MS;
            sout << "Output Enable Filter Low Time (TOEL) bit: " << ((int)Register::receiver_settings->oeh);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 24:{
            if(((ofxUIToggle*)e.widget)->getValue()){
                Register::receiver_settings->alrtind = ALERT_TRIGGER_BY_PARITY_ERROR_OR_ALARM_TIMER;
                Terminal::sharedTerminal()->post("Alert bit by parity error or alarm timer");            }
            else{
                Register::receiver_settings->alrtind = ALERT_TRIGGER_BY_PARITY_ERROR;
                Terminal::sharedTerminal()->post("Alert bit by parity error");
            }
            break;
        }
        case 26:{
            if(((ofxUIToggle*)e.widget)->getValue()){
                Register::receiver_settings->lcxen = INPUT_CHANNEL_DISABLE;
                Terminal::sharedTerminal()->post("Input channel disable");
            }
            else{
                Register::receiver_settings->lcxen = INPUT_CHANNEL_ENABLE;
                Terminal::sharedTerminal()->post("Input channel enable");
            }
            break;
        }
        default:
            break;
    }
}

#endif /* defined(__BodyCommander__OutputEnableFilter__) */
