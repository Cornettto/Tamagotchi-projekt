#ifndef DOG_H
#define DOG_H

#include "Pet.h"
#include <iostream>


class Dog : public Pet {
public:
    Dog(const std::string& petName) : Pet(petName) {}

    void makeSound() const override {
        std::cout << name << ": Hau! Hau!\n";
    }

    std::string getSpecies() const override {
        return "Pies";
    }

    // pies szybciej glodny ale bardziej happy z zabawy
    void play() override {
        Pet::play();
        happiness += 5; 
        clampStats();
    }


    void clean() override {
        cleanliness = 100;
        happiness += 5;
        energy -= 10;
        clampStats();
        std::cout << name << " otrzepal sie z wody na cale mieszkanie i jest szczesliwy!\n";
    }
};

#endif 