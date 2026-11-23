#ifndef FISH_H
#define FISH_H
#include "Pet.h"
#include <iostream>

class Fish : public Pet {
public:
    Fish(const std::string& petName) : Pet(petName) {}

    void makeSound() const override {
        std::cout << name << ": Bul bul... *plywa w kolko po akwarium*\n";
    }


    std::string getSpecies() const override {
        return "Ryba";
    }

    //ryby nie poglaszczesz wiec zabawa to pukanie w szybe
    void play() override {
        if (energy < 10) {
            std::cout << name << " lezy przy dnie kolo filtru i nie reaguje.\n";
            return;
        }
        happiness += 12;
        energy -= 5;
        hunger += 5;
        clampStats();
        std::cout << name << " podplynela do szyby i zrobila salto w wodzie!\n";
    }



    // ryba nie ma powiek wiec spi dryfujac w miejscu
    void sleep() override {
        energy += 30;
        hunger += 5;
        clampStats();
        std::cout << name << " dryfuje w miejscu z otwartymi oczami (niby spi).\n";
    }
};

#endif