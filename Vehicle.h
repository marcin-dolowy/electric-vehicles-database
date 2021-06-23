#include "libs.h"

class Vehicle {
protected:
    std::string brand;
    int price;
    int range;
public:
    Vehicle(std::string  brand, int price, int range) : brand(std::move(brand)), price(price), range(range) {}
    Vehicle() : brand(" "), price(0), range(0) {};
    ~Vehicle() = default;

    std::string get_brand() const;
    int get_price() const;
    int get_range() const;

    void set_brand(const std::string& brand_);
    void set_price(int price_);
    void set_range(int range_);

    virtual void info() const;
    friend std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle);
    friend std::istream& operator>>(std::istream& in, Vehicle& vehicle);
    static void show_data_base(const std::vector<Vehicle>& vec);
    static void sort_by_price(std::vector<Vehicle>& vec);
    static void sort_by_range(std::vector<Vehicle>& vec);
};