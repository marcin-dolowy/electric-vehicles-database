#pragma once

#include "Vehicle.h"

class Car : public Vehicle {
protected:
    std::string model;
    std::string color;
    std::string vim;
    bool damage;
public:
    Car(const std::string& brand, std::string model, const int price, const int range, std::string color, std::string vim,
        bool damage): Vehicle(brand, price, range), model(std::move(model)), color(std::move(color)),
        vim(std::move(vim)), damage(damage) {}
    Car() = default;
    ~Car() = default;

    //getters
    std::string get_model() const;
    std::string get_color() const;
    std::string get_vim() const;
    bool get_damage() const;

    //setters
    void set_model(const std::string& model_);
    void set_color(const std::string& color_);
    void set_vim(const std::string& vim_);
    void set_damage(const bool& damage_);

    void info() const override;
    friend std::ostream& operator<<(std::ostream& out, const Car& car);
    friend std::istream& operator>>(std::istream& in, Car& car);
    static void show_cars_data_base(const std::vector<Car>& vec);
    static std::vector<Car> cars_with_damage(const std::vector<Car>& vec);
    static std::vector<Car> cars_without_damage(const std::vector<Car>& vec);
    static void deleted_by_vim(std::vector<Car>& vec);
    static std::vector<Car> read_car_file(const std::string& filename);
};

