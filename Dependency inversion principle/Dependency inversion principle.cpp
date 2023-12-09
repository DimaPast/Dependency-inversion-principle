#include <iostream>


class LightBulb {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};


class IncandescentBulb : public LightBulb {
public:
    void turnOn() override {
        std::cout << "Incandescent Bulb turned on\n";
    }

    void turnOff() override {
        std::cout << "Incandescent Bulb turned off\n";
    }
};


class LEDBulb : public LightBulb {
public:
    void turnOn() override {
        std::cout << "LED Bulb turned on\n";
    }

    void turnOff() override {
        std::cout << "LED Bulb turned off\n";
    }
};

class LightSwitch {
private:
    LightBulb* bulb;

public:
    
    LightSwitch(LightBulb* lightBulb) : bulb(lightBulb) {}

    
    void turnOn() {
        bulb->turnOn();
    }

    void turnOff() {
        bulb->turnOff();
    }
};

int main() {
    
    IncandescentBulb incandescentBulb;
    LEDBulb ledBulb;

    
    LightSwitch incandescentSwitch(&incandescentBulb);
    LightSwitch ledSwitch(&ledBulb);

   
    incandescentSwitch.turnOn();
    incandescentSwitch.turnOff();

    ledSwitch.turnOn();
    ledSwitch.turnOff();

    return 0;
}