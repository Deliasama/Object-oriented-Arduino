#pragma once

#include "Arduino.h"
#include "interfaces/ITickable.h"
#include "Tick/TickManager.h"

class DigitalInput : public ITickable {
    private:
        int pin;
        bool state;
        void (*event)(bool x);

    public:
        DigitalInput(int pin);
        DigitalInput(int pin, void (*event)(bool x));
        ~DigitalInput();
        bool getState();
        void tick(long deltaTime) override;
};