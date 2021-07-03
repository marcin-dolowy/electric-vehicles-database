#include "Bike.h"
#include "Car.h"

int main() {
    try {
        std::cout << "================================================\n";
        std::cout << "********** ELECTRIC VEHICLE DATA BASE **********\n";
        std::cout << "================================================\n";
        std::cout << "Menu Options\n";
        std::cout << "1. Cars\n" << "2. Bikes\n";

        while (true)
        {
            std::vector<Car> car = Car::read_cars_file("cars.txt");
            std::vector<Bike> bike = Bike::read_bikes_file("bikes.txt");
            int choice = INT_MAX;
            std::cout << "Type Options: ";
            std::cin >> choice;
            int choice2 = INT_MAX;
            switch(choice)
            {
                case 1: {
                    std::cout << "\"====================* CARS *====================\n";
                    std::cout << "1. Load all electric cars\n" << "2. Add new car\n" << "3. Delete existing car\n"
                              << "4. Sort all cars by price\n" << "5. Sort all cars by range\n"
                              << "6. Show all damaged cars\n" << "7. Show all non-damaged cars\n"
                              << "8. Save electric cars to file\n" << "9. Exit\n" << "0. Back\n";
                    while(choice2 != 0)
                    {
                        std::cout << "Type Options: ";
                        std::cin >> choice2;
                        std::cout << '\n';
                            switch (choice2) {
                                case 1: {
                                    Car::show_cars_data_base(car);
                                    break;
                                }
                                case 2: {
                                    Car::add_car(car);
                                    Car::show_cars_data_base(car);
                                    break;
                                }
                                case 3: {
                                    Car::deleted_by_vin(car);
                                    Car::show_cars_data_base(car);
                                    break;
                                }
                                case 4: {
                                    Car::sort_by_price(car);
                                    Car::show_cars_data_base(car);
                                    break;
                                }
                                case 5: {
                                    Car::sort_by_range(car);
                                    Car::show_cars_data_base(car);
                                    break;
                                }
                                case 6: {
                                    std::vector<Car> result = Car::cars_with_damage(car);
                                    Car::show_cars_data_base(result);
                                    break;
                                }
                                case 7: {
                                    std::vector<Car> result = Car::cars_without_damage(car);
                                    Car::show_cars_data_base(result);
                                    break;
                                }
                                case 8: {
                                    Car::save_cars(car, "electric_cars.txt");
                                    break;
                                }
                                case 9: {
                                    return 0;
                                }
                                case 0: {
                                    std::cout << "EXITED CAR\n";
                                    std::cout << "1. Cars\n" << "2. Bikes\n";
                                   break;
                                }
                                default: {
                                    std::cout << "WRONG CHOICE" << std::endl;
                                    break;
                                }
                            }
                    }
                    break;
                }
                case 2: {
                    choice2 = INT_MAX;
                    std::cout << "====================* BIKES *====================\n";
                    std::cout << "1. Load all electric bikes\n" << "2. Add new bike\n" << "3. Delete existing bike\n"
                              << "4. Sort all bikes by price\n" << "5. Sort all bikes by range\n"
                              << "6. Save electric bikes to file\n" << "7. Exit\n";
                    std::cout << "Type Options: ";
                    std::cin >> choice2;
                    switch(choice2)
                    {
                        case 1: {
                            Bike::show_bikes_data_base(bike);
                            break;
                        }
                        case 2: {
                            Bike::add_bike(bike);
                            Bike::show_bikes_data_base(bike);
                            break;
                        }
                        case 3: {
                            Bike::delete_bike(bike);
                            Bike::show_bikes_data_base(bike);
                            break;
                        }
                        case 4: {
                            Bike::sort_by_price(bike);
                            Bike::show_bikes_data_base(bike);
                            break;
                        }
                        case 5: {
                            Bike::sort_by_range(bike);
                            Bike::show_bikes_data_base(bike);
                            break;
                        }
                        case 6: {
                            Bike::save_bikes(bike, "electric_bikes.txt");
                            break;
                        }
                    }
                }
            }
        }
    } catch (std::runtime_error &error) {
    std::cout << error.what() << '\n';
}
}
