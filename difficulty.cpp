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
    wid = 12;
    len = 12;
    nbMine = 30;
    time = 60;
}

void Difficulty::hard()
{
    wid = 18;
    len = 18;
    nbMine = 181; // 15 a negocier
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
    char choix;
    unsigned short ichoix;
    do{
        cout << "Choose a level:" << endl;
        cout << "1) Easy" << endl;
        cout << "2) Medium" << endl;
        cout << "3) Hard" << endl;
        cin >> choix;
        ichoix=(unsigned short) choix - 48;
    }while (ichoix<1 || ichoix>3);

    switch (ichoix)
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

    }
};
