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
    if(vim_.length() != 17)
    {
        throw std::runtime_error("VIM NUMBER IS INCORRECT\n");
    }
    this->vim = vim_;
}

void Car::info() const {
    std::cout << "BRAND: " << Vehicle::brand << " | MODEL: " << model << " | PRICE: " << price << " | RANGE: " << range
    << " | COLOR: " << color << " | VIM: " << vim << " | DAMAGE: " << std::boolalpha << damage << '\n';
}

std::ostream &operator<<(std::ostream &out, const Car& car) {
    return out << "BRAND: " << car.brand << " | MODEL: " << car.model << " | PRICE: " << car.price<<" | RANGE: "
               <<car.range << " | COLOR: "<< car.color << " | VIM: " << car.vim << " | DAMAGE: " << std::boolalpha << car.damage << '\n';
}
//TODO ADD BODY FUNCTION
std::istream &operator>>(std::istream &in, Car &car) {
    std::cout << "TYPE BRAND: ";
    std::getline(in, car.brand);
    std::cout << "TYPE BRAND: ";
}

void Car::show_cars_data_base(const std::vector<Car>& vec) {
    for(const auto & i : vec) {
        std::cout << i;
    }
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


