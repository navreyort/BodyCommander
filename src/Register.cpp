//
//  Register.cpp
//  BodyCommander
//
//  Created by Akito van Troyer on 12/6/13.
//
//

#include "Register.h"

SEND_DATA_STRUCTURE *Register::receiver_settings = new SEND_DATA_STRUCTURE();
SEND_DATA_STRUCTURE *Register::sentData = new SEND_DATA_STRUCTURE();
bool Register::didSend = false;