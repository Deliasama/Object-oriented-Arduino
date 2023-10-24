#include "DigitalOutput.h"
#include "OOAManager.h"

DigitalOutput::DigitalOutput(int pin) {
    pinMode(pin, OUTPUT);
    pins[pin] = this;
    DigitalOutput::pin = pin;

    Serial.println("new Digitaloutput!");
}

DigitalOutput::~DigitalOutput() {
    pinMode(pin, NULL);
    pins[pin] = NULL;
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

    // Serial.println(deltaTime);
    // Serial.println(delay);
}

void DigitalOutput::setTickable(bool tickable) {
    DigitalOutput::tickable = tickable;
}