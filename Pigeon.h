#ifndef PIGEON_H
#define PIGEON_H
#include "Pet.h"
#include <iostream>

class Pigeon : public Pet {
public:
    Pigeon(const std::string& petName) : Pet(petName) {}

    void makeSound() const override {
        std::cout << name << ": Gruuu gruuu! *patrzy podejrzliwie*\n";
    }

    std::string getSpecies() const override {
        return "Golab";
    }

    // golab zje wszystko z ziemi wiec jedzenie daje mu tez szczescie
    void feed() override {
        hunger -= 35;
        happiness += 15;
        energy += 5;
        clampStats();
        std::cout << name << " wciagnal starego precla i jest wniebowziety.\n";
    }

    // zamiast normalnej zabawy robi rozrobe
    void play() override {
        if (energy < 15) {
            std::cout << name << " napuszyl piora i nie reaguje.\n";
            return;
        }
        happiness += 20;
        energy -= 15;
        hunger += 15;
        clampStats();
        std::cout << name << " ukradl komus frytke i odlecial na latarnie!\n";
    }
};

#endif