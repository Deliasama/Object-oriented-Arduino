#include "SerialManager.h"
#include "Tick/TickManager.h"

SerialManager::SerialManager(int rate) {
    Serial.begin(rate);

    // handle ticks
    TickManager::addTickable(this);
    timeOut = 10l * 1000l; // 10ms timeOut
}   

SerialManager::~SerialManager() {
    delete[] buffer;

    // handle ticks
    TickManager::removeTickable(this);
}

void SerialManager::tick(long deltaTime) {
    checkIncomingPackets();
}

void SerialManager::registerEventListener(void (*reveivePacketListener)(Packet* packet)) {
    SerialManager::receivePacketEvent = (*reveivePacketListener);
}

void SerialManager::checkIncomingPackets() {
    while(Serial.available() > 0) {
        uint8_t data = Serial.read();

        if(data != 0xFF) {
            // if the Arduino receives a FE the packet should be created
            if(data == 0xFE) {
                // create packet
                Packet* packet = new Packet(buffer[0], bytesRead);
                packet->setValue(buffer+1, bytesRead-1);


                // trigger Event and free memory
                receivePacketEvent(packet);

                delete[] packet;
                bytesRead = 0;
            }else {
                buffer[bytesRead] = data;
                bytesRead++;
            }
        }
    }
}

bool SerialManager::sendPackets(Packet* packets) {
    // write data
    uint8_t* data = packets->getData();
    for(int i = 0; i<packets->getSize(); i++) {
        Serial.write(data[i]);
    }

    Serial.write(0xFE);
    Serial.write(0xFF);
    Serial.flush();

    // clean up
    delete[] packets;
    return true;
}