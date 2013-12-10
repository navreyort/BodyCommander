//
//  OscSetup.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/10/13.
//
//

#ifndef BodyCommander_OscSetup_h
#define BodyCommander_OscSetup_h


#include "UIExt.h"

class OscSetup : public UIExt {
public:
    OscSetup(int x, int y, int w, int h):UIExt(kSerialSetupName, x, y, w, h){};
    
    ~OscSetup(){
        
    };
    
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
    ofxUIToggle *led;
    
    void write();
    void threadedFunction();
    
};

#endif
