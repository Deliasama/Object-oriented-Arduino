#pragma once

class ITickable {
    public:
        virtual ~ITickable() {  }
        virtual void tick(long deltaTime);
        long elapsedTime;
        long timeOut;
    private:
};