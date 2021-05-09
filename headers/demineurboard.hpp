#ifndef DEMINEURBOARD_H
#define DEMINEURBOARD_H
#include <iostream>
#include <stack>
#include <tuple>
#include <list>
#include <iterator>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Tile.hpp"
#include "difficulty.hpp"
using namespace std;




class DemineurBoard: public Difficulty, public Tile
{

    unsigned short flags;
    Tile Board[20][20];

public:
    DemineurBoard();   // Constructor
    ~DemineurBoard();  // Destructor
    void create();     // Create the board
    void affiche();     
    void affichei();    // Displays the Board for testing purposes
    void setMines();   // Set mines in place
    void setNumbers(); // Set number for each tile
    void setNum(Tile*);
    
    void uncoverZeros(short,short);
    Tile* operator [](int);
    unsigned short minesLeft();
};

DemineurBoard::DemineurBoard()
{
        Board[0][0]= Tile();
        flags = 0;
}
DemineurBoard::~DemineurBoard() {}
void DemineurBoard::create()
{

    Difficulty::setLevel();
    len = Difficulty::getLength();
    wid = Difficulty::getWidth();

    for (unsigned short i = 0; i < len; i++)
    {
        for (unsigned short j = 0; j < wid; j++)
        {
            Board[i][j] = Tile(i, j);
        }
    }

        setMines();
        for (unsigned short i = 0; i < len; i++)
        {
            for (unsigned short j = 0; j < wid; j++)
            {
                //cout<<"I am in Tile: ("<<i<<','<<j<<')'<<endl;
                if (!Board[i][j].isBomb())
                    setNum(&(Board[i][j]));
            }
        }

};
void DemineurBoard::affiche()
{

    for (unsigned short i = 0; i < Difficulty::getLength(); i++){

        for (unsigned short j = 0; j < Difficulty::getWidth(); j++)
    {
            if(Board[i][j].isPlayed()){

            cout << Board[i][j].getNum() << " | ";
            }
            else{
                cout << Board[i][j].getStatus() << " | ";
            }

    }
    cout<<'\n';
    }
};
//a effacer
void DemineurBoard::affichei()
{

    for (unsigned short i = 0; i < Difficulty::getLength(); i++){

        for (unsigned short j = 0; j < Difficulty::getWidth(); j++)
    {


            cout << Board[i][j].getNum() << " | ";


    }
    cout<<'\n';
    }
};

void DemineurBoard::setMines()
{
    unsigned short i,k,j,len,wid;

    len = Difficulty::getLength();
    wid = Difficulty::getWidth();
    unsigned short x = Difficulty::getMines();
    //cout<<"this is x: "<<x<<endl;
    while(k<x) //2
    {
//        srand(time(0));
//        rand();
        i = rand() % len ;
        j = rand() % wid ;

        //cout<<"i= "<<i<<" j= "<<j<<endl;
        if(!Board[i][j].isBomb()){
            Board[i][j].setBomb();
            k++;
        }

    }
}

unsigned short DemineurBoard::minesLeft() // 7at flag 3ala wa7da fiha mine
{
    return Difficulty::getMines() - flags;
}



