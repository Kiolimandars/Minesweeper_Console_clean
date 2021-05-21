#ifndef DEMINEURBOARD_H
#define DEMINEURBOARD_H

#include <iostream>
#include <vector>
#include "Difficulty.hpp"
#include "Tile.hpp"
#include <utility>
#include <string>
using namespace std;




class DemineurBoard: public Difficulty, public Tile
{

    unsigned short flags,nbPlayed;
    Tile Board[20][20];

public:
    DemineurBoard();   // Constructor
    ~DemineurBoard();  // Destructor
    void create();     // Create the board
    void display();     // displays the board for the user
    void displayAll();    // Displays the Board for testing purposes
    void setMines();   // Set mines in place
    void setNumbers(); // Set number for each tile
    void setNum(Tile*);
    void setFlags(short);
    void addNbPlayed();
    void Ines(Tile*);
    void uncoverTile(int,int);
    Tile* operator [](int);
    unsigned short minesLeft();
    unsigned short getNbPlayed();
    bool checkVectory();
};

#endif
