#include <iostream>
#include <string>
#include "headers/Player.hpp"
#include "headers/Tile.hpp"

using namespace std;

Player::Player (string Name)

{
    nbrdef = 0;
    nbrV = 0;
    name= Name;

   cout << "le constructeur est";

}

Player::~Player() {}

void Player::setV() // the game is over
{
        nbrV++;
}
void Player::setDef()
{
        nbrdef++;
}

unsigned short Player::getV()
{
    return nbrV;
}

unsigned short Player::getDef()
{
    return nbrdef;
}


