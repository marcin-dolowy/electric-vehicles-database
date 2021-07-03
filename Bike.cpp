#include "Bike.h"

int Bike::get_gears() const {
    return this->gears;
}

double Bike::get_weight() const {
    return this->weight;
}

double Bike::get_frame_size() const {
    return this->frame_size;
}

void Bike::set_gears(int gears_) {
    if(gears_ < 0 || gears_ > 30) {
        throw std::runtime_error("GEARS VALUE IS INCORRECT\n");
    }
    this->gears = gears_;
}

void Bike::set_weight(double weight_) {
    if(weight_ < 0 || weight_ > 50) {
        throw std::runtime_error("WEIGHT VALUE IS INCORRECT\n");
    }
    this->weight = weight_;
}

void Bike::set_frame_size(double frame_size_) {
    if(frame_size_ < 0 || frame_size_ > 50) {
        throw std::runtime_error("FRAME SIZE VALUE IS INCORRECT\n");
    }
    this->frame_size = frame_size_;
}

Bike::Bike(const std::string &brand, int price, int range, int gears, double weight,
           double frame_size) : Vehicle(brand, price, range) {
    set_gears(gears);
    set_weight(weight);
    set_frame_size(frame_size);
}


void Bike::info() const {
    Vehicle::info();
    std::cout << " | GEARS: " << get_gears() << " | WEIGHT: " << get_weight() << " | FRAME SIZE: " << get_frame_size() << '\n';
}

std::ostream& operator<<(std::ostream& out, const Bike& bike) {
    return out << "BRAND: " << bike.get_brand() << " | PRICE: " << bike.get_price() << " | RANGE: " << bike.get_range()
    << " | GEARS: " << bike.get_gears() << " | WEIGHT: " << bike.get_weight() << " | FRAME SIZE: "<< bike.get_frame_size()
    << '\n';
}

void Bike::show_bikes_data_base(const std::vector<Bike>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        std::cout << i + 1 << ". " << vec[i];
    }
}

void Bike::sort_by_price(std::vector<Bike> &vec) {
    std::sort(vec.begin(), vec.end(), [](const Bike& lhs, const Bike& rhs){
        return lhs.get_price() < rhs.get_price();
    });
}

void Bike::sort_by_range(std::vector<Bike> &vec) {
    std::sort(vec.begin(), vec.end(), [](const Bike& lhs, const Bike& rhs){
        return lhs.get_range() < rhs.get_range();
    });
}

void Bike::add_bike(std::vector<Bike> &vec) {
    std::string brand_;
    int price_, range_, gears_;
    double weight_, frame_size_;
    std::cout << "TYPE BRAND: ";
    std::getline(std::cin, brand_);
    std::cout << "TYPE PRICE: ";
    std::cin >> price_; std::cin.get();
    std::cout << "TYPE RANGE: ";
    std::cin >> range_; std::cin.get();
    std::cout << "TYPE GEARS: ";
    std::cin >> gears_; std::cin.get();
    std::cout << "TYPE WEIGHT: ";
    std::cin >> weight_; std::cin.get();
    std::cout << "TYPE FRAME SIZE: ";
    std::cin >> frame_size_; std::cin.get();
    vec.emplace_back(Bike{brand_, price_, range_, gears_, weight_, frame_size_});
}

void Bike::delete_bike(std::vector<Bike>& vec) {
    int choice;
    std::cout << "SELECT A NUMBER OF BIKE YOU WANT TO DELETE: ";
    std::cin >> choice;
    vec.erase(vec.begin() + choice - 1);
    }

std::vector<Bike> Bike::read_bikes_file(const std::string &filename) {
    std::ifstream file;
    file.open(filename);
    if(!file.is_open()) {
        throw std::runtime_error("FILE NOT FOUND!\n");
    }
    std::string brand_, separator;
    int price_, range_, gears_;
    double weight_, frame_size_;
    std::vector<Bike> result;
    while(!file.eof()) {
        std::getline(file, brand_);
        file >> price_; file.get();
        file >> range_; file.get();
        file >> gears_; file.get();
        file >> weight_; file.get();
        file >> frame_size_; file.get();
        std::getline(file, separator);
        result.emplace_back(Bike{brand_, price_, range_, gears_, weight_, frame_size_});
    }
    return result;
}

void Bike::save_bikes(const std::vector<Bike> &vec, const std::string &filename) {
    std::ofstream file;
    file.open(filename, std::ios::app);
    if(!file.is_open()) {
        throw std::runtime_error("ERROR!\n");
    }
    for(const auto & i : vec) {
        file << i.get_brand() << '\n' << i.get_price() << '\n' << i.get_range() << '\n' << i.get_gears() << '\n'
        << i.get_weight() << '\n' << i.get_frame_size() << '\n' << "=====================\n";
    }
    std::cout << "Saved successfully :)!" << '\n' << "You saved your data base in: " << filename << '\n';
}