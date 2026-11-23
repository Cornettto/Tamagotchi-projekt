#ifndef SPIDER_H
#define SPIDER_H

#include "Pet.h"
#include <iostream>

class Spider : public Pet {
public:
    Spider(const std::string& petName) : Pet(petName) {}

    void makeSound() const override {
        std::cout << name << ": *ciche tupanie ośmoma nogami*\n";
    }

    std::string getSpecies() const override {
        return "Pajak";
    }

    // pajak ma wywalone w zabawe wiec malo mu daje szczescia
    void play() override {
        if (energy < 10) {
            std::cout << name << " siedzi w pajeczynie i nie ma sily.\n";
            return;
        }
        happiness += 5;
        energy -= 10;
        clampStats();
        std::cout << name << " przeszedl sie po scianie i wrocil w kat.\n";
    }

    // wolny metabolizm - wolno robi sie glodny i malo traci energii taki luzny zwierzak
    void update() override {
        hunger += 2;
        happiness -= 2;
        energy -= 2;
        clampStats();
    }
};

#endif