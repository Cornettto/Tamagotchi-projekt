#ifndef TURTLE_H
#define TURTLE_H
#include "Pet.h"
#include <iostream>

class Turtle : public Pet {
public:
    Turtle(const std::string& petName) : Pet(petName) {}

    void makeSound() const override {
        std::cout << name << ": *sapie cicho i chowa glowe w pancerzu*\n";
    }

    std::string getSpecies() const override {
        return "Zółw";
    }



    // zolw je wolno ale salata poprawia mu humor
    void feed() override {
        hunger -= 20;
        happiness += 10;
        energy += 5;
        clampStats();
        std::cout << name << " przez piec minut przezuwal jeden lisc salaty.\n";
    }

    // zolw zyje sto lat wiec jego staty spadaja mega wolno co ture
    void update() override {
        hunger += 1;
        happiness -= 1;
        energy -= 1;
        clampStats();
        ageTurns++;
    }
};

#endif