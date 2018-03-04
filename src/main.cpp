#include <Arduino.h>
#include <Flasher.h>

// Pins
const int pwrPin = 5;
const int ledPin = 3;

// some variables
int pwm_signal = 880;
int counter = 0;

Flasher led(13, 550, 250);

void setup() {
    Serial.begin(9600);
}

void loop() {

    while (counter <=1) {
        int txCh = pwm_signal;
        int ch_mapped = map(txCh, 900, 2100, -600, 600);
        int ch_constr = constrain(ch_mapped, txCh, 900);

        Serial.print("pulse width: ");
        Serial.println(txCh);

        Serial.print("Mapped: ");
        Serial.println(ch_mapped);

        Serial.print("constrained: ");
        Serial.println(ch_constr);
        Serial.println("--------------------");
        delay(20);
        counter += 1;
    }

    led.Update();
    Serial.println("Hallo");

}
