#include "Arduino.h"
#include "Tick/TickManager.h"

#include "Led.h"

class tickableTest : public ITickable {
    public:
        void tick(long deltaTime) override {
            Serial.println("TICK!");
        }
};

void setup() {
    Serial.begin(9600);
    
    Led* led = new Led(13);
    led->blink(5*1000);
}

void loop() {
    TickManager::tickAll();
}

