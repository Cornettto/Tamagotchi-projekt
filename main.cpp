#include "Game.h"
#include <cstdlib>
#include <ctime>
int main(){
    //zeby rand() losowal za kazdym razem inne rzeczy
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // to na losowe zdarzenaia miedzy turami


    Game tamagotchi;
    tamagotchi.run();
    return 0;
} 