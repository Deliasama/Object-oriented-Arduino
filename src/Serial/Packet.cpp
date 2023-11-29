#include "Packet.h"

Packet::Packet(uint8_t id, int size) {
    if(size <= 0)return;
    data = new uint8_t[size];
    data[0] = id;
}

Packet::~Packet() {
    // Free Memory
    delete[] data;
}

bool Packet::send() {
    // TODO
}

void Packet::setValue(uint8_t* value, int size) {
    if(size == 0 || size >= dataSize)return;
    for(int i = 1; i<=size; i++) {
        data[i] = value[i-1];
    }
}

uint8_t* Packet::getData() {
    return data;
}

int Packet::getSize() {
    return dataSize;
}