#include <utility>

#include "Vehicle.h"

class Car : public Vehicle {
private:
    std::string model;
    std::string color;
    std::string vim;
    bool damage;
public:
    Car(const std::string& brand, const std::string& model, int price, int range,const std::string& color,
        const std::string& vim, bool damage);
    Car() = default;
    ~Car() = default;
    void info() const override;
    friend std::ostream& operator<<(std::ostream& out, const Car& car);
    static void show_cars_data_base(const std::vector<Car>& vec);
    static std::vector<Car> all_damage_cars(const std::vector<Car>& vec);
    static std::vector<Car> car_without_damage(const std::vector<Car>& vec);
    static void deleted_by_vim(std::vector<Car>& vec);
};

