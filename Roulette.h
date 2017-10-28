#ifndef ROULETTE_H
#define ROULETTE_H
#include <string>
#include <array>
#include <sstream>

using std::array; using std::string; using std::ostringstream;

class Number {
public:
    Number(int val=0) : value{val} {}
    bool isEven();
    bool isLow();
    std::string toString();    
private:
    int value;    
};


class Player {
public:
    Player(int ident=0, int budg=0) : id{ident}, budget{budg}, playing{true}, bet{0}, number{Number(0)}, moneyBet{0} {}
    bool takeFromBudget(int);
    void addToBudget(int);
    
    int getId(){return id;}
    int getBudget() {return budget;}
    
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
    std::string showPlayers();
    std::string showNumbers();
    
private:
    std::array<Player, nrP> players;
    std::array<Number, nrN> roulette;
};



#endif /* ROULETTE_H */

