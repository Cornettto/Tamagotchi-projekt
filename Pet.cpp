#include "Pet.h"
#include <algorithm>
#include <iostream>

Pet::Pet(const std::string& petName)
    : name(petName), hunger(30), happiness(70), energy(80), isAlive(true) {}

void Pet::clampStats() {
    hunger = std::clamp(hunger, 0, 100);
    happiness = std::clamp(happiness, 0, 100);
    energy = std::clamp(energy, 0, 100);

    // warunek przegranej ale nie caly (to sie potem dokonczy)
    if (hunger >= 100 || happiness <= 0) {
        isAlive = false;
    }
}

void Pet::feed() {
    hunger -= 25;
    energy += 5;
    clampStats();
    std::cout << name << " zostal nakarmiony.\n";
}

void Pet::play() {
    if (energy < 15) {
        std::cout << name << " jest zbyt zmeczony na zabawe!\n";
        return;
    }
    happiness += 20;
    energy -= 15;
    hunger += 10;
    clampStats();
    std::cout << name << " swietnie sie bawi!\n";
}

void Pet::sleep() {
    energy += 40;
    hunger += 15;
    clampStats();
    std::cout << name << " ucial sobie drzemke.\n";
}

void Pet::update() {
    // uplyw czasu na jedna turee
    hunger += 5;
    happiness -= 5;
    energy -= 5;
    clampStats();
}