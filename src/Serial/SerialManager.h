#pragma once
#include <Arduino.h>
#include "Packet.h"
#include "interfaces/ITickable.h"

class SerialManager : ITickable {
    public:
        SerialManager(int rate);
        ~SerialManager();
        void registerEventListener(void (*receivePacketEvent)(Packet* packet));
        void tick(long deltaTime) override;
        bool sendPackets(Packet* packet, int size);
        bool sendPackets(Packet* packet);
        void checkIncomingPackets();
    private:
        void (*receivePacketEvent)(Packet* packet);
        uint8_t* buffer = new uint8_t[32];
        int bytesRead;
};