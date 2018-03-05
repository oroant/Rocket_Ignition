/**
 * Relais Header File
 * Class and pin definitions for the various relais
 */

#include <Arduino.h>

//Pins - Hardware mapping
const int rocketPin_1 = 11;
const int rocketPin_2 = 13;
const int rocketPin_3 = 12;
const int rocketPin_4 = 8;
const int rocketPin_5 = 9;
const int pwrPin = 10;

class Relais {

    // Class Member Variables
    int relaisPin; // pin number for relais
    int relaisStatus; //status of relais 0=off, 1=ready/armed, 2=fired
    unsigned long previousMillis;  	// will store last time relais was updated
    unsigned long fireTime;  //time, wenn relais was switch the armed (status 1)


    // Constructor - creates a Relais
    // and initializes the member variables and state
public:
    Relais(int pin)
    {   /*  intialize relais, set it to LOW
            Input: pin
            Output: none
        */ 
        relaisPin = pin;
        pinMode(relaisPin, OUTPUT);
        digitalWrite(relaisPin, LOW); //set the relais to off
        relaisStatus = 0; //set the status to off=0
        previousMillis = 0;
    }
    
    void update()
    { /*    update relais
            Set the time fire ready status was set. Used
        */

        // TODO: implent functionality
        // check to see if it's time to change the state of the LED
       
    }

    void fire()
    {
        // make sure, relais is on for 5s (5000ms)
        
        //TODO: wait 5s, then switch back to LOW

        //TODO: message(rocket launched)
        //TODO: message(awating trigger for next rocket)
        relaisStatus = 2; //rocket fired
    }
};
