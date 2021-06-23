
#include "Car.h"
int main() {

    std::vector<Vehicle> vec {{"MERCEDES", 16000, 300}, {"TESLA", 30000, 700},
                              {"BMW", 15000, 370}, {"PORSCHE", 60000, 730}};
    Vehicle v1 {"AUDI", 12000, 480};
    vec.emplace_back(v1);

/*    Vehicle::show_data_base(vec);
    Vehicle::sort_by_range(vec);
    std::cout << "AFTER SORT" << '\n';
    Vehicle::show_data_base(vec);*/

    Car c1{"AUDI", "ETRON", 120000, 480, "BLACK", "LT3109646464", true};
    c1.info();
    return 0;
}
