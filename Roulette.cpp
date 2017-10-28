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
    if (budget >= val) budget -= val;
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
    if(bet == 'g' || bet == 'u' || bet == 'h' || bet == 't' || bet == 'z')
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
        switch(i)
        {
            case 0: 
                players[i].setBet('g');
            case 1: 
                players[i].setBet('t');
            case 2: 
                players[i].setBet('z'); 
                players[i].setNumber(Number(23));
            case 3: 
                players[i].setBet('z'); 
                players[i].setNumber(Number(rand()%36 + 1));
            default: 
                players[i].setPlaying(players[i].takeFromBudget(100));
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