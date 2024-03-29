#pragma once

#include "libs.h"

class Vehicle {
private:
    std::string brand;
    int price;
    int range;
public:
    Vehicle(const std::string& brand, const int price, const int range);
    Vehicle() : brand(" "), price(0), range(0) {};
    ~Vehicle() = default;

    //getters
    std::string get_brand() const;
    int get_price() const;
    int get_range() const;

    //setters
    void set_brand(const std::string& brand_);
    void set_price(int price_);
    void set_range(int range_);

    // wirtualna metoda info wypisujaca obiekt klasy Vehicle
    virtual void info() const;

    // metoda wypisujaca vector obietkow klasy Vehicle
    static void show_data_base(const std::vector<Vehicle>& vec);

    // opearator wyjscia wypisujacy obiekt klasy
    friend std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle);

    // operator wejscia inicjalizujacy obiekt klasy zmiennymi przekazanymi przez usera
    friend std::istream& operator>>(std::istream& in, Vehicle& vehicle);
};