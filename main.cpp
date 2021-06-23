#include "Vehicle.h"

int main() {
    Vehicle v1 {"AUDI", 12000, 480};
    v1.info();
    std::cout << v1;
    Vehicle v2;
    std::cin >> v2;
    v2.info();
    return 0;
}
