#ifndef SNAKE_H
#define SNAKE_H
#include "Pet.h"
#include <iostream>

class Snake : public Pet {
public:
    Snake(const std::string& petName) : Pet(petName) {}

    void makeSound() const override {
        std::cout << name << ": Sssssss...\n";
    }

    std::string getSpecies() const override {
        return "Wąż";
    }

    // waz je rzadko ale konkretnie wiec zbija duzo glodu ale zamula od trawienia
    void feed() override {
        hunger -= 50;
        energy -= 10;
        clampStats();
        std::cout << name << " polknal cala mysz i teraz lezy jak kloda.\n";
    }

    //nie biega za pilka tylko pelza po rece wiec malo energii traci
    void play() override {
        if (energy < 10) {
            std::cout << name << " schowal sie pod kamieniem i nie wychodzi.\n";
            return;
        }
        happiness += 15;
        energy -= 5;
        clampStats();
        std::cout << name << " owinal sie wokol szyi i udaje szalik.\n";
    }

    //zmiennocieplny wiec wolno traci staty co ture
    void update() override {
        hunger += 2;
        happiness -= 2;
        energy -= 3;
        clampStats();
        ageTurns++;
    }
};

#endif