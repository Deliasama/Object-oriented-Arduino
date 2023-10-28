#include "DigitalInput.h"

DigitalInput::DigitalInput(int pin) {
    DigitalInput::pin = pin;
    pinMode(pin, INPUT);

    TickManager::addTickable(this);
    // TODO: Make timeOut cangeable
    timeOut = 10;
}

DigitalInput::DigitalInput(int pin, void(*event)(bool x)) {
    DigitalInput::pin = pin;
    DigitalInput::event = event;

    TickManager::addTickable(this);
    // TODO: Make timeOut cangeable
    timeOut = 10;
}

DigitalInput::~DigitalInput() {
    TickManager::removeTickable(this);
    pinMode(pin, NULL);
}

bool DigitalInput::getState() {
    return state;
}

void DigitalInput::tick(long deltaTime) {
    state = digitalRead(pin);
    event(state);
}

