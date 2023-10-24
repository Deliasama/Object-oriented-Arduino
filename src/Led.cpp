#include "Led.h"

Led::Led(int pin) : DigitalOutput(pin) {
    
}
void Led::on() {
    setState(true);
    update();
}

void Led::off() {
    setState(false);
    update();
}

void Led::blink(int ms) {
    setState(true);
    update();
    setState(false);
    updateInOverride(ms);
}