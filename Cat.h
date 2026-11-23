#ifndef CAT_H
#define CAT_H
#include "Pet.h"
#include <iostream>
#include <cstdlib> // do losowania czy kotu sie chce bawic bo moze mu sie nie chciec #leniwy

class Cat : public Pet {
public:
    Cat(const std::string& petName) : Pet(petName) {}

    void makeSound() const override {
        std::cout << name << ": Miau...\n";
    }

    std::string getSpecies() const override {
        return "Kot";
    }

    // kot ma wywalone i w 50% przypadkow ignoruje zabawe
    void play() override {
        if (rand() % 2 == 0) {
            std::cout << name << " popatrzyl na ciebie z pogarda i poszedl sobie.\n";
            happiness -= 5;
            clampStats();
            return;
        }
        Pet::play(); // jak juz sie bawi to normalnie jak w bazowej
    }

    // kot mniej sie meczy w trakcie tury niz pies
    void update() override {
        hunger += 4;
        happiness -= 3;
        energy -= 2;
        clampStats();
    }
};

#endif