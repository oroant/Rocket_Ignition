/*
Titel:      Rocket Ignition main program
Requires:   PCB version: OAZA Pyrozuender 2.3FL(BEC)
Function:   RC transmitter setup with one (optional two) channels for: 
            - ch2: Security switch for ON, OFF, lockable, reduces risk of accidentially firing a rocket on ground
            - ch1: Trigger switch for ON, OFF, to launch smoke rockets 1 to 5
            Pre-flight checks at startup of the board are performed: 
            - mirco dip switch on board: in case switched OFF, Security switch on ch1 of tx is ignored
Version:    2018-03-05
*/

// Dependencies
#include <Arduino.h>
#include <Flasher.h>
#include <Relais.h>
#include <Messages.h>

// Relais
Relais pwrRelais(pwrPin);
Relais rocket_1(rocketPin_1);
Relais rocket_2(rocketPin_2);

// some LEDs
Flasher onBoard(13);            // onBoard LED
Flasher errorLED(redPin);   // red LED pin for Error
Flasher externalLED(bluePin); // blue LED for external switch

// some test variables
int pwm_signal = 880;

// Setup
void setup() {
    Serial.begin(9600);
    
    //Starting
    printMsg(startMessage);
    onBoard.on(); 
    errorLED.on();
    externalLED.on();

    //Init of rocket channels
    printMsg(initMessage);
    pwrRelais.off();
    rocket_1.on(); 
    rocket_2.on(); 
    
    delay(100);
    rocket_1.off();
    rocket_2.off();
    delay(100);

    //TODO: blinking of Software Version

    // Everything ready
    printMsg(readyMessage);
}

// Loop
void loop() {
    
    onBoard.blinking(500, 250, 5);
    
}
