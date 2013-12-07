//
//  Register.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/5/13.
//
//

#ifndef __BodyCommander__Register__
#define __BodyCommander__Register__
#include "UIExt.h"
#include "Terminal.h"

class Register : public UIExt {
    
public:
    Register(string name, int x, int y, int w, int h):UIExt(name, x, y, w, h){};
    virtual ~Register(){};

    static SEND_DATA_STRUCTURE *receiver_settings;
    
protected:

    virtual void uiEvent(ofxUIEventArgs &e){};
    virtual void setupBody(){};
};

#endif /* defined(__BodyCommander__Register__) */
