#include "OOAManager.h"
#include "Arduino.h"

Pin* pins[64] = { nullptr };

long deltaTime;

long startAt;

void enterLoop() {
    deltaTime = (micros() - startAt);
    startAt = micros();
    
    Serial.println(deltaTime);
};

void exitLoop() {
    for(Pin* pin : pins) {
        if(pin != nullptr) {
            // Serial.println((millis()-startAt));
            pin->tick(deltaTime);
        }
    }
};

void wait(int ms) {
    delay(ms);
    deltaTime-=(ms*1000);
}
