#include "Car.h"

Car::Car(const std::string &brand, const std::string &model, int price, int range, const std::string &color,
         const std::string &vim, bool damage) : Vehicle(brand, price, range) {
    this->model = model;
    this->color = color;
    this->vim = vim;
    this->damage = damage;
}

void Car::info() const {
    std::cout << "BRAND: " << Vehicle::brand << " | MODEL: " << model << " | PRICE: " << price << " | RANGE: " << range
    << " | COLOR: " << color << " | VIM: " << vim << " | DAMAGE: " << std::boolalpha << damage << '\n';
}

void Car::show_cars_data_base(const std::vector<Car>& vec) {
    for(const auto & i : vec) {
        i.info();
    }
}

std::ostream &operator<<(std::ostream &out, const Car& car) {
    out << car.brand << " " << car.model << " " << car.price << " " << car.range << " " << car.color << " " << car.vim << " " << car.damage;
    return out;
}

std::vector<Car> Car::all_damage_cars(const std::vector<Car>& vec) {
    std::vector<Car> result;
    for(auto & i : vec) {
        if(i.damage) {
            result.emplace_back(i);
        }
    }
    return result;
}

std::vector<Car> Car::car_without_damage(const std::vector<Car>& vec) {
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

