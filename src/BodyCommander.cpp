#include "BodyCommander.h"

//--------------------------------------------------------------
void BodyCommander::setup(){
    gui = new ofxUICanvas(0,0,320,320);		//ofxUICanvas(float x, float y, float width, float height)
    gui->addWidgetDown(new ofxUILabel("OFXUI TUTORIAL", OFX_UI_FONT_LARGE));
    gui->addWidgetDown(new ofxUISlider(304,16,0.0,255.0,100.0,"BACKGROUND VALUE"));
    gui->addWidgetDown(new ofxUIToggle(32, 32, false, "FULLSCREEN"));
    ofAddListener(gui->newGUIEvent, this, &BodyCommander::guiEvent);
    gui->loadSettings("GUI/guiSettings.xml");
}

//--------------------------------------------------------------
void BodyCommander::update(){

}

//--------------------------------------------------------------
void BodyCommander::draw(){

}

//--------------------------------------------------------------
void BodyCommander::keyPressed(int key){

}

//--------------------------------------------------------------
void BodyCommander::keyReleased(int key){

}

//--------------------------------------------------------------
void BodyCommander::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void BodyCommander::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void BodyCommander::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void BodyCommander::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void BodyCommander::windowResized(int w, int h){

}

//--------------------------------------------------------------
void BodyCommander::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void BodyCommander::dragEvent(ofDragInfo dragInfo){ 

}
//--------------------------------------------------------------
void BodyCommander::exit(){
	gui->saveSettings("GUI/guiSettings.xml");
    delete gui;
}
//--------------------------------------------------------------
void BodyCommander::guiEvent(ofxUIEventArgs &e){
	if(e.widget->getName() == "BACKGROUND VALUE"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        ofBackground(slider->getScaledValue());
    }
    else if(e.widget->getName() == "FULLSCREEN")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        ofSetFullscreen(toggle->getValue());
    }
}