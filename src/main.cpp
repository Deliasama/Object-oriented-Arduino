#include "Arduino.h"
#include "DigitalOutput.h"
#include "OOAManager.h"
#include "Led.h"

// Pin* pins[64] = { nullptr };

DigitalOutput* output;
Led led(13);

void setup() {
    Serial.begin(9600);

    /*for(Pin* pin : pins) {
        if(pin == nullptr)Serial.println("no");
        if(pin != nullptr)Serial.println("yes");
    }*/

    /*output->setState(true);
    output->update();
    output->setState(false);
    output->updateInOverride(10*1000);*/

    led.off();
}

void loop() {
    // Serial.println("Loop: ");
    enterLoop();
    
    if(!led.isHigh()) {
        wait(1*1000);
        led.blink(2*1000);
    }

    
    /*output->setState(true);
    output->update();
    delay(2*1000);
    output->setState(false);
    output->update();
    delay(2* 1000);*/
    
    // led->on();
    exitLoop();
}