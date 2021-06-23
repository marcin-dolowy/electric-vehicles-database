#include "Vehicle.h"

void Vehicle::info() const {
    std::cout << "BRAND: " << brand << " | PRICE: " << price << " | RANGE: " << range << " | ";
}

std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle) {
    return out << "BRAND: " << vehicle.brand << " | PRICE: " << vehicle.price << " | RANGE: " << vehicle.range << '\n';
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

void Vehicle::show_data_base(const std::vector<Vehicle>& vec) {
    for(const auto & i : vec)
    {
        std::cout << i;
    }
}

void Vehicle::sort_by_price(std::vector<Vehicle>& vec) {
    std::sort(vec.begin(), vec.end(), [](const Vehicle& lhs, const Vehicle& rhs){
        return lhs.price < rhs.price;
    });
}

void Vehicle::sort_by_range(std::vector<Vehicle>& vec) {
    std::sort(vec.begin(), vec.end(), [](const Vehicle& lhs, const Vehicle& rhs){
       return lhs.range < rhs.range;
    });
}

std::string Vehicle::get_brand() const {
    return brand;
}

int Vehicle::get_price() const {
    return price;
}

int Vehicle::get_range() const {
    return range;
}

void Vehicle::set_brand(const std::string &brand_) {
    if(brand_.length() < 0) {
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
    if(range < 0) {
        throw std::runtime_error("RANGE VALUE IS INCORRECT");
    }
    this->range = range_;
}