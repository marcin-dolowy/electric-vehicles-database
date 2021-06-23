#include <utility>

#include "Vehicle.h"

class Car : public Vehicle {
private:
    std::string model;
    std::string color;
    std::string vim;
    bool damage;
public:
    Car(const std::string& brand, std::string model, int price, int range, std::string color, std::string vim,
        bool damage) : Vehicle(brand, price, range),
        model(std::move(model)), color(std::move(color)), vim(std::move(vim)), damage(damage) {}
    Car() = default;
    ~Car() = default;
    void info() const override;



};

