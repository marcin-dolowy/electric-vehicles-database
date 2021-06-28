#include "Car.h"

std::string Car::get_model() const {
    return this->model;
}

std::string Car::get_color() const {
    return this->color;
}

std::string Car::get_vim() const {
    return this->vim;
}

bool Car::get_damage() const {
    return this->damage;
}

void Car::set_model(const std::string &model_) {
    if(model_.length() < 0 || model.length() > 20) {
        throw std::runtime_error("WRONG NAME OF MODEL\n");
    }
    this->model=model_;
}

void Car::set_color(const std::string &color_) {
    if(color_.length() < 0 || color_.length() > 20) {
        throw std::runtime_error("WRONG NAME OF COLOR\n");
    }
    this->color = color_;
}

void Car::set_vim(const std::string &vim_) {
    if(vim_.length() != 17) {
        throw std::runtime_error("VIM NUMBER IS INCORRECT\n");
    }
    this->vim = vim_;
}

void Car::info() const {
    std::cout << "BRAND: " << Vehicle::brand << " | MODEL: " << model << " | PRICE: " << price << " | RANGE: " << range
    << " | COLOR: " << color << " | VIM: " << vim << " | DAMAGE: " << std::boolalpha << damage << '\n';
}

std::ostream &operator<<(std::ostream &out, const Car& car) {
    return out << "BRAND: " << car.brand << " | MODEL: " << car.model << " | PRICE: " << car.price << " | RANGE: "
    << car.range << " | COLOR: "<< car.color << " | VIM: " << car.vim << " | DAMAGE: " << std::boolalpha << car.damage << '\n';
}

std::istream &operator>>(std::istream &in, Car &car) {
    std::cout << "TYPE BRAND: ";
    in >> car.brand; in.get();
    std::cout << "TYPE MODEL: ";
    in >> car.model; in.get();
    std::cout << "TYPE PRICE: ";
    in >> car.price; in.get();
    std::cout << "TYPE RANGE: ";
    in >> car.range; in.get();
    std::cout << "TYPE COLOR: ";
    in >> car.color; in.get();
    std::cout << "TYPE VIM: ";
    in >> car.vim; in.get();
    std::cout << "TYPE DAMAGE (0/1): ";
    in >> car.damage; in.get();
    return in;

}

void Car::show_cars_data_base(const std::vector<Car>& vec) {
    for(const auto & i : vec) {
        std::cout << i;
    }
}

std::vector<Car> Car::cars_with_damage(const std::vector<Car>& vec) {
    std::vector<Car> result;
    for(auto & i : vec) {
        if(i.damage) {
            result.emplace_back(i);
        }
    }
    return result;
}

std::vector<Car> Car::cars_without_damage(const std::vector<Car>& vec) {
    std::vector<Car> result;
    for(const auto & i : vec) {
        if(!i.damage) {
            result.emplace_back(i);
        }
    }
    return result;
}

void Car::deleted_by_vim(std::vector<Car>& vec) {
    std::string vim_;
    std::cout << "TYPE VIM: ";
    std::cin >> vim_;
    for(int i = 0; i < vec.size(); ++i) {
        if(vec[i].vim == vim_) {
            vec.erase(vec.begin() + i);
        }
    }
}

std::vector<Car> Car::read_car_file(const std::string &filename) {
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
        vec.emplace_back(brand_, model_, price_, range_, color_, vim_, damage_);
    }
    return vec;
}






