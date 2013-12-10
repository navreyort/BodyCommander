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
    
    FaceImagePanel(int x, int y, int w, int h):UIExt("Image Display", x, y, w, h),isDisplaying(false),displayTime(0){};
    
    ~FaceImagePanel(){
        delete img;
    };
    
    void setGUIState();
    
protected:
    void uiEvent(ofxUIEventArgs &e);
    void setupBody();

private:
    ofxUIImage *image;
    ofImage *img;
    string imageName;
    bool isDisplaying;
    double displayTime;
};

inline void FaceImagePanel::setupBody(){
    img = new ofImage();
    img->loadImage("img/David-Cranor.jpg");
    image = new ofxUIImage(img->width*.25, img->height*.25, img, "You are touching");
    uiCanvas->addWidgetDown(image);
    image->setVisible(false);
}

inline void FaceImagePanel::uiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
}

inline void FaceImagePanel::setGUIState(){
    if(SerialSetup::receiver_telemetry->decodedData == kDavidID && imageName != kDavidImg){
        imageName = kDavidImg;
        img->loadImage(kDavidImg);
        image->setVisible(true);
        isDisplaying = true;
    }
    else if(SerialSetup::receiver_telemetry->decodedData == kScottID && imageName != kScottImg){
        imageName = kScottImg;
        img->loadImage(kScottImg);
        image->setVisible(true);
        isDisplaying = true;
    }
    
    if((SerialSetup::receiver_telemetry->decodedData == kDavidID || SerialSetup::receiver_telemetry->decodedData == kScottID)){
        displayTime = ofGetFrameNum();
    }
    
    if((isDisplaying && (ofGetFrameNum() - displayTime > 2*ofGetFrameRate())) || ofGetFrameNum() - SerialSetup::lastReceived > 2*ofGetFrameRate()){
        imageName = "";
        image->setVisible(false);
        displayTime = 0;
        isDisplaying = false;
    }
}

#endif
