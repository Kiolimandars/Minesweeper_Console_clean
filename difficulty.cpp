#include <iostream>
#include <string>
#include "headers/difficulty.hpp"

using namespace std;

void Difficulty::easy()
{
    wid = 8;
    len = 8;
    nbMine = 16; // nbMine= {(wid*len) / 4}
    time = 30;
}

void Difficulty::medium()
{
    wid = 15;
    len = 12;
    nbMine = 50;
    time = 60;
}

void Difficulty::hard()
{
    wid = 16;
    len = 16;
    nbMine = 56; // 15 a negocier
    time = 120;
}
int Difficulty::getWidth()
{
    return wid;
}

int Difficulty::getLength()
{
    return len;
}

unsigned short Difficulty::getMines()
{
    return nbMine;
}

unsigned short Difficulty::getTime()
{
    return time;
}

void Difficulty::setLevel()
{
    unsigned short choix;
    cout << "Tapez :" << endl;
    cout << "1) Niveau easy" << endl;
    cout << "2) Niveau medium" << endl;
    cout << "3) Niveau hard" << endl;
    cin >> choix;
    switch (choix)
    {
    case 1:
    {
        easy();
        break;
    }
    case 2:
    {
        medium();
        break;
    }
    case 3:
    {
        hard();
        break;
    }
    default:
        cout << "try again" << endl;
    }
};
