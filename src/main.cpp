#include "Arduino.h"
#include "Tick/TickManager.h"
#include "string.h"

#include "Led.h"
#include "DigitalInput.h"

Led* led = new Led(13);

class tpsOutput : public ITickable {
    public:
        void tick(long deltaTime) override {
            // int tps = (long(1*1000*1000) / deltaTime);
            Serial.print("\r" + String(deltaTime));
        }
};

class tickableTest : public ITickable {
    public:
        void tick(long deltaTime) override {
            if(digitalRead(10)) {
                led->blink(1000);
            }
        }
};

void buttonEvent(bool x) {
    if(x) {
        led->blink(2000);
    }
}

void setup() {
    Serial.begin(9600);

    pinMode(10, INPUT);
    
    
    // led->blink(3*1000);

    DigitalInput* input = new DigitalInput(10, (*buttonEvent));

    /*tickableTest* tt = new tickableTest();
    TickManager::addTickable(tt);
    TickManager::setTickrate(tt, 200);*/

    tpsOutput* tpsOut = new tpsOutput();
    TickManager::addTickable(tpsOut);
    TickManager::setTickrate(tpsOut, 500);
}

void loop() {
    TickManager::tickAll();
}

