#include "Pet.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>

Pet::Pet(const std::string& petName)
    : name(petName), hunger(30), happiness(70), energy(80), isAlive(true) {}

void Pet::clampStats() {
    hunger = std::clamp(hunger, 0, 100);
    happiness = std::clamp(happiness, 0, 100);
    energy = std::clamp(energy, 0, 100);
    cleanliness = std::clamp(cleanliness, 0, 100);

    // warunek przegranej caly
    if (hunger >= 100 || happiness <= 0 || energy <= 0) {
        isAlive = false;
    }
}

void Pet::updateHygieneAndHealth() {
    cleanliness -= 5;
    if (cleanliness < 25) {
        happiness -= 5; // jak siedzi w syfie to spada mu humor
    }

    // 30% szans na chorobe jak jest mega brudny albo zaglodzony
    if (!isSick && (cleanliness < 15 || hunger > 85) && (rand() % 100 < 30)) {
        isSick = true;
        std::cout << "[UWAGA] " << name << " zachorowal! Podaj mu szybko lek!\n";
    }

    // jak jest chory to co ture leci mocniej w dol ze statami
    if (isSick) {
        std::cout << "[CHOROBA] " << name << " meczy sie i zle sie czuje...\n";
        hunger += 5;
        happiness -= 8;
        energy -= 8;
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
    hunger += 5;
    happiness -= 5;
    energy -= 5;
    ageTurns++; // zwierzak starzeje sie o 1 ture
    updateHygieneAndHealth();
    clampStats();
    
} 

std::string Pet::getStage() const {
    if (ageTurns < 5)  return "Maluch";
    if (ageTurns < 12) return "Nastolatek";
    if (ageTurns < 20) return "Dorosly";
    return "Stary";
}


void Pet::modifyStats(int dHunger, int dHappiness, int dEnergy){ //tez do losowego
    hunger += dHunger;
    happiness += dHappiness;
    energy += dEnergy;
    clampStats(); // od razu sprawdza zakres 0-100 i czy nie padl
}


void Pet::saveToFile(std::ofstream& file) const {
   
    
    file << getSpecies() << "\n"//zapisz gatunek imie i staty 
         << name << "\n"
         << hunger << " " << happiness << " " << energy << "\n";
}


void Pet::loadFromFile(std::ifstream& file) {
    file >> hunger >> happiness >> energy;
    clampStats();
}


//na wyswietklanie mordki
void Pet::drawFace() const {
    if (!isAlive) {
        std::cout << "   ( x _ x )  <-- RIP\n";
    } else if (hunger > 75) {
        std::cout << "   ( O _ O )  <-- DAJ JESC!\n";
    } else if (energy < 25) {
        std::cout << "   ( - . - ) zZz  <-- PADAM\n";
    } else if (happiness > 75) {
        std::cout << "   ( ^ w ^ )  <-- ALE SUPER!\n";
    } else if (happiness < 30) {
        std::cout << "   ( ; _ ; )  <-- SMUTNO MI\n";
    } else {
        std::cout << "   ( o _ o )  <-- JEST GIT\n";
    }
}



void Pet::clean() {
    cleanliness = 100;
    energy -= 10;
    clampStats();
    std::cout << name << " zostal wykapany i pachnie jak nowy!\n";
}

void Pet::heal() {
    if (!isSick) {
        std::cout << name << " jest zdrowy, nie potrzebuje lekow.\n";
        return;
    }
    isSick = false;
    energy += 15;
    happiness -= 5; // syrop jest niedobry
    clampStats();
    std::cout << name << " dostal lekarstwo i wyzdrowial!\n";
}


Pet& Pet::operator+=(int bonusHappiness) {
    happiness += bonusHappiness;
    clampStats();
    return *this;
}

Pet& Pet::operator++() {
    update(); // wywoluje wirtualne update() wiec dziala dla kazdego gatunku
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Pet& pet) {
    os << "Zwierzak: " << pet.name
       << " (" << pet.getSpecies() << " - " << pet.getStage() << ")"
       << (pet.isSick ? " [CHORY!]" : "") << "\n"
       << "Glod: " << pet.hunger << "/100 | "
       << "Szczescie: " << pet.happiness << "/100 | "
       << "Energia: " << pet.energy << "/100 | "
       << "Czystosc: " << pet.cleanliness << "/100";
    return os;
}