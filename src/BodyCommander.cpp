#include "BodyCommander.h"

//--------------------------------------------------------------
void BodyCommander::setup(){
    
    terminal = Terminal::sharedTerminal();
    
    serialSetup = new SerialSetup(kCanvasWidth+4, 437+kCanvasHeight, 532, kCanvasHeight);
    serialSetup->setup();
    
    registers.push_back(new Register0(2,2,kCanvasWidth,kCanvasHeight));
    registers.push_back(new Register1(2,kCanvasHeight+4,kCanvasWidth,140));
    registers.push_back(new Register2(2,140+kCanvasHeight+6,kCanvasWidth,80));
    registers.push_back(new Register4(2,220+kCanvasHeight+8,kCanvasWidth,100));
    registers.push_back(new Register5(2,320+kCanvasHeight+10,kCanvasWidth,120));
    registers.push_back(new Register7(2,440+kCanvasHeight+12,kCanvasWidth,150));
    
    for (int i=0; i<registers.size(); i++) {
        registers[i]->setup();
    }
}

//--------------------------------------------------------------
void BodyCommander::update(){
}

//--------------------------------------------------------------
void BodyCommander::draw(){
    ofBackground(100);
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
}
//--------------------------------------------------------------
void BodyCommander::guiEvent(ofxUIEventArgs &e){
//	if(e.widget->getName() == "BACKGROUND VALUE"){
//        ofxUISlider *slider = (ofxUISlider *) e.widget;
//        ofBackground(slider->getScaledValue());
//    }
//    else if(e.widget->getName() == "FULLSCREEN")
//    {
//        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
//        ofSetFullscreen(toggle->getValue());
//    }
}