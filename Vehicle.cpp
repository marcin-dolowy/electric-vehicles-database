#include "Vehicle.h"

std::string Vehicle::get_brand() const {
    return this->brand;
}

int Vehicle::get_price() const {
    return this->price;
}

int Vehicle::get_range() const {
    return this->range;
}

void Vehicle::set_brand(const std::string &brand_) {
    if(brand_.length() < 0 || brand_.length() > 20) {
        throw std::runtime_error("WRONG NAME OF BRAND\n");
    }
    this->brand = brand_;
}

void Vehicle::set_price(int price_) {
    if(price_ < 0) {
        throw std::runtime_error("PRICE VALUE IS INCORRECT\n");
    }
    this->price = price_;
}

void Vehicle::set_range(int range_) {
    if(range_ < 0) {
        throw std::runtime_error("RANGE VALUE IS INCORRECT");
    }
    this->range = range_;
}

Vehicle::Vehicle(const std::string& brand, const int price, const int range) {
    set_brand(brand);
    set_price(price);
    set_range(range);
}

void Vehicle::info() const {
    std::cout << "BRAND: " << get_brand() << " | PRICE: " << get_price() << " | RANGE: " << get_range();
}

void Vehicle::show_data_base(const std::vector<Vehicle>& vec) {
    for(const auto & i : vec) {
        std::cout << i;
    }
}

std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle) {
    return out << "BRAND: " << vehicle.get_brand() << " | PRICE: " << vehicle.get_price() << " | RANGE: "
    << vehicle.get_range() << '\n';
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


