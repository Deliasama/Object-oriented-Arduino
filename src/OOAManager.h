#pragma once

#include "Pin.h"

extern Pin* pins[64];

void enterLoop();
void exitLoop();
void wait(int ms);