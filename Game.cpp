#include "Game.h"
#include "Dog.h"
#include <iostream>

Game::Game() : isRunning(true), turnCount(1) {
    // !! tu ekran wyboru peta i imienia
    playerPet = std::make_unique<Dog>("Burek");
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

    // tu sie jakas walidacje zrobi na te litery i cyfry
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
    std::cout << "Witaj w konsolowym Tamagotchi!\n";

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