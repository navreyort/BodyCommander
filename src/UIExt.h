//
//  DropDownList.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/5/13.
//
//

#ifndef BodyCommander_DropDownList_h
#define BodyCommander_DropDownList_h

#include "ofMain.h"
#include "ofxUI.h"
#include "Constants.h"

typedef struct GUIProperty {
    int x;
    int y;
    int w;
    int h;
    GUIProperty(int x, int y, int w, int h):x(x),y(y),w(w),h(h){};
} GUIProperty;

class UIExt {
public:
    static ofxUIDropDownList *createDropDownList(string name, vector<string>items, ofxUICanvas *uiCanvas);

public:
    UIExt(string name, int x, int y, int w, int h):name(name){
        property = new GUIProperty(x,y,w,h);
    };
    
    virtual ~UIExt(){
        uiCanvas->saveSettings("GUI/"+name);
        delete uiCanvas;
    };
    
    void setup(){
        uiCanvas = new ofxUICanvas(property->x,property->y,property->w,property->h);
        uiCanvas->addWidgetDown(new ofxUILabel(name, OFX_UI_FONT_LARGE));
        
        uiCanvas->addSpacer();
        uiCanvas->addSpacer();
        
        this->setupBody();
        
        ofAddListener(uiCanvas->newGUIEvent, this, &UIExt::uiEvent);
        uiCanvas->loadSettings("GUI/"+name);
    };
    
protected:
    ofxUICanvas *uiCanvas;
    string name;
    
    virtual void uiEvent(ofxUIEventArgs &e){};
    virtual void setupBody(){};
private:
    GUIProperty *property;
};

inline ofxUIDropDownList *UIExt::createDropDownList(string name, vector<string>items, ofxUICanvas *uiCanvas){
    uiCanvas->addWidgetDown(new ofxUILabel(name, OFX_UI_FONT_MEDIUM));
    
    ofxUIDropDownList *list = new ofxUIDropDownList(name,items,kCanvasWidth-10);
    uiCanvas->addWidgetDown(list);
    
    for (int i=0; i<list->getToggles().size(); i++) {
        ofxUILabelToggle *toggle = list->getToggles().at(i);
        toggle->setColorBack(ofColor(150));
    }
    
    list->setAllowMultiple(false);
    list->setShowCurrentSelected(true);
    list->setAutoClose(true);
    list->setLabelText(items.at(0));
    list->activateToggle(items.at(0));
    
    return list;
}
#endif
