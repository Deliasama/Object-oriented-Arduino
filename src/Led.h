#pragma once

#include "DigitalOutput.h"

class Led : public DigitalOutput {
    private:

    public:
        Led(int pin);
        ~Led() {    };
        void on();
        void off();
        void blink(int ms);
};