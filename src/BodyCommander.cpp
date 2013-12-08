#include "BodyCommander.h"

//--------------------------------------------------------------
void BodyCommander::setup(){
    
    terminal = Terminal::sharedTerminal();
    
    registers.push_back(new Register0(kSpacing,kSpacing,kCanvasWidth,kRegister0Height));
    registers.push_back(new Register1(kSpacing,kRegister0Height+kSpacing*2,kCanvasWidth,kRegister1Height));
    registers.push_back(new Register2(kSpacing,kRegister1Height+kRegister0Height+kSpacing*3,kCanvasWidth,kRegister2Height));
    registers.push_back(new Register4(kSpacing,kRegister2Height+kRegister1Height+kRegister0Height+kSpacing*4,kCanvasWidth,kRegister4Height));
    registers.push_back(new Register5(2,kRegister4Height+kRegister2Height+kRegister1Height+kRegister0Height+kSpacing*5,kCanvasWidth,kRegister5Height));
    registers.push_back(new Register7(2,kRegister5Height+kRegister4Height+kRegister2Height+kRegister1Height+kRegister0Height+kSpacing*6,kCanvasWidth,kRegister7Height));
    
    for (int i=0; i<registers.size(); i++) {
        registers[i]->setup();
    }
    
    serialSetup = new SerialSetup(registers, kCanvasWidth*2+kSpacing*3, 2, kCanvasWidth, kRegister0Height);
    serialSetup->setup();
    
    registerPreset = new RegisterPreset(registers, kCanvasWidth+kSpacing*2, 2, kCanvasWidth, kRegister0Height);
    registerPreset->setup();
    
    image = new FaceImagePanel(kCanvasWidth+kSpacing*2,kRegister0Height+kSpacing*2+168, 522, 200);
    image->setup();
};

//--------------------------------------------------------------
void BodyCommander::update(){
    serialSetup->receiveCycle();
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