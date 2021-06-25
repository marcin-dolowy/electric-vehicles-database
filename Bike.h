#pragma once

#include "Vehicle.h"

class Bike : public Vehicle {
protected:
    int gears;
    int weight;
    double frame_size;
public:
    Bike(const std::string &brand, const int price, const int range, const int gears, const int weight,
         const double frame_size) : Vehicle(brand, price, range), gears(gears), weight(weight),
         frame_size(frame_size) {}
    Bike() = default;
    ~Bike() = default;
    void info() const override;
    friend std::ostream& operator<<(std::ostream& out, const Bike& bike);
};