#include "Roulette.h"
#include <iostream>
int main() {
    
    Roulette r1(1000);
    r1.makeBets();
    std::cout << r1.showPlayers();

    return 0;
}

