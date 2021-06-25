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


        Car c1{"AUDI", "ETRON", 120000, 480, "BLACK", "LT3109646464", true};
        //c1.info();
        std::vector<Car> c2 = {{"BMW", "I3", 70000, 480, "BLUE", "LT59381294", true},
                               {"MERCEDES", "ELECTRIC", 300000, 600, "WHITE", "TG53564673", false},
                               {"TESLA", "MODEL S", 500000, 780, "RED", "FV3535353", true}};
        c2.emplace_back(c1);
        //Car::show_cars_data_base(c2);
        //std::cout << "ALL DAMAGE CARS: " << '\n';
        //std::vector<Car> result = Car::car_without_damage(c2);
        //Car::show_cars_data_base(result);
        //Car::deleted_by_vim(c2);
        //Car::show_cars_data_base(c2);

/*        std::cout << '\n';
        Bike b1 {"CROSS", 1500, 50, 21, 12, 12.5};
        std::cout << b1;*/



    } catch (std::runtime_error& error) {
        std::cout << error.what() << '\n';
    }
        return 0;
}
