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


// Relais
Relais pwrRelais(pwrPin);
Relais rocket_1(rocketPin_1);
Relais rocket_2(rocketPin_2);
Relais rocket_3(rocketPin_3);
Relais rocket_4(rocketPin_4);
Relais rocket_5(rocketPin_5);


// some variables
int pwm_signal = 880;
int counter = 0;

Flasher led(13, 550, 250);

// Setup
void setup() {
    Serial.begin(9600);
}

// Loop
void loop() {


}
