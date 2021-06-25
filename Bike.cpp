#include "Bike.h"

void Bike::info() const {
    Vehicle::info();
    std::cout << "GEARS: " << gears << " | WEIGHT: " << weight << " | FRAME SIZE: " << frame_size << '\n';
}

std::ostream& operator<<(std::ostream& out, const Bike& bike) {
    return out << "BRAND: " << bike.brand << " | PRICE: " << bike.price << " | RANGE: " << bike.range << " | GEARS: " << bike.gears
    << " | WEIGHT: " << bike.weight << " | FRAME SIZE: " << bike.frame_size << '\n';
}
