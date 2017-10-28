#include "Roulette.h"
#include <ctime>

int main() {
    
    std::srand(time(0));
    Roulette r1(1000);
    for(int i = 0; i < 1000; ++i)
    {
    r1.makeBets();
    std::cout << r1.showPlayers();
    r1.play();
    }
    
    return 0;
}

