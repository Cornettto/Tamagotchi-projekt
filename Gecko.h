#ifndef GECKO_H
#define GECKO_H
#include "Pet.h"
#include <iostream>

class Gecko : public Pet {
public:
    Gecko(const std::string& petName) : Pet(petName) {}



    void makeSound() const override {
        std::cout << name << ": Mlem! *oblizuje sobie oko jezykiem*\n";
    }

    std::string getSpecies() const override {
        return "Gekon";
    }

    // gekon nie biega tylko wspina sie po szybie wiec malo energii traci
    void play() override {
        if (energy < 10) {
            std::cout << name << " siedzi pod kamieniem i nie ma ochoty wychodzic.\n";
            return;
        }
        happiness += 15;
        energy -= 5;
        hunger += 5;
        clampStats();
        std::cout << name << " przykleil sie do szyby i udaje plastikowa dekoracje.\n";
    }

    
    // jak idzie spac to wygrzewa sie pod lampa i laduje baterie na maksa
    void sleep() override {
        energy += 45;
        hunger += 5;
        clampStats();
        std::cout << name << " wygrzewa sie pod lampa grzewcza i kima z usmiechem.\n";
    }
};

#endif