#pragma once

#include "Vehicle.h"

// klasa Bike, ktora dziedziczy metody oraz pola skladowe klasy Vehicle
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

    // przeladowana metoda info wypisujaca obiekt klasy Bike
    void info() const override;

    // operator wyjscia wypisujacy obiekt klasy Bike
    friend std::ostream& operator<<(std::ostream& out, const Bike& bike);

    // metoda wypisujaca vector obietkow klasy Bike
    static void show_bikes_data_base(const std::vector<Bike>& vec);

    // metoda, ktora sortuje wszystkie obiekty z vectora Bike rosnaco po cenie
    static void sort_by_price(std::vector<Bike>& vec);

    // metoda, ktora sortuje wszystkie obiekty z vectora Bike rosnaco po zasiegu akumulatora
    static void sort_by_range(std::vector<Bike>& vec);

    //metoda ktora inicjalizuje zmienne wprowadzone przez usera i dodaje je do vectora Bike
    static void add_bike(std::vector<Bike>& vec);

    // metoda, usuwajaca wybrany obiekt z vectora Bike
    static void delete_bike(std::vector<Bike>& vec);

    // metoda zwracaja vector Bike, wczytany z pliku
    static std::vector<Bike> read_bikes_file(const std::string& filename);

    // statyczna metoda zapisujaca vector Bike w pliku
    static void save_bikes(const std::vector<Bike>& vec, const std::string& filename);
};