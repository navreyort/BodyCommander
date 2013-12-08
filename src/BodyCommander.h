#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "SerialSetup.h"
#include "Terminal.h"
#include "Register0.h"
#include "Register1.h"
#include "Register2.h"
#include "Register4.h"
#include "Register5.h"
#include "Register7.h"
#include "PresetPanel.h"
#include "FaceImagePanel.h"

class BodyCommander : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    SerialSetup *serialSetup;
    Terminal *terminal;
    vector<Register*> registers;
    RegisterPreset* registerPreset;
    FaceImagePanel * image;
    void exit();

};
