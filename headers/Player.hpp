#ifndef DEMINEUR_H
#define DEMINEUR_H
#include <iostream>
#include <string>
using namespace std;

class Player
{
   protected :
   string name;
   unsigned short nbrV;
   unsigned short nbrdef;

    public:
     //si le Player est un visiteur, appel à un constructeur par défaut.
    Player();
    ~Player();
    //getters
   unsigned short getV();
   unsigned short getDef();
   string getName();
   //setters
   void setV(unsigned short);
   void setDef(unsigned short);
   void setName(string);


};


#endif
