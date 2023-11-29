#pragma once
#include <Arduino.h>

class Packet {
    // Packet: [ID] [Value] [Value] [Value] [Value]...
    public:
        Packet(uint8_t id, int size);
        ~Packet();
        bool send();
        void setValue(uint8_t* value, int size);
        uint8_t* getData();
        int getSize();

    private:
        uint8_t* data;
        int dataSize;
};