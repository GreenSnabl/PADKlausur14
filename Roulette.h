#ifndef ROULETTE_H
#define ROULETTE_H
#include <string>
#include <array>
#include <sstream>

using std::array; using std::string; using std::ostringstream;

class Number {
public:
    Number(int val) : value{val} {}
    bool isEven();
    bool isLow();
    string toString();    
private:
    int value;    
};


class Player {
public:
    Player(int ident, int budg) : id(ident), budget(budg), playing(true) {}
    bool takeFromBudget(int);
    void addToBudget(int);
    
    char getBet(){return bet;}
    void setBet(char);
    
    Number getNumber(){return number;}
    void setNumber(Number);
    
    int getMoneyBet(){return moneyBet;}
    void setMoneyBet(int);
    
    bool isPlaying(){return playing;}
    void setPlaying(bool pl) {playing = pl;}
    
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
    string showPlayers();
    string showNumbers();
    
private:
    array<Player, nrP> players;
    array<Number, nrN> roulette;
    
};



#endif /* ROULETTE_H */

