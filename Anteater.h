#ifndef ANTEATER_H
#define ANTEATER_H
#include "Pet.h"
#include <iostream>

class Anteater : public Pet {
public:
    Anteater(const std::string& petName) : Pet(petName) {}


    void makeSound() const override {
        std::cout << name << ": *siorbie dlugim jezykiem i weszy po podlodze*\n";
    }

    std::string getSpecies() const override {
        return "Mrówkojad";
    }



    // wciaga mrowki wiec od razu najedzony
    void feed() override {
        hunger -= 35;
        energy += 10;
        clampStats();
        std::cout << name << " wciagnal nosem cala kolonie mrowek i jest zadowolony.\n";
    }




    // ciagle szuka jedzenia wiec troche szybciej robi sie glodny co ture
    void update() override {
        hunger += 7;
        happiness -= 4;
        energy -= 5;
        clampStats();
    }
};

#endif