#include "Car.h"

std::string Car::get_model() const {
    return this->model;
}

std::string Car::get_color() const {
    return this->color;
}

std::string Car::get_vin() const {
    return this->vin;
}

bool Car::get_damage() const {
    return this->damage;
}

void Car::set_model(const std::string &model_) {
    if(model_.length() < 0 || model_.length() > 20) {
        throw std::runtime_error("WRONG NAME OF MODEL\n");
    }
    this->model = model_;
}

void Car::set_color(const std::string &color_) {
    if(color_.length() < 0 || color_.length() > 20) {
        throw std::runtime_error("WRONG NAME OF COLOR\n");
    }
    this->color = color_;
}

void Car::set_vin(const std::string &vim_) {
    if(vim_.length() != 17) {
        throw std::runtime_error("VIM NUMBER IS INCORRECT\n");
    }
    this->vin = vim_;
}

void Car::set_damage(const bool &damage_) {
    if(damage_ || !damage_) {
        this->damage = damage_;
    }
    else {
        throw std::runtime_error("DAMAGE SHOULD BE TRUE/FALSE");
    }
}

Car::Car(const std::string& brand, const std::string& model, int price, int range, const std::string& color,
         const std::string& vin, bool& damage) : Vehicle(brand, price, range) {
    set_model(model);
    set_color(color);
    set_vin(vin);
    set_damage(damage);
}

void Car::info() const {
    std::cout << "BRAND: " << get_brand() << " | MODEL: " << model << " | PRICE: " << get_price() << " | RANGE: "
    << get_range()<< " | COLOR: " << get_color() << " | VIN: " << get_vin() << " | DAMAGE: " << std::boolalpha
    << get_damage() << '\n';
}

std::ostream &operator<<(std::ostream &out, const Car& car) {
    return out << "BRAND: " << car.get_brand() << " | MODEL: " << car.get_model() << " | PRICE: " << car.get_price()
    << " | RANGE: "<< car.get_range() << " | COLOR: " << car.get_color() << " | VIN: " << car.get_vin() << " | DAMAGE: "
    << std::boolalpha << car.get_damage()<< '\n';
}

void Car::show_cars_data_base(const std::vector<Car>& vec) {
    for(const auto & i : vec) {
        std::cout << i;
    }
}

void Car::sort_by_price(std::vector<Car> &vec) {
    std::sort(vec.begin(), vec.end(), [](const Car& lhs, const Car& rhs){
        return lhs.get_price() < rhs.get_price();
    });
}

void Car::sort_by_range(std::vector<Car> &vec) {
    std::sort(vec.begin(), vec.end(), [](const Car& lhs, const Car& rhs){
        return lhs.get_range() < rhs.get_range();
    });
}

std::vector<Car> Car::cars_with_damage(const std::vector<Car>& vec) {
    std::vector<Car> result;
    for(auto & i : vec) {
        if(i.get_damage()) {
            result.emplace_back(i);
        }
    }
    return result;
}

std::vector<Car> Car::cars_without_damage(const std::vector<Car>& vec) {
    std::vector<Car> result;
    for(const auto & i : vec) {
        if(!i.get_damage()) {
            result.emplace_back(i);
        }
    }
    return result;
}

void Car::deleted_by_vin(std::vector<Car>& vec) {
    std::string vim_;
    std::cout << "TYPE VIM: ";
    std::cin >> vim_;
    for(int i = 0; i < vec.size(); ++i) {
        if(vec[i].get_vin() == vim_) {
            vec.erase(vec.begin() + i);
        }
    }
}

void Car::add_car(std::vector<Car>& vec) {
    std::string brand_, model_, color_, vin_;
    int price_, range_;
    bool damage_;
    std::cout << "TYPE BRAND: ";
    std::cin >> brand_; std::cin.get();
    std::cout << "TYPE MODEL: ";
    std::getline(std::cin, model_);
    std::cout << "TYPE PRICE: ";
    std::cin >> price_; std::cin.get();
    std::cout << "TYPE RANGE: ";
    std::cin >> range_; std::cin.get();
    std::cout << "TYPE COLOR: ";
    std::getline(std::cin, color_);
    std::cout << "TYPE VIM: ";
    std::getline(std::cin, vin_);
    std::cout << "TYPE DAMAGE (0/1): ";
    std::cin >> damage_; std::cin.get();
    vec.emplace_back(Car{brand_, model_, price_, range_, color_, vin_,damage_});
}

std::vector<Car> Car::read_cars_file(const std::string &filename) {
    std::ifstream file;
    file.open(filename);
    if(!file.is_open()) {
        throw std::runtime_error("FILE NOT FOUND\n");
    }
    std::string brand_, model_, color_, vim_, separator;
    int price_, range_;
    bool damage_;
    std::vector<Car> vec;
    while(!file.eof()) {
        std::getline(file, brand_);
        std::getline(file, model_);
        file >> price_; file.get();
        file >> range_; file.get();
        std::getline(file, color_);
        std::getline(file, vim_);
        file >> damage_; file.get();
        std::getline(file, separator);
        vec.emplace_back(Car{brand_, model_, price_, range_, color_, vim_, damage_});
    }
    return vec;
}

void Car::save_cars(const std::vector<Car> &vec, const std::string &filename) {
    std::ofstream file;
    file.open(filename, std::ios::app);
    if(!file.is_open()) {
        throw std::runtime_error("ERROR\n");
    }
    for(const auto & i : vec) {
        file << i.get_brand() << '\n' << i.get_model() << '\n' << i.get_price() << '\n' << i.get_range() << '\n'
        << i.get_color() << '\n' << i.get_vin() << '\n' << i.get_damage() << '\n' << "=====================\n";
    }
    std::cout << "Saved successfully :)!" << '\n' << "You saved your database in: " << filename << '\n';
}