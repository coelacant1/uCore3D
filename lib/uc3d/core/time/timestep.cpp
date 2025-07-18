#include "timestep.hpp"

TimeStep::TimeStep(float frequency) {
    SetFrequency(frequency);
}

void TimeStep::SetFrequency(float frequency) {
    this->updateInterval = uint16_t((1.0f / frequency) * 1000.0f);
}

bool TimeStep::IsReady() {
    uint32_t currentMillis = uc3d::Time::Millis();
    if (currentMillis - previousMillis >= updateInterval) {
        previousMillis = currentMillis;
        return true;
    } else {
        return false;
    }
}
