#pragma once

#include "Vehicle.h"

class Bike : public Vehicle {
private:
    int gears;
    double weight;
    double frame_size;
public:
    Bike(const std::string& brand, const int price, const int range, const int gears, const double weight,
         const double frame_size);
    Bike() = default;
    ~Bike() = default;

    //getters
    int get_gears() const;
    double get_weight() const;
    double get_frame_size() const;

    //setters
    void set_gears(int gears_);
    void set_weight(double weight_);
    void set_frame_size(double frame_size);

    void info() const override;
    friend std::ostream& operator<<(std::ostream& out, const Bike& bike);
    static void show_bikes_data_base(const std::vector<Bike>& vec);
    static void sort_by_price(std::vector<Bike>& vec);
    static void sort_by_range(std::vector<Bike>& vec);
    static void add_bike(std::vector<Bike>& vec);
    static void delete_bike(std::vector<Bike>& vec);
    static std::vector<Bike> read_bikes_file(const std::string& filename);
    static void save_bikes(const std::vector<Bike>& vec, const std::string& filename);
};