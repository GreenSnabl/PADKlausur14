#ifndef ROULETTE_H
#define ROULETTE_H
#include <string>
#include <array>

class Number {
public:
    Number(int);
    bool isEven();
    bool isLow();
    std::string toString();    
private:
    int value;    
};


class Player {
public:
    Player(int, int);
    bool takeFromBudget(int);
    void addToBudget(int);
    
private:    
    int id;
    char bet;
    Number number;
    int budget;
    int moneyBet;
    bool playing;
};

class Roulette {
public:
    const static int nrP = 4;
    const static int nrN = 37;
    Roulette(int);
    void makeBets();
    void play();
    void sort();
    std::string showPlayers();
    std::string showNumbers();
    
private:
    std::array<Player, nrP> players;
    std::array<Number, nrN> roulette;
    
};



#endif /* ROULETTE_H */

