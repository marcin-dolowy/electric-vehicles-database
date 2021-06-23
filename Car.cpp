#include "Car.h"

void Car::info() const {
    Vehicle::info();
    std::cout << "MODEL: " << model << " | COLOR: " << color << " | VIM: " << vim <<
    " | DAMAGE: " << std::boolalpha << damage << '\n';
}
