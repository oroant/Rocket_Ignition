/**
 * Messages utlitiy file
 * contains some messages and function to display
 */

#include <Arduino.h>

//some messages
const char startMessage[31] = "Starting... \n";
const char readyMessage[31] = "Rocket Ignition System ready... \n";
const char initMessage[31] = "initialising... \n";
//const char resetMessage[] = "Reset...        ";

void printMsg(char* msg){ 
    Serial.print(msg);
}

