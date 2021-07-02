#include "Bike.h"
#include "Car.h"

int main() {
    try {
        std::vector<Vehicle> v{{"MERCEDES", 16000, 300},
                                 {"TESLA",    30000, 700},
                                 {"BMW",      15000, 370},
                                 {"PORSCHE",  60000, 730}};
        Vehicle v1{"AUDI", 12000, 480};
        v.emplace_back(v1);


        std::vector<Car> c5 = Car::read_car_file("car.txt");
        Car::show_cars_data_base(c5);
        std::cout << "=====NO DAMAGE=====\n";
        std::vector<Car> result = Car::cars_without_damage(c5);
        Car::show_cars_data_base(result);
        Car::sort_by_price(c5);
        std::cout << "========SORTED BY PRICE========\n";
        Car::show_cars_data_base(c5);
        std::cout << "========SORTED BY RANGE========\n";
        Car::sort_by_range(c5);
        Car::show_cars_data_base(c5);



    } catch (std::runtime_error& error) {
        std::cout << error.what() << '\n';
    }
        return 0;
}
