#include "AnalogOutput.h"

AnalogOutput::AnalogOutput(int pin) {
    AnalogOutput::pin = pin;
    pinMode(pin, OUTPUT);
}

AnalogOutput::~AnalogOutput() {
    pinMode(pin, NULL);
}

void AnalogOutput::write(int frequenz) {
    analogWrite(pin, frequenz);
}

void AnalogOutput::tick(long deltaTime) {

}