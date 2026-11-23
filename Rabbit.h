#ifndef RABBIT_H
#define RABBIT_H
#include "Pet.h"
#include <iostream>

class Rabbit : public Pet {
public:
    Rabbit(const std::string& petName) : Pet(petName) {}

    void makeSound() const override {
        std::cout << name << ": *kica po pokoju i szybko rusza noskiem*\n";
    }

    std::string getSpecies() const override {
        return "Krolik";
    }

    // krolik uwielbia marchewke wiec jedzenie podbija mu tez humor
    void feed() override {
        hunger -= 25;
        happiness += 10;
        energy += 5;
        clampStats();
        std::cout << name << " schrupal cala marchewke z predkoscia swiatla.\n";
    }

    // skacze jak szalony wiec duzo szczescia ale szybko sie meczy
    void play() override {
        if (energy < 20) {
            std::cout << name << " padl na bok i udaje dywanik, nie ma sily.\n";
            return;
        }
        happiness += 25;
        energy -= 20;
        hunger += 10;
        clampStats();
        std::cout << name << " robi salta w powietrzu i kica po meblach!\n";
    }
};

#endif