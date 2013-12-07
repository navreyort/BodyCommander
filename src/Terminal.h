//
//  Terminal.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/6/13.
//
//

#ifndef BodyCommander_Terminal_h
#define BodyCommander_Terminal_h


#include "UIExt.h"
#include <iostream>
#define kMaxLine 12

class Terminal : public UIExt {
    
public:
    Terminal(int x, int y, int w, int h):UIExt(kTerminalName, x, y, w, h){};
    
    ~Terminal(){
        delete textArea;
    };
    
    ofSerial *getSerial() const;
    static Terminal *sharedTerminal();
    void post(string s);
    
protected:
    void uiEvent(ofxUIEventArgs &e);
    void setupBody();
    
private:
    ofxUITextArea *textArea;
    string textString;
    
    static int lineCount(string s);
};

inline void Terminal::setupBody(){
    //string _name, string _textstring, float w, float h = 0,
    textArea = new ofxUITextArea("texts","",510, 120);
    uiCanvas->addWidgetDown(textArea);
}

inline void Terminal::uiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
}

inline int Terminal::lineCount(string s){
    int count = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '\n'){
            count++;
        }
    }
    return count;
}

inline void Terminal::post(string s){
    
    textString += s + "\n";
    if(lineCount(textString) >= kMaxLine){
        size_t found = textString.find("\n");
        textString = textString.substr(found+1,textString.size()-1);
        
    }
    textArea->setTextString(textString);
}

inline Terminal *Terminal::sharedTerminal() {
	static Terminal *terminal = NULL;
	if (terminal == NULL) {
		terminal = new Terminal(kCanvasWidth+4, 267+kCanvasHeight, 532, 168);
        terminal->setup();
	}
	return terminal;
}

#endif
