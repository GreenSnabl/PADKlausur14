#include "Roulette.h"

bool Number::isEven()
{
    return value % 2;
}

bool Number::isLow()
{
    return value < 19;
}

string Number::toString()
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
        players[i] = Player(i, budg);
    for(int i = 0; i < nrN; ++i)
        roulette[i] = Number(i);
}

void Roulette::makeBets()
{
    for(int i = 0; i < nrP; ++i)
    {
        switch(i)
        {
            case 0: players[i].setBet('g');
            case 1: players[i].setBet('t');
            case 2: players[i].setBet('z'); players[i].setNumber(23);
            case 3: players[i].setBet('z'); players[i].setNumber(rand()%36 + 1);
            default: players[i].setPlaying(Player::takeFromBudget(100));
        }
    }
}