/*void DemineurBoard::Ines(Tile* current) // a utiliser si la case cliqué n est pas une bombe
{

    coupleList l;
    int i=0;
    stack<Tile*> pile;
    Tile curTile;       // Holds the neighbouring tile
    Tile* ptrTile;
    pile.push(current); // Initiate the stack with the clicked tile

    while (!pile.empty()|| i<10)
    {
        curTile= *(pile.top());
        pile.pop();
        cout<<"While starts here"<<endl;
        l=curTile.neighbours(); // Returns the list of neighbours' coordinates

            for (coupleList::iterator it = l.begin(); it != l.end(); ++it)
            {
                cout<<"for starts here"<<endl;
                if ((*it).first < Difficulty::getLength() && (*it).second < Difficulty::getWidth()){

                        cout<<"If valid tile starts here: "<<Board[(*it).first][(*it).second].getNum()<<endl;
                   if(Board[(*it).first][(*it).second].getNum()==0){

                    cout<<"Tile has been pushed"<<endl;
                    ptrTile=&(Board[(*it).first][(*it).second]);
                    pile.push(ptrTile);
                    (*ptrTile).setPlayed();
                }
                else{
                    if (!(Board[(*it).first][(*it).second].isBomb()))
                       (*ptrTile).isPlayed();
                }

            }
         }
         i++;
      //  pile.top().setPlayed();  Playing the current tile

        /*if ((*(pile.top())).getNum() == 0)
        {
            //ta3mel chay, bech to93ed fi west l pile bech tempili l voisins
            (*(pile.top())).setPlayed();
        }
        else
        {
            (*(pile.top())).setPlayed();
            pile.pop();
            //Board[i][j].visible();
        }
    }
}*/
/*void DemineurBoard::Ines(Tile* current)
{
    coupleList l;
    stack<Tile*> pile;
    Tile* ptrTile;
    Tile curTile;       // Holds the neighbouring tile
    pile.push(current); // Initiate the stack with the clicked tile
    while (!pile.empty())
    {
        ptrTile=pile.top();
        l = (*ptrTile).neighbours(); // Returns the list of neighbours' coordinates
        (*(pile.top())).setPlayed();      // Playing the current tile
        //cout<<"I ve been set played"<<endl;
        pile.pop();
        cout<<" i ve been popped"<<endl;

        for (coupleList::iterator it = l.begin(); it != l.end(); ++it)
        { // Loop through the list
            if ((*it).first < Difficulty::getLength() && (*it).second < Difficulty::getWidth())
            { // Check if the tile is valid
                curTile = Board[(*it).first][(*it).second];
                cout<<"tile is: "<<curTile.getNum()<<endl;
                if (curTile.getNum() == 0)
                {

                    cout<<"It is 0 "<<endl;
                    curTile.setPlayed();
                    pile.push(&(Board[(*it).first][(*it).second]));
                } // If it is empty or bomb it is pushed in the stack
                else if(!curTile.isBomb())
                {
                    cout<<"Board["<<(*it).first<<"]["<<(*it).second)<<"]= "<<curTile.getNum()<<endl;

                    Board[(*it).first][(*it).second].setPlayed(); // If it is a number, it is displayed
                }
            }
        }
    }
}*/
/*---------------------------------------------------------------------------------------------------------*/
void DemineurBoard::uncoverZeros(short i, short j)
{
	if (!Board[i][j].isPlayed())
	{
	    Board[i][j].setPlayed();
	    if (Board[i][j].getNum() == 0)
                {
                if (i > 0)
                {
                    uncoverZeros( i - 1, j);
                }
                if (i > 0 && j > 0)
                {
                    uncoverZeros( i - 1, j - 1);
                }
                if (j > 0)
                {
                    uncoverZeros( i, j - 1);
                }
                if (j > 0 && i < Difficulty::getLength() - 1)
                {
                    uncoverZeros( i + 1, j - 1);
                }
                if (i < Difficulty::getLength() - 1)
                {
                    uncoverZeros( i + 1, j);
                }
                if (i > Difficulty::getLength() - 1 && j < Difficulty::getWidth() - 1)
                {
                    uncoverZeros(i + 1, j + 1);
                }
                if (j < Difficulty::getWidth() - 1)
                {
                    uncoverZeros( i, j + 1);
                }
                if (i > 0 && j < Difficulty::getWidth() - 1)
                {
                    uncoverZeros(i - 1, j + 1);
                }

		}
	}
}
/*---------------------------------------------------------------------------------------------------------*/
void DemineurBoard::setNum(Tile* current)
{
    unsigned short res = 0;
    fflush(stdin);
    coupleList l;
    l = (*current).neighbours();
    for (coupleList::iterator it = l.begin(); it != l.end(); ++it)
    {
        if ((*it).first < Difficulty::getLength() && (*it).second < Difficulty::getWidth())
        {
            if (Board[(*it).first][(*it).second].isBomb())
            {
                res++;   
            }
        }
    }
    (*current).setnum(res);
}

Tile* DemineurBoard::operator [](int i){
    return Board[i];

}

#endif
