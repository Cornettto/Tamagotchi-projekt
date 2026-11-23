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
        return "Mrowkojad";
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
        ageTurns++;
        updateHygieneAndHealth();
        clampStats();
    }


    //prysznic splukuje mu resztki mrowek z dlugiego nosa
    void clean() override {
        cleanliness = 100;
        happiness += 5;
        energy -= 10;
        clampStats();
        std::cout << name << " wzial prysznic i w koncu odkleil sobie mrowki od nosa!\n";
    }
};

#endif