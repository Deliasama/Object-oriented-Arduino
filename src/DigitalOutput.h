#pragma once

#include "Arduino.h"
#include "Pin.h"

class DigitalOutput : public Pin {
    public:
        DigitalOutput(int pin);
        ~DigitalOutput();
        bool getState();
        void setState(bool state);
        bool isHigh();
        void update();
        void updateInOverride(long ms);

        void tick(long deltaTime) override;

    private:
        // State the output should be (after a update)
        bool state;
        // State the output actually is
        bool currentState = false;
};