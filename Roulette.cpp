#include "Roulette.h"

bool Number::isEven()
{
    return value % 2;
}

bool Number::isLow()
{
    return value < 19;
}

std::string Number::toString()
{
    ostringstream os;
    os << value;
    if (value == 0) return os.str();
    if(isEven()) os << " gerade "; 
    else os << " ungerade ";
    if(isLow()) os << "tief";
    else os << "hoch";
    return os.str();
}

bool Player::takeFromBudget(int val)
{
    if (budget >= val) {budget -= val; setMoneyBet(val);}
    return budget >= val;
}

void Player::addToBudget(int val)
{
    budget += val;
}

Roulette::Roulette(int budg)
{
    for(int i = 0; i < nrP; ++i)
        players.at(i) = Player(i+1, budg);
    for(int i = 0; i < nrN; ++i)
        roulette.at(i) = Number(i);
}

void Player::setBet(char c)
{
    bet = c;
}

void Player::setNumber(Number n)
{
    number = n;
}


void Roulette::makeBets()
{
    for(int i = 0; i < nrP; ++i)
    {
    players[i].setPlaying(players[i].takeFromBudget(100));

        switch(i)
        {
            case 0: players[i].setBet('g'); break;
            case 1: players[i].setBet('t'); break;
            case 2: players[i].setBet('z'); 
                    players[i].setNumber(Number(23));
                    break;
            case 3: players[i].setBet('z');
                    players[i].setNumber(Number(rand()%36 + 1));
                    break;

        }
    }
}

void Roulette::play()
{
    Number winningNumber = Number(rand() % 37);
    std::cout << winningNumber.toString() << "\n";
    for(int i = 0; i < nrP; ++i)
    {
        //std::cout << players[i].isPlaying() << "\n";
        if (players[i].isPlaying()){
            std::cout << players[i].getBet() << "\n";
        switch (players[i].getBet())
        {
            case 'u': if(!winningNumber.isEven()) {players[i].addToBudget(players[i].getMoneyBet()*2);}; break;
            case 'g': if(winningNumber.isEven()) {players[i].addToBudget(players[i].getMoneyBet()*2);}; break;
            case 't': if(winningNumber.isLow()) {players[i].addToBudget(players[i].getMoneyBet()*2);}; break;
            case 'h': if(!winningNumber.isLow()) {players[i].addToBudget(players[i].getMoneyBet()*2);}; break;
            case 'z': if(winningNumber == players[i].getNumber()) {players[i].addToBudget(players[i].getMoneyBet()*36);}; break;
        }
        
        }   
    }
    
    
    
}


std::string Roulette::showPlayers() 
{
    std::ostringstream os;
    for (int i = 0; i < nrP; ++i)
        os << "player " << players[i].getId() << " || budget: " << players[i].getBudget() << "\n";
    return os.str();
}