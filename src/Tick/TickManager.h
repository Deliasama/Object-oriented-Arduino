#pragma once

#include "../interfaces/ITickable.h"

class TickManager {
    public:
        static ITickable* tickables[64];
    
        static bool addTickable(ITickable* tickable);
        static bool removeTickable(ITickable* tickable);
        static void tickAll();
};