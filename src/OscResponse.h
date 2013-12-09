//
//  OscResponse.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/8/13.
//
//

#ifndef BodyCommander_OscResponse_h
#define BodyCommander_OscResponse_h

#include "Constants.h"
#include "ofxOsc.h"

class OscResponse {
    
public:

    OscResponse(){
        // open an outgoing connection to HOST:PORT
        sender.setup( kOscHost, kOscPort );
    };
    
    ~OscResponse(){};
    
    void sendMessage(u_int16_t number){
        ofxOscMessage m;
        m.setAddress(kOscTag);
        m.addIntArg(number);
        sender.sendMessage(m);
    };
    
private:
    ofxOscSender sender;
};

#endif
