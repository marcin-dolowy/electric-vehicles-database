#include <iostream>
#include <utility>
#include <ostream>
#include <istream>
#include <string>

class Vehicle {
private:
    std::string brand;
    int price;
    int range;
public:
    Vehicle(std::string  brand, int price, int range) : brand(std::move(brand)), price(price), range(range) {}
    Vehicle() : brand(" "), price(0), range(0) {};
    ~Vehicle() = default;
    void info() const;
    friend std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle);
    friend std::istream& operator>>(std::istream& in, Vehicle& vehicle);
};