#pragma once

#include "Arduino.h"
#include "interfaces/ITickable.h"

class Pin : public ITickable {
    public:
        int pin;
        virtual void tick(long deltaTime) override;
    private:
};