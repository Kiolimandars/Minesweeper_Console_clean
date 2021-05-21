#include <iostream>
#include <string>
#include "headers/Player.hpp"
#include "headers/Tile.hpp"

using namespace std;

Player::Player ()

{
    nbrdef = 0;
    nbrV = 0;
    name= "";


}

Player::~Player() {}

void Player::setV(unsigned short n)
{
        nbrV=n;
}
void Player::setDef(unsigned short n)
{
        nbrdef=n;
}

unsigned short Player::getV()
{
    return nbrV;
}

unsigned short Player::getDef()
{
    return nbrdef;
}

string Player::getName(){
    return name;
    }
void Player::setName(string Name){
    name=Name;
}

