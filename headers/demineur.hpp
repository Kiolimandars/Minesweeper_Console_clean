#ifndef Demineur_H
#define Demineur_H
#include "Timer.hpp"
#include <iostream>
#include "DemineurBoard.hpp"
using namespace std;
class Demineur : public DemineurBoard, public Timer
{
    int totalmoves;
    int mineRest;
public:
    Demineur();
    ~Demineur();
    string timeLeft(); // Returns the time left
    void endTheGame(); //
    void begin(); // Start the Timer
    bool move(); // Clicking a case
    bool hasEnded(); // End of game conditions
    unsigned short nbrMoves(unsigned short); // Tracks how many clicks
    int getMineRest();
};
#endif