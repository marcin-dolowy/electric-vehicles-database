#pragma once

#include "Vehicle.h"

class Bike : public Vehicle {
private:
    int gears;
    int weight;
    double frame_size;
public:
    Bike(const std::string &brand, const int price, const int range, const int gears, const int weight,
         const double frame_size);
    Bike() = default;
    ~Bike() = default;

    //getters
    int get_gears() const;
    int get_weight() const;
    double get_frame_size() const;

    //setters
    void set_gears(int gears_);
    void set_weight(int weight_);
    void set_frame_size(double frame_size);

    void info() const override;
    friend std::ostream& operator<<(std::ostream& out, const Bike& bike);
    friend std::istream& operator>>(std::istream& in, Bike& bike);
};