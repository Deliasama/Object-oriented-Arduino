#pragma once
#include <Arduino.h>
#include "Packet.h"
#include "interfaces/ITickable.h"

class SerialManager : ITickable {
    public:
        SerialManager(int rate);
        void tick(long deltaTime) override;
        bool sendPackets(Packet* packet);
    private:
};