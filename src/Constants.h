//
//  Constants.h
//  BodyCommander
//
//  Created by Akito van Troyer on 12/5/13.
//
//

#ifndef BodyCommander_Constants_h
#define BodyCommander_Constants_h

#include "MCP2035.h"

//------------------- Microcontroller Related

typedef struct SEND_DATA_STRUCTURE {
    //put your variable definitions here for the data you want to send
    //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
    
    uint8_t oeh;
    uint8_t oel;
    uint8_t alrtind;
    uint8_t lcxen;
    
    uint8_t datout;
    uint8_t tunecap;
    
    uint8_t rssifet;
    uint8_t clkdiv;
    
    uint8_t sensctl;
    
    uint8_t agcsig;
    uint8_t modmin;
    
    uint8_t led;
    
    SEND_DATA_STRUCTURE():oeh(0x00),oel(0x00),alrtind(0x00),lcxen(0x00),datout(0x00),tunecap(0x00),rssifet(0x00),clkdiv(0x00),sensctl(0x00),agcsig(0x00),modmin(0x00), led(0x00){};
} SEND_DATA_STRUCTURE;

#define kMaxRegisterSize 9

//Register 0
#define kNumRegistersUsedin0th 2

#define kOEFHT "OEH"
#define kOEFLT "OEL"
#define kAlertTrigger "ALRTIND"
#define kInputChannel "LCXEN"

//Register 1
#define kDatout "DATOUT"
#define kLcxtun "LCXTUN"

//Register 2
#define kRssiFet "RSSIFET"
#define kClkDiv "CLKDIV"

//Register 4
#define kLcxSen "LCXSEN"

//Register 5
#define kModMin "MODMIN"
#define kAgcSig "AGCSIG"

//Register 7
#define kNumRegistersUsedOn7th 7
#define kChzact "CHZACT"
#define kChyact "CHYACT"
#define kChxact "CHXACT"
#define kAgcAct "AGCACT"
#define kWakez "WAKEZ"
#define kWakey "WAKEY"
#define kWakex "WAKEX"
#define kAlarm "ALARM"
#define kPei "PEI"


//GUI Related
#define kRegister0Name "Register 0"
#define kRegister1Name "Register 1"
#define kRegister2Name "Register 2"
#define kRegister4Name "Register 4"
#define kRegister5Name "Register 5"
#define kRegister7Name "Register 7"
#define kSerialSetupName "Serial Setup"
#define kSerialSendName "Serial Setup"
#define kTerminalName "Terminal"

#define kCanvasWidth 260
#define kCanvasHeight 165
#define kToggleSize 20

#endif
