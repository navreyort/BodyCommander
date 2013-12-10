//
//  FaceImagePanel.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/7/13.
//
//

#ifndef BodyCommander_FaceImagePanel_h
#define BodyCommander_FaceImagePanel_h

#include "UIExt.h"

class FaceImagePanel : public UIExt {
    
public:
    
    FaceImagePanel(int x, int y, int w, int h):UIExt("Image Display", x, y, w, h){};
    
    ~FaceImagePanel(){
        delete img;
    };
    
protected:
    void uiEvent(ofxUIEventArgs &e);
    void setupBody();
    void setGUIState();

private:
    ofxUIImage *image;
    ofImage *img;
};

inline void FaceImagePanel::setupBody(){
    img = new ofImage();
    img->loadImage("img/David-Cranor.jpg");
    img->loadImage("img/Obama_portrait_crop.jpg");
    image = new ofxUIImage(img->width*.25, img->height*.25, img, "You are touching");
    uiCanvas->addWidgetDown(image);
}

inline void FaceImagePanel::uiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
}

inline void FaceImagePanel::setGUIState(){
    if(SerialSetup::receiver_telemetry->decodedData == kDavidID){
        //img->loadImage();
    }
    else if(SerialSetup::receiver_telemetry->decodedData == kScottID){
        
    }
    else {
        
    }

}

#endif
