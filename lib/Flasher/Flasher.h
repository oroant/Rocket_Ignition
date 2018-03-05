/**
 * LED Header File
 * Class and pin definitions for the various leds used in circuit
 * some utility functions to facilitate LED on/off and blinking. 
 */
#include <Arduino.h>

//Pins - Hardware mapping
const int redPin = 7;   // red LED for errors
const int greenPin = 6; // green LED for Ignition ready
const int bluePin = 4;  // blue LED for external switch/bridge

// Class Definition 
class Flasher
{
  // Class Member Variables
  // These are initialized at startup
  int ledPin;   // the number of the LED pin
  long OnTime;  // milliseconds of on-time
  long OffTime; // milliseconds of off-time
  int repeat;   // how many time to repeat
  int count;

  // These maintain the current state
  int ledState;                 // ledState used to set the LED
  unsigned long previousMillis; // will store last time LED was updated
  int blinkState = 0;           // makes sure, led is not doing a blink

  // Constructor - creates a Flasher
public:
  Flasher(int pin, long on, long off, int reps)
  { /*  this constructor, allows initial setup for LED
        Input: led pin, on=ontime, off=offtime, reps=repetitions
        Output: 
        */
    ledPin = pin;
    pinMode(ledPin, OUTPUT);

    OnTime = on;
    OffTime = off;
    repeat = reps;

    ledState = LOW;
    blinkState = 0;
    previousMillis = 0;
    count = 0;
  }

  // Constructor - creates a Flasher, only with its pin
  Flasher(int pin)
  { /*  this constructor initialises a LED only with its pin 
        Input: led pin
        Output: 
        */
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    ledState = LOW;
    blinkState = 0;
    previousMillis = 0;
    count = 0;
  }

  // Utility for blinking
  void blinking(long on, long off, int reps)
  { /*  this function lets an LED blink for a specified number of repetitions. 
        Input: on=ontime, off=offtime, reps=repetitions
        Output: functions works only in loop, not setup 
        */
    repeat = reps;
    OnTime = on;
    OffTime = off;

    // check to see if it's time to change the state of the LED
    unsigned long currentMillis = millis();

    if (count < repeat) // repeat only specified number of times
    {
      blinkState = 1;
      if ((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
      {
        ledState = LOW;                 // Turn it off
        previousMillis = currentMillis; // Remember the time
        digitalWrite(ledPin, ledState); // Update the actual LED
        count = count + 1;
      }
      else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
      {
        ledState = HIGH;                // turn it on
        previousMillis = currentMillis; // Remember the time
        digitalWrite(ledPin, ledState); // Update the actual LED
      }
    }
    else
    {
      blinkState = 0;
    }
  }

  //Utility for LED on
  void on()
  {
    if (blinkState == 0)
    {
      digitalWrite(ledPin, HIGH);
    }
  }

  //Utility for LED off
  void off()
  {
    if (blinkState == 0)
    {
      digitalWrite(ledPin, LOW);
    }
  }
};
