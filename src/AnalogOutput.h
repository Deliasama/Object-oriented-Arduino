#include "Arduino.h"
#include "interfaces/ITickable.h"

class AnalogOutput : public ITickable {
    public:
        AnalogOutput(int pin);
        ~AnalogOutput();
        void tick(long deltaTime) override;
        void write(int frequenz);
    private:
        int pin;
};