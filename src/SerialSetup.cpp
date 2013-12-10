//
//  SerialSetup.cpp
//  BodyCommander
//
//  Created by Akito van Troyer on 12/8/13.
//
//

#include "SerialSetup.h"

TELEMETRY_DATA_STRUCTURE *SerialSetup::receiver_telemetry = new TELEMETRY_DATA_STRUCTURE();
int SerialSetup::lastReceived = 0;