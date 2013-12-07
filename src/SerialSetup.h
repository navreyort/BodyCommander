//
//  SerialSetup.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/5/13.
//
//

#ifndef __BodyCommander__SerialSetup__
#define __BodyCommander__SerialSetup__

#include "UIExt.h"
#include "EasyTransfer.h"
#include "Register.h"
#include "Terminal.h"

class SerialSetup : public UIExt {

public:
    SerialSetup(int x, int y, int w, int h):UIExt(kSerialSetupName, x, y, w, h){};
    
    ~SerialSetup(){
        serial->close();
        delete serial;
        delete portList;
    };

    ofSerial *getSerial() const;
    
protected:
    void uiEvent(ofxUIEventArgs &e);
    void setupBody();
    
private:
    string curPort;
    int curRate;
    vector <string> devices;
    ofSerial *serial;
    ofxUIDropDownList *portList;
    EasyTransfer ET;
    bool serialConnected;
    
    void write();
};

inline void SerialSetup::setupBody(){
    //Serial Device list
    serial = new ofSerial();
    vector <ofSerialDeviceInfo> deviceList = serial->getDeviceList();
    for (int i=0; i<deviceList.size(); i++) {
        devices.push_back(deviceList.at(i).getDeviceName());
    }
    portList = UIExt::createDropDownList("Port",devices,uiCanvas);
    curPort = devices.at(0);
    
    //Serial rate
    vector <string> rates;
    rates.push_back("9600");rates.push_back("14400");rates.push_back("19200");rates.push_back("28800");
    UIExt::createDropDownList("Rate",rates,uiCanvas);
    curRate = atoi(rates.at(0).c_str());
    
    //Connect and refresh Button
    uiCanvas->addWidgetDown(new ofxUILabelButton("Connect",false));
    uiCanvas->addWidgetRight(new ofxUILabelButton("Refresh",false));
    uiCanvas->addWidgetRight(new ofxUILabelButton("Write",false));
}

inline void SerialSetup::uiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
    if(name == "Port"){
        vector<ofxUIWidget *> &selected = ((ofxUIDropDownList*)e.widget)->getSelected();
        if (selected.size()) {
            curPort = selected[0]->getName();
            cout << curPort << endl;
        }
    }
    else if(name == "Rate"){
        vector<ofxUIWidget *> &selected = ((ofxUIDropDownList*)e.widget)->getSelected();
        if (selected.size()) {
            curRate = atoi(selected[0]->getName().c_str());
            cout << curRate << endl;
        }
    }
    else if(name == "Connect"){
        if (!serial->isInitialized()) {
            serialConnected = serial->setup(curPort, curRate);
            if(serialConnected){
                ET.begin((uint8_t*)Register::receiver_settings, 256, serial);
            }
            else {
                Terminal::sharedTerminal()->post("Can't Initialize Serial");
            }
        }
    }
    else if(name == "Refresh"){
        serial->close();
        delete serial;
        serial = new ofSerial();
        vector <ofSerialDeviceInfo> deviceList = serial->getDeviceList();
        devices.clear();
        for (int i=0; i<deviceList.size(); i++) {
            devices.push_back(deviceList.at(i).getDeviceName());
        }
        portList->clearToggles();
        portList->addToggles(devices);
        for (int i=0; i<portList->getToggles().size(); i++) {
            ofxUILabelToggle *toggle = portList->getToggles().at(i);
            toggle->setColorBack(ofColor(150));
        }
    }
    else if(name == "Write"){
        write();
    }
}

inline void SerialSetup::write() {
    ET.sendData();
}

inline ofSerial *SerialSetup::getSerial() const{
    return serial;
}

#endif /* defined(__BodyCommander__SerialSetup__) */