//
//  PresetPanel.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/7/13.
//
//

#ifndef BodyCommander_PresetPanel_h
#define BodyCommander_PresetPanel_h

#include "UIExt.h"

#define kNumPresets 2

class RegisterPreset : public UIExt {

public:
    RegisterPreset(vector<Register*> registers, int x, int y, int w, int h):UIExt("Presets",x,y,w,h),registers(registers){
        SEND_DATA_STRUCTURE *preset1 = new SEND_DATA_STRUCTURE();
        preset1->oeh = OUTPUT_ENABLE_FILTER_HIGH_4MS;
        preset1->oel = OUTPUT_ENABLE_FILTER_LOW_4MS;
        preset1->alrtind = ALERT_TRIGGER_BY_PARITY_ERROR_OR_ALARM_TIMER;
        preset1->lcxen = INPUT_CHANNEL_ENABLE;
        preset1->datout = LFDATA_OUTPUT_DEMODULATED;
        preset1->tunecap = 0b1;
        preset1->rssifet = RSSI_PULL_DOWN_OFF;
        preset1->clkdiv = CARRIER_CLOCK_DIVIDE_1;
        preset1->sensctl = INPUT_SENSITIVITY_REDUCTION_0_DB;
        preset1->agcsig = DEMOD_OUTPUT_AGC_DEPENDENT_ENABLE;
        preset1->modmin = MIN_MOD_DEPTH_33_PCT;
        preset1->led = 0x01;
        presets.push_back(preset1);
    };
    ~RegisterPreset(){};
    
protected:
    void uiEvent(ofxUIEventArgs &e);
    void setupBody();
    void setGUIState();
    
private:
    vector<Register*> registers;
    vector<ofxUILabelButton*> presetButtons;
    
    void preset1();
    vector<SEND_DATA_STRUCTURE*> presets;
    
    void copyPresets(int index);
    
};

inline void RegisterPreset::setupBody(){
    uiCanvas->addWidgetDown(new ofxUILabelButton("Preset 1",false));
    uiCanvas->addWidgetDown(new ofxUILabelButton("Preset 2",false));
}

inline void RegisterPreset::uiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
    if(name == "Preset 1"){
        preset1();
    }
    else {
        
    }
}

inline void RegisterPreset::setGUIState(){
    
}

inline void RegisterPreset::preset1(){
    copyPresets(0);
}

inline void RegisterPreset::copyPresets(int index){
    Register::receiver_settings->oeh = presets[index]->oeh;
    Register::receiver_settings->oel = presets[index]->oel;
    Register::receiver_settings->alrtind = presets[index]->alrtind;
    Register::receiver_settings->lcxen = presets[index]->lcxen;
    Register::receiver_settings->datout = presets[index]->datout;
    Register::receiver_settings->tunecap = presets[index]->tunecap;
    Register::receiver_settings->rssifet = presets[index]->rssifet;
    Register::receiver_settings->clkdiv = presets[index]->clkdiv;
    Register::receiver_settings->sensctl = presets[index]->sensctl;
    Register::receiver_settings->agcsig = presets[index]->agcsig;
    Register::receiver_settings->modmin = presets[index]->modmin;
    Register::receiver_settings->led = presets[index]->led;
}

#endif