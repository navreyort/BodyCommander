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
    void setGUIState();
    
private:
    ofxUIDropDownList *oefhtList;
    ofxUIDropDownList *oefltList;
    ofxUIToggle *alertToggle;
    ofxUIToggle *inputChannelToggle;
    
    vector<string> oefhts;
    vector<string> oeflts;
};

inline void Register0::setupBody(){
    
    //list
    oefhts.push_back("Disable");oefhts.push_back("1ms");oefhts.push_back("2ms");oefhts.push_back("4ms");
    oefhtList = UIExt::createDropDownList(kOEFHT,oefhts,uiCanvas);
    
    //list
    oeflts.push_back("1ms");oeflts.push_back("2ms");oeflts.push_back("4ms");
    oefltList = UIExt::createDropDownList(kOEFLT,oeflts,uiCanvas);
    
    //toggle buttons
    alertToggle = new ofxUIToggle(kToggleSize, kToggleSize, false, kAlertTrigger);
    uiCanvas->addWidgetDown(alertToggle);
    inputChannelToggle = new ofxUIToggle(kToggleSize, kToggleSize, false, kInputChannel);
    uiCanvas->addWidgetRight(inputChannelToggle);
}

inline void Register0::uiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
    int id = e.widget->getID();
    stringstream sout;
    
    cout << id << endl;
    switch (id) {
        case 5:{
            Register::receiver_settings->oeh = OUTPUT_ENABLE_FILTER_HIGH_DISABLED;
            sout << "Output Enable Filter High Time (TOEH) bit: " << ((int)Register::receiver_settings->oeh);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 7:{
            Register::receiver_settings->oeh = OUTPUT_ENABLE_FILTER_HIGH_1MS;
            sout << "Output Enable Filter High Time (TOEH) bit: " << ((int)Register::receiver_settings->oeh);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 9:{
            Register::receiver_settings->oeh = OUTPUT_ENABLE_FILTER_HIGH_2MS;
            sout << "Output Enable Filter High Time (TOEH) bit: " << ((int)Register::receiver_settings->oeh);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 11:{
            Register::receiver_settings->oeh = OUTPUT_ENABLE_FILTER_HIGH_4MS;
            sout << "Output Enable Filter High Time (TOEH) bit: " << ((int)Register::receiver_settings->oeh);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 16:{
            Register::receiver_settings->oel = OUTPUT_ENABLE_FILTER_LOW_1MS;
            sout << "Output Enable Filter Low Time (TOEL) bit: " << ((int)Register::receiver_settings->oel);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 18:{
            Register::receiver_settings->oel = OUTPUT_ENABLE_FILTER_LOW_2MS;
            sout << "Output Enable Filter Low Time (TOEL) bit: " << ((int)Register::receiver_settings->oel);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 20:{
            Register::receiver_settings->oel = OUTPUT_ENABLE_FILTER_LOW_4MS;
            sout << "Output Enable Filter Low Time (TOEL) bit: " << ((int)Register::receiver_settings->oel);
            Terminal::sharedTerminal()->post(sout.str());
            break;
        }
        case 23:{
            if(((ofxUIToggle*)e.widget)->getValue()){
                Register::receiver_settings->alrtind = ALERT_TRIGGER_BY_PARITY_ERROR_OR_ALARM_TIMER;
                Terminal::sharedTerminal()->post("Alert bit by parity error or alarm timer");            }
            else{
                Register::receiver_settings->alrtind = ALERT_TRIGGER_BY_PARITY_ERROR;
                Terminal::sharedTerminal()->post("Alert bit by parity error");
            }
            break;
        }
        case 25:{
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

inline void Register0::setGUIState(){
    int oefhtIndex = 0;
    switch (Register::receiver_settings->oeh) {
        case OUTPUT_ENABLE_FILTER_HIGH_DISABLED:
            oefhtIndex = 0;
            break;
        case OUTPUT_ENABLE_FILTER_HIGH_1MS:
            oefhtIndex = 1;
            break;
        case OUTPUT_ENABLE_FILTER_HIGH_2MS:
            oefhtIndex = 2;
            break;
        case OUTPUT_ENABLE_FILTER_HIGH_4MS:
            oefhtIndex = 3;
            break;
        default:
            break;
    }
    oefhtList->setLabelText(oefhts.at(oefhtIndex));
    oefhtList->activateToggle(oefhts.at(oefhtIndex));
    
    int oefltIndex = 0;
    switch (Register::receiver_settings->oel) {
        case OUTPUT_ENABLE_FILTER_LOW_1MS:
            oefltIndex = 0;
            break;
        case OUTPUT_ENABLE_FILTER_LOW_2MS:
            oefltIndex = 1;
            break;
        case OUTPUT_ENABLE_FILTER_LOW_4MS:
            oefltIndex = 2;
        default:
            break;
    }
    oefltList->setLabelText(oeflts.at(oefltIndex));
    oefltList->activateToggle(oeflts.at(oefltIndex));
    
    if(Register::receiver_settings->alrtind == ALERT_TRIGGER_BY_PARITY_ERROR_OR_ALARM_TIMER){
        alertToggle->setValue(false);
    }
    else {
        alertToggle->setValue(true);
    }
    
    if(Register::receiver_settings->lcxen == INPUT_CHANNEL_DISABLE){
        inputChannelToggle->setValue(false);
    }
    else {
        inputChannelToggle->setValue(true);
    }
}
#endif /* defined(__BodyCommander__OutputEnableFilter__) */
