#include "SerialManager.h"

SerialManager::SerialManager(int rate) {
    Serial.begin(rate);
}