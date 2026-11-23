#ifndef HAMSTER_H
#define HAMSTER_H

#include "Pet.h"
#include <iostream>

class Hamster : public Pet {
public:
    Hamster(const std::string& petName) : Pet(petName) {}

    void makeSound() const override {
        std::cout << name << ": Chrup chrup! *biega w kolowrotku*\n";
    }

    std::string getSpecies() const override {
        return "Chomik";
    }

    // wariuje w kolowrotku wiec mega szczesliwy ale szybko pada
    void play() override {
        if (energy < 20) {
            std::cout << name << " zakopal sie w trocinach i spi.\n";
            return;
        }
        happiness += 30;
        energy -= 25;
        hunger += 15;
        clampStats();
        std::cout << name << " kreci kolowrotkiem jakby jutra nie bylo!\n";
    }

    // maly organizm wiec szybko sie meczy i robi glodny co ture
    void update() override {
        hunger += 8;
        happiness -= 5;
        energy -= 8;
        ageTurns++;
        updateHygieneAndHealth();
        clampStats();
        ageTurns++;
    }


    
    // chomik kapie sie w specjalnym piasku i ma z tego mega frajde
    void clean() override {
        cleanliness = 100;
        happiness += 15;
        energy -= 5;
        clampStats();
        std::cout << name << " wytarzal sie w piasku kapielowym i blyszczy jak nowy!\n";
    }
};

#endif