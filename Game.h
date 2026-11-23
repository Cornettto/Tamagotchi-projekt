#ifndef GAME_H
#define GAME_H

#include "Pet.h"
#include <memory>

class Game {
private:
    std::unique_ptr<Pet> playerPet; //wskaznik na zwierzaka ale chb zle
    bool isRunning;
    int turnCount;
    void initPet(); // wybor gatunku i imienia na starcie
    void showStatus() const;
    void showMenu() const;
    void handleInput();
    void triggerRandomEvent(); // losowe zdarenia co ture zeby nie bylo boring
public:
    Game();
    void run();
};

#endif 