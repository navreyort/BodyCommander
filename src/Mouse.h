//
//  Mouse.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/9/13.
//
//

#ifndef BodyCommander_Mouse_h
#define BodyCommander_Mouse_h

class Mouse {

public:
    
    Mouse(){};
    ~Mouse(){};
    
    void pressed();
    void released();
    bool getPressState();
    static Mouse *sharedMouse();
    
private:
    bool mousePressed;
};

inline void Mouse::pressed() {
    mousePressed = true;
}

inline void Mouse::released() {
    mousePressed = false;
}

inline bool Mouse::getPressState() {
    return mousePressed;
}

inline Mouse *Mouse::sharedMouse() {
	static Mouse *mouse = NULL;
	if (mouse == NULL) {
		mouse = new Mouse();
	}
	return mouse;
}

#endif
