#include "Game.h"
#include "Dog.h"
#include "Cat.h"
#include "Spider.h"
#include "Hamster.h"
#include "Pigeon.h"
#include "Snake.h"
#include "Snail.h"
#include "Turtle.h"
#include "Fish.h"
#include "Rabbit.h"
#include "Anteater.h"
#include "Gecko.h"
#include <iostream>
#include <limits> //smietnik na czyszczenia blednego wejscia
#include <fstream>
Game::Game() : isRunning(true), turnCount(1) {
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
              << "6. Waz\n"
              << "7. Slimak\n"
              << "8. Zolw\n"
              << "9. Ryba\n"
              << "10. Krolik\n"
              << "11. Mrowkojad\n"
              << "12. Gekon\n"
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
        case 6:  playerPet = std::make_unique<Snake>(petName); break;
        case 7:  playerPet = std::make_unique<Snail>(petName); break;
        case 8:  playerPet = std::make_unique<Turtle>(petName); break;
        case 9:  playerPet = std::make_unique<Fish>(petName); break;
        case 10: playerPet = std::make_unique<Rabbit>(petName); break;
        case 11: playerPet = std::make_unique<Anteater>(petName); break;
        case 12: playerPet = std::make_unique<Gecko>(petName); break;
        default: playerPet = std::make_unique<Dog>(petName); break;//pies bedzie domyslnie
    }
}


void Game::showStatus() const {
    std::cout << "\n=== TURA: " << turnCount << " ===\n";
    std::cout << *playerPet << "\n"; // przeciazony operator << wypisuje wszystkie staty i czy jest chory
    playerPet->drawFace();           // rysuje mordke zaleznie od humoru glodu i energii
    std::cout << "====================\n";
}

void Game::showMenu() const {
    std::cout << "1. Nakarm\n";
    std::cout << "2. Pobaw sie\n";
    std::cout << "3. Poloz spac\n";
    std::cout << "4. Pomin ture (czekaj)\n";
    std::cout << "5. Zapisz gre\n";
    std::cout << "6. Zagraj w kubki (mini gra)\n";
    std::cout << "7. Poglaszcz\n";
    std::cout << "8. Wykap / Posprzataj\n";
    std::cout << "9. Podaj lekarstwo\n";
    std::cout << "0. Wyjdz z gry\n";
    std::cout << "Wybierz akcje: ";
}
void Game::triggerRandomEvent() {
    turnsWithoutEvent++;
    int chance = rand() % 100; //losuje liczbe od 0 do 99
    if (turnsWithoutEvent >= 4) {
        chance = rand() %48;
    }

    if (chance < 48) {
        turnsWithoutEvent = 0; // reset licznika bo cos sie zadzialo
    }

    if (chance < 20) {
        // 20% szans na darmowe jedzenie
        std::cout << "[LOSOWE] " << playerPet->getName() << " znalazl starego chrupka pod kanapa! (-15 glodu, +5 szczescia)\n";
        playerPet->modifyStats(-15, 5, 0);
    } 
    else if (chance < 30) {
        //10% szans na glupawke
        std::cout << "[LOSOWE] " << playerPet->getName() << " dostal naglej glupawki i biega w kolko! (+15 szczescia, -10 energii)\n";
        playerPet->modifyStats(0, 15, -10);
    } 
    else if (chance < 28) {
        //8% szans na regeneracje energii
        std::cout << "[LOSOWE] " << playerPet->getName() << " znalazl cieple miejsce i ucial mikro-drzemke. (+15 energii)\n";
        playerPet->modifyStats(0, 0, 15);
    } 
    else if (chance < 36) {
        // 8% szans na akcje negatywna (stres)
        std::cout << "[LOSOWE] Ktos wlaczyl odkurzacz! " << playerPet->getName() << " jest w szoku. (-15 szczescia, -5 energii)\n";
        playerPet->modifyStats(0, -15, -5);
    } 
    else if (chance < 43) {
        //7% szans na zatrucie
        std::cout << "[LOSOWE] " << playerPet->getName() << " zjadl cos podejrzanego z podlogi i teraz go muli. (+15 glodu, -10 szczescia)\n";
        playerPet->modifyStats(15, -10, 0);
    } 
    else if (chance < 48) {
        // 5% szans na rzadki pozytywny event
        std::cout << "[LOSOWE] " << playerPet->getName() << " odkryl swoja zaginiona ulubiona zabawke! (+25 szczescia)\n";
        playerPet->modifyStats(0, 25, 0);
    }
    //od 48 do 99 (52% szans) nic sie nie dzieje zeby nie spamowalo co ture
}

void Game::playCupGame() {
    int secretCup = (rand() % 3) + 1; // losuje kubek 1, 2 albo 3
    int guess = 0;

    std::cout << "\n[MINI GRA] Pod ktorym kubkiem (1, 2 lub 3) jest smaczek? ";
    std::cin >> guess;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Miales wpisac 1, 2 albo 3! Zwierzak sie pogubil.\n";
        return;
    }

    if (guess == secretCup) {
        std::cout << "TRAFIONY! " << playerPet->getName() << " zjadl smaczka i skacze z radosci! (-15 glodu, +25 szczescia, -10 energii)\n";
        playerPet->modifyStats(-15, 25, -10);
    } else {
        std::cout << "PUDLO! Smaczek byl pod kubkiem nr " << secretCup << ". " << playerPet->getName() << " jest zawiedziony. (-10 szczescia, -10 energii)\n";
        playerPet->modifyStats(0, -10, -10);
    }
}




void Game::handleInput() {
    int choice;
    std::cin >> choice;
    if (std::cin.fail()) { // pilnuje zeby byla wpisana liczba a nie tekst
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wpisz liczbe z menu!\n";
        return;
    }

    switch (choice) {
        case 1: playerPet->feed(); break;
        case 2: playerPet->play(); break;
        case 3: playerPet->sleep(); break;
        case 4: std::cout << "Czas plynie...\n"; break;
        case 5: {
            std::ofstream file("save.txt");
            if (file.is_open()) {
                playerPet->saveToFile(file);
                std::cout << "Zapisano stan gry do save.txt!\n";
            }
            return; // nie liczy tego jako tury
        }
        case 6: playCupGame(); break;
        case 7:
            *playerPet += 10; // przeciazony operator += dodaje +10 szczescia
            std::cout << "Poglaskales " << playerPet->getName() << "! (+10 szczescia)\n";
            break;
        case 8: playerPet->clean(); break;
        case 9: playerPet->heal(); break;
        case 0: isRunning = false; return;
        default: std::cout << "Nieznana opcja.\n"; return;
    }

    playerPet->makeSound();
    ++(*playerPet); // przeciazony operator ++ (uplyw tury)
    triggerRandomEvent();
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