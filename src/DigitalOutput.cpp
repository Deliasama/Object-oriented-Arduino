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
    delay = (ms*1000);
    tickable = true;
}

void DigitalOutput::tick(long deltaTime) {
    if(!tickable)return;

    delay -= deltaTime;
    if(delay<=0) {
        update();
        tickable = false;
    }
}

void DigitalOutput::setTickable(bool tickable) {
    DigitalOutput::tickable = tickable;
}