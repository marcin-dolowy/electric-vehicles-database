#include "Bike.h"
#include "Car.h"

void car_menu(std::vector<Car>& car) {
    char choice{};

    std::cout << "================================================\n";
    std::cout << "********************* CARS *********************\n";
    std::cout << "================================================\n";
    std::cout << "1. Load all electric cars\n" << "2. Add new car\n" << "3. Delete existing car\n"
              << "4. Sort all cars by price\n" << "5. Sort all cars by range\n"
              << "6. Show all damaged cars\n" << "7. Show all non-damaged cars\n"
              << "8. Save electric cars to file\n" << "0. Back\n";

    while (choice != '0') {
        std::cout << "Type Options: ";
        std::cin >> choice;
        std::cout << '\n';

        switch (choice) {
            case '1': {
                std::cout << "====== ALL ELECTRIC CARS ======\n";
                Car::show_cars_data_base(car);
                break;
            }
            case '2': {
                Car::add_car(car);
                Car::show_cars_data_base(car);
                break;
            }
            case '3': {
                Car::deleted_by_vin(car);
                Car::show_cars_data_base(car);
                break;
            }
            case '4': {
                std::cout << "====== SORT BY PRICE ======\n";
                Car::sort_by_price(car);
                Car::show_cars_data_base(car);
                break;
            }
            case '5': {
                std::cout << "====== SORT BY RANGE ======\n";
                Car::sort_by_range(car);
                Car::show_cars_data_base(car);
                break;
            }
            case '6': {
                std::cout << "====== CARS WITH DAMAGE ======\n";
                std::vector<Car> result = Car::cars_with_damage(car);
                Car::show_cars_data_base(result);
                break;
            }
            case '7': {
                std::cout << "====== CARS WITHOUT DAMAGE ======\n";
                std::vector<Car> result = Car::cars_without_damage(car);
                Car::show_cars_data_base(result);
                break;
            }
            case '8': {
                Car::save_cars(car, "electric_cars.txt");
                break;
            }
            case '0': {
                break;
            }
            default: {
                std::cout << "Wrong choice" << std::endl;
                break;
            }
        }
    }
}

void bike_menu(std::vector<Bike>& bike) {
    char choice{};

    std::cout << "================================================\n";
    std::cout << "******************** BIKES *********************\n";
    std::cout << "================================================\n";
    std::cout << "1. Load all electric bikes\n" << "2. Add new bike\n"
              << "3. Delete existing bike\n"
              << "4. Sort all bikes by price\n" << "5. Sort all bikes by range\n"
              << "6. Save electric bikes to file\n" << "0. Back\n";

    while (choice != '0') {
        std::cout << "Type Options: ";
        std::cin >> choice;
        std::cout << '\n';

        switch (choice) {
            case '1': {
                std::cout << "====== ALL ELECTRIC BIKES ======\n";
                Bike::show_bikes_data_base(bike);
                break;
            }
            case '2': {
                Bike::add_bike(bike);
                Bike::show_bikes_data_base(bike);
                break;
            }
            case '3': {
                Bike::delete_bike(bike);
                Bike::show_bikes_data_base(bike);
                break;
            }
            case '4': {
                std::cout << "====== SORT BY PRICE ======\n";
                Bike::sort_by_price(bike);
                Bike::show_bikes_data_base(bike);
                break;
            }
            case '5': {
                std::cout << "====== SORT BY RANGE ======\n";
                Bike::sort_by_range(bike);
                Bike::show_bikes_data_base(bike);
                break;
            }
            case '6': {
                Bike::save_bikes(bike, "electric_bikes.txt");
                break;
            }
            case '0': {
                break;
            }
            default: {
                std::cout << "Wrong choice\n";
                break;
            }
        }
    }
}

int main() {
    try {

        std::vector<Car> car = Car::read_cars_file("cars.txt");
        std::vector<Bike> bike = Bike::read_bikes_file("bikes.txt");
        char choice{};

        std::cout << "================================================\n";
        std::cout << "********** ELECTRIC VEHICLE DATA BASE **********\n";
        std::cout << "================================================\n";

        do {
            std::cout << "Menu Options\n";
            std::cout << "1. Cars\n" << "2. Bikes\n" << "3. Exit\n";
            std::cout << "Type Options: ";
            std::cin >> choice;
            std::cout << '\n';
            switch (choice) {
                case '1': {
                    car_menu(car);
                    break;
                }
                case '2': {
                    bike_menu(bike);
                    break;
                }
                case '3': {
                    std::cout << "Exit" << std::endl;
                    return 0;
                }
                default:
                    std::cout << "Wrong choice" << std::endl;
            }
        } while (choice != '3');

    } catch (std::runtime_error &error) {
        std::cout << error.what() << '\n';
    }
}
