#ifndef SNAIL_H
#define SNAIL_H

#include "Pet.h"
#include <iostream>

class Snail : public Pet {
public:
    Snail(const std::string& petName) : Pet(petName) {}

    void makeSound() const override {
        std::cout << name << ": *zostawia sluz na podlodze i wolno rusza czulkami*\n";
    }

    std::string getSpecies() const override {
        return "Slimak";
    }

    // slimak nigdzie sie nie spieszy wiec zabawa prawie nie zabiera energii
    void play() override {
        if (energy < 5) {
            std::cout << name << " przykleil sie do szyby i nie ma sily sie ruszyc.\n";
            return;
        }
        happiness += 10;
        energy -= 2;
        hunger += 2;
        clampStats();
        std::cout << name << " przesunal sie o dwa centymetry w pol godziny.\n";
    }

    // jak idzie spac to chowa sie do skorupy i odpoczywa na maksa
    void sleep() override {
        energy += 50;
        hunger += 5;
        clampStats();
        std::cout << name << " schowal sie caly do skorupy i odcial od swiata.\n";
    }
};

#endif