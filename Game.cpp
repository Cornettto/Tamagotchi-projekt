#include "Game.h"
#include "Dog.h"
#include "Cat.h"
#include "Spider.h"
#include "Hamster.h"
#include "Pigeon.h"
#include <iostream>
#include <limits> //smietnik na czyszczenia blednego wejscia

Game::Game() : isRunning(true), turnCount(1) {
    // !! tu ekran wyboru peta i imienia
    initPet(); 
}
void Game::initPet(){
    int choice = 0;
    std::string petName;

    std::cout << "Wybierz zwierzaka:\n"
              << "1. Pies\n"
              << "2. Kot\n"
              << "3. Pajak\n"
              << "4. Chomik\n"
              << "5. Golab\n"
              << "Wybor: ";
    std::cin >> choice;

    // zeby nie wywalalo petli jak wpisze litere zamiast cyfry
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        choice = 1;
    }
    std::cout << "Podaj imie dla zwierzaka: ";
    std::cin >> petName;

    switch (choice){ // podmienione na switcha ten if bo jednak bedzie wiecj zwierzakow
        case 2:  playerPet = std::make_unique<Cat>(petName); break;
        case 4:  playerPet = std::make_unique<Hamster>(petName); break;
        case 3:  playerPet = std::make_unique<Spider>(petName); break;
        case 5:  playerPet = std::make_unique<Pigeon>(petName); break;
        default: playerPet = std::make_unique<Dog>(petName); break;//pies bedzie domyslnie
    }
}


void Game::showStatus() const {
    std::cout << "\n=== TURA: " << turnCount << " ===\n";
    std::cout << "Zwierzak: " << playerPet->getName() 
              << " (" << playerPet->getSpecies() << ")\n";
    std::cout << "Glod: " << playerPet->getHunger() << "/100 | "
              << "Szczescie: " << playerPet->getHappiness() << "/100 | "
              << "Energia: " << playerPet->getEnergy() << "/100\n";
    std::cout << "====================\n";
}

void Game::showMenu() const {
    std::cout << "1. Nakarm\n";
    std::cout << "2. Pobaw sie\n";
    std::cout << "3. Poloz spac\n";
    std::cout << "4. Pomin ture (czekaj)\n";
    std::cout << "0. Wyjdz z gry\n";
    std::cout << "Wybierz akcje: ";
}

void Game::handleInput() {
    int choice;
    std::cin >> choice;
    if (std::cin.fail()) { //pilnuje zeby byla wpisana cyfra a nie liczba
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wpisz liczbe od 0 do 4!\n";
        return;
    }

    
    switch (choice) {
        case 1: playerPet->feed(); break;
        case 2: playerPet->play(); break;
        case 3: playerPet->sleep(); break;
        case 4: std::cout << "Czas plynie...\n"; break;
        case 0: isRunning = false; return;
        default: std::cout << "Nieznana opcja.\n"; return;
    }

    playerPet->makeSound();
    playerPet->update();
    turnCount++;
}

void Game::run() {
    std::cout << "Witaj w Tamagotchi!\n";

    while (isRunning && playerPet->checkIsAlive()) {
        showStatus();
        showMenu();
        handleInput();
    }

    if (!playerPet->checkIsAlive()) {
        std::cout << "\nNiestety, " << playerPet->getName() << " nie przetrwal...\n";
    }
    std::cout << "Koniec gry.\n";
}