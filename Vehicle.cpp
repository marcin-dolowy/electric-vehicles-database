#include "Vehicle.h"

void Vehicle::info() const {
    std::cout << "BRAND: " << brand << ", PRICE: " << price << ", RANGE: " << range << '\n';
}

std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle) {
    return out << "BRAND: " << vehicle.brand << ", PRICE: " << vehicle.price << ", RANGE: " << vehicle.range << '\n';
}

std::istream& operator>>(std::istream& in, Vehicle& vehicle) {
    std::cout << "TYPE BRAND: ";
    std::getline(in, vehicle.brand);
    std::cout << "TYPE PRICE: ";
    in >> vehicle.price; in.get();
    std::cout << "TYPE RANGE: ";
    in >> vehicle.range; in.get();
    return in;
}

