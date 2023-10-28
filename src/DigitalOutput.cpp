#include "DigitalOutput.h"
#include "Tick/TickManager.h"

DigitalOutput::DigitalOutput(int pin) {
    pinMode(pin, OUTPUT);
    TickManager::addTickable(this);
    DigitalOutput::pin = pin;

    Serial.println("new Digitaloutput!");
}

DigitalOutput::~DigitalOutput() {
    pinMode(pin, NULL);
    TickManager::removeTickable(this);
}

void DigitalOutput::setState(bool state) {
    DigitalOutput::state = state;
}

bool::DigitalOutput::getState() {
    return state;
}

bool DigitalOutput::isHigh() {
    return currentState;
}

void DigitalOutput::update() {
    if(state) {
        digitalWrite(pin, HIGH);
        currentState = true;
    }else {
        digitalWrite(pin, LOW);
        currentState = false;
    }
}

void DigitalOutput::updateInOverride(long ms) {
    TickManager::removeTickable(this);
    if(TickManager::addTickable(this)) {
        TickManager::setTickrate(this, ms);
    }
}

void DigitalOutput::tick(long deltaTime) {
    update();
    TickManager::removeTickable(this);
}