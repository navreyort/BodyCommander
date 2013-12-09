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
#include "OscResponse.h"

class SerialSetup : public UIExt {

public:
    SerialSetup(vector<Register*> registers, int x, int y, int w, int h):UIExt(kSerialSetupName, x, y, w, h),registers(registers){
        oscResponse = new OscResponse();
    };
    
    ~SerialSetup(){
        serial->close();
        delete serial;
        delete portList;
    };

    ofSerial *getSerial() const;
    void receiveCycle();
    
    static TELEMETRY_DATA_STRUCTURE *receiver_telemetry;
    
protected:
    void uiEvent(ofxUIEventArgs &e);
    void setupBody();
    void setGUIState();
    
private:
    string curPort;
    int curRate;
    vector <string> devices;
    ofSerial *serial;
    ofxUIDropDownList *portList;
    EasyTransfer ET;
    EasyTransfer ET2;
    bool serialConnected;
    vector<Register*> registers;
    OscResponse *oscResponse;
    
    void write();
};

inline void SerialSetup::setupBody(){
    //Serial Device list
    serial = new ofSerial();
    //serial->flush();
    vector <ofSerialDeviceInfo> deviceList = serial->getDeviceList();
    for (int i=0; i<deviceList.size(); i++) {
        devices.push_back(deviceList.at(i).getDeviceName());
    }
    portList = UIExt::createDropDownList("Port",devices,uiCanvas);
    curPort = devices.at(0);
    
    //Serial rate
    vector <string> rates;
    rates.push_back("9600");rates.push_back("14400");rates.push_back("19200");rates.push_back("28800");
    rates.push_back("38400");rates.push_back("57600");rates.push_back("115200");
    UIExt::createDropDownList("Rate",rates,uiCanvas);
    curRate = atoi(rates.at(0).c_str());
    
    //Connect and refresh Button
    uiCanvas->addWidgetDown(new ofxUILabelButton("Connect",false));
    uiCanvas->addWidgetRight(new ofxUILabelButton("Refresh",false));
    uiCanvas->addWidgetRight(new ofxUILabelButton("Write",false));
    uiCanvas->addWidgetRight(new ofxUIToggle(kToggleSize, kToggleSize, false, "LED"));
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
                ET.begin((uint8_t*)Register::receiver_settings, sizeof(*Register::receiver_settings), serial);
                ET2.begin((uint8_t*)SerialSetup::receiver_telemetry, sizeof(*SerialSetup::receiver_telemetry), serial);
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
        //serial->flush();
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
    else if(name == "LED"){
        if(((ofxUIToggle*)e.widget)->getValue()){
            Register::receiver_settings->led = 0x01;
            //Terminal::sharedTerminal()->post("LED on");
        }
        else {
            Register::receiver_settings->led = 0x00;
            //Terminal::sharedTerminal()->post("LED off");
        }
        
        //cout << "LED: " << ((int) Register::receiver_settings->led) << endl;
    }
}

inline void SerialSetup::setGUIState(){

}

inline void SerialSetup::receiveCycle(){
    while(serial &&  serial->isInitialized() && serial->available() > 3){
        if(Register::didSend){
            if(ET.receiveData()){
                if(Register::checkData()){
                    Terminal::sharedTerminal()->post("Data returned is the same!");
                    //Populate UI
                    for (int i=0; i<registers.size(); i++) {
                        registers[i]->setGUIState();
                    }
                }
                else{
                    Terminal::sharedTerminal()->post("Data returned is not the same :(");
                }
            }
        }
        else {
            if(ET2.receiveData()){
                //TODO display data from the board
                //cout << receiver_telemetry->decodedData << endl;
                oscResponse->sendMessage(receiver_telemetry->decodedData);
                //serial->flush();
            }
        }
    }
}

inline void SerialSetup::write() {
    Register::copyData();
    ET.sendData();
}

inline ofSerial *SerialSetup::getSerial() const{
    return serial;
}

#endif /* defined(__BodyCommander__SerialSetup__) */