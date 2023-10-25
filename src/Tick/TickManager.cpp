#include "TickManager.h"
#include "Arduino.h"

ITickable* TickManager::tickables[64] = { nullptr };

long deltaTime;
long startAt;

bool TickManager::addTickable(ITickable* tickable) {
    for (int i = 0; i < 64; i++) {
        if (tickables[i] == nullptr) {
            tickables[i] = tickable;
            return true;
        }
    }
    return false;
}

bool TickManager::removeTickable(ITickable* tickAble) {
    for (int i = 0; i < 64; i++) {
        if(tickables[i] == tickAble) {
            tickables[i] = nullptr;
            return true;
        }
    }
    return false;
}

void TickManager::tickAll() {
    deltaTime = (micros() - startAt);
    startAt = micros();
    
    for(ITickable* t : tickables) {
        if(t) {
            t->tick(deltaTime);
            return;
        }
    }
}