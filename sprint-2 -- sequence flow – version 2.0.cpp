#include <iostream>

class EnvironmentSensor {
private:
    int currentTemperature;
public:
    int getCurrentTemperature() const {
        return currentTemperature;
    }

    void setCurrentTemperature(int temperature) {
        currentTemperature = temperature;
    }
};

class WaterHeater {
private:
    int heatingTemperature;
public:
    int getHeatingTemperature() const {
        return heatingTemperature;
    }

    void setHeatingTemperature(int temperature) {
        heatingTemperature = temperature;
    }
};

class SmartGeyser {
protected:
    EnvironmentSensor temperatureSensor;
    WaterHeater waterHeater;
public:
    virtual void activateGeyser() = 0; // Virtual function to be overridden in derived classes
};

class HeatingSystem {
public:
    int calculateRequiredTemperature(int currentTemperature) {
        return currentTemperature + 10; // Example calculation for required temperature
    }
};

class BathroomGeyser : public SmartGeyser {
private:
    HeatingSystem heatingSystem;
public:
    void activateGeyser() override {
        int currentTemperature = temperatureSensor.getCurrentTemperature();
        int requiredTemperature = heatingSystem.calculateRequiredTemperature(currentTemperature);
        waterHeater.setHeatingTemperature(requiredTemperature);
        std::cout << "Heating temperature set to: " << requiredTemperature << " degrees" << std::endl;
    }

    void adjustHeatingTemperature() {
        int currentTemperature = temperatureSensor.getCurrentTemperature();
        int requiredTemperature = currentTemperature + 15; // Adjusted calculation for winter day
        waterHeater.setHeatingTemperature(requiredTemperature);
        std::cout << "Adjusted heating temperature set to: " << requiredTemperature << " degrees" << std::endl;
    }
};

class HomeOwner {
public:
    void getsOutOfBed(SmartGeyser& geyser) {
        geyser.activateGeyser();
    }
};

int main() {
    HomeOwner owner;
    BathroomGeyser geyser;
    owner.getsOutOfBed(geyser);

    return 0;
}
