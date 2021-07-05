#pragma once

#include "Vehicle.h"

class Car : public Vehicle {
private:
    std::string model;
    std::string color;
    std::string vin;
    bool damage;
public:
    Car(const std::string& brand, const std::string& model, int price, int range, const std::string& color,
        const std::string& vin, bool& damage);
    Car() = default;
    ~Car() = default;

    //getters
    std::string get_model() const;
    std::string get_color() const;
    std::string get_vin() const;
    bool get_damage() const;

    //setters
    void set_model(const std::string& model_);
    void set_color(const std::string& color_);
    void set_vin(const std::string& vim_);
    void set_damage(const bool& damage_);

    // przeladowana metoda info wypisujaca obiekt klasy Car
    void info() const override;

    // operator wyjscia wypisujacy obiekt klasy Car
    friend std::ostream& operator<<(std::ostream& out, const Car& car);

    // metoda wypisujaca wszystkie obiekty z vectora Car
    static void show_cars_data_base(const std::vector<Car>& vec);

    // metoda, ktora sortuje wszystkie obiekty z vectora Car rosnaco po cenie
    static void sort_by_price(std::vector<Car>& vec);

    // metoda, ktora sortuje wszystkie obiekty z vectora Car rosnaco po zasięgu akumulatora
    static void sort_by_range(std::vector<Car>& vec);

    // metoda ktora inicjalizuje zmienne wprowadzone przez usera i dodaje je do vectora Car
    static void add_car(std::vector<Car>& vec);

    // metoda usuwajaca wybrany obiekt z vectora Car, podajac unikalny dla danego samochodu VIN
    static void deleted_by_vin(std::vector<Car>& vec);

    // metoda zwracaja vector samochodow ktore sa uszkodzone
    static std::vector<Car> cars_with_damage(const std::vector<Car>& vec);

    // metoda zwracajaca wektor samochodow, ktore nie sa uszkodzone
    static std::vector<Car> cars_without_damage(const std::vector<Car>& vec);

    // metoda zwracajaca vector Car, wczytany z pliku
    static std::vector<Car> read_cars_file(const std::string& filename);

    // statyczna metoda, ktora jest odpowiedzialna za zapisanie do pliku vectora Car
    static void save_cars(const std::vector<Car>& vec, const std::string& filename);
};