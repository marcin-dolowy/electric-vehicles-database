#include "Bike.h"

int Bike::get_gears() const {
    return this->gears;
}

int Bike::get_weight() const {
    return this->weight;
}

double Bike::get_frame_size() const {
    return this->frame_size;
}

void Bike::set_gears(int gears_) {
    if(gears_ < 0 || gears_ > 20) {
        throw std::runtime_error("GEARS VALUE IS INCORRECT\n");
    }
    this->gears = gears_;
}

void Bike::set_weight(int weight_) {
    if(weight_ < 0 || weight_ > 50) {
        throw std::runtime_error("WEIGHT VALUE IS INCORRECT\n");
    }
    this->weight = weight_;
}

void Bike::set_frame_size(double frame_size_) {
    if(frame_size_ < 0 || frame_size_ > 30) {
        throw std::runtime_error("FRAME SIZE VALUE IS INCORRECT\n");
    }
    this->frame_size = frame_size_;
}

Bike::Bike(const std::string &brand, const int price, const int range, const int gears, const int weight,
           const double frame_size) : Vehicle(brand, price, range) {
    set_gears(gears);
    set_weight(weight);
    set_frame_size(frame_size);
}

void Bike::info() const {
    Vehicle::info();
    std::cout << "GEARS: " << gears << " | WEIGHT: " << weight << " | FRAME SIZE: " << frame_size << '\n';
}

std::ostream& operator<<(std::ostream& out, const Bike& bike) {
    return out << "BRAND: " << bike.get_brand() << " | PRICE: " << bike.get_price() << " | RANGE: " << bike.get_range()
    << " | GEARS: " << bike.get_gears() << " | WEIGHT: " << bike.get_weight() << " | FRAME SIZE: "<< bike.get_frame_size()
    << '\n';
}


/*std::istream &operator>>(std::istream &in, Bike &bike) {
    std::cout << "TYPE BRAND: ";
    std::getline(in, bike.brand);
    std::cout << "TYPE PRICE: ";
    in >> bike.price; in.get();
    std::cout << "TYPE RANGE: ";
    in >> bike.range; in.get();
    std::cout << "TYPE GEARS: ";
    in >> bike.gears; in.get();
    std::cout << "TYPE WEIGHT: ";
    in >> bike.weight; in.get();
    std::cout << "TYPE FRAME SIZE: ";
    in >> bike.frame_size; in.get();
    return in;
}*/
