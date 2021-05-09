#include "headers/Demineur.hpp"
#include <iostream>
#include <string>
#include "time.h"
using namespace std;

Demineur::Demineur()
{
    totalmoves = 0;
}
Demineur::~Demineur()
{
}
string timeLeft()
{
    string time;
    time = DemineurBoard::getTime();
    return time;
}
void Demineur::endTheGame()
{
    //popup ll the game is over
};

void Demineur::Begin() //compteur yebda ye7seb l wa9t
{
    Timer timer = Timer::Instance();
    bool isRunning = true;
    while (isRunning)
    {
        return (Timer::calcul());
    }
    if (hasEnded)
    isRunning= false
}


bool Demineur::move()
{
    Tile Board[DemineurBoard::getLength()][DemineurBoard::getWidth()];
    int i;
    int j;
    cout << "Ligne : ";
    cin >> i;
    cout << "Colonne : ";
    cin >> j;
    if (Board[i][j].isPlayed())
    return false;
    else
    return true;
}


bool Demineur::hasEnded() //les mines lkol trouvés
{
    if (getMineRest() == 0 || Timer::DureeTime() == 0)
        return true;
    else
        return false;
}
unsigned short Demineur::nbrMoves(unsigned short M = 0)
{
    while (!hasEnded)
    {
        if (move)
        {
            M++;
            cout << M;
        }
    }
}

