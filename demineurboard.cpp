#include "headers/DemineurBoard.hpp"
//#include "headers/Difficulty.hpp"
//#include "headers/Tile.hpp"
#include <iostream>
#include <stack>
#include <tuple>
#include <list>
#include <iterator>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <windows.h>
using namespace std;

DemineurBoard::DemineurBoard()
{
        Board[0][0]= Tile();
        flags = 0;
}
DemineurBoard::~DemineurBoard() {}
void DemineurBoard::create()
{
    srand(time_t(NULL));
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
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<"\t\t   ";
    SetConsoleTextAttribute(hConsole, 15);
    for (unsigned short j = 0; j < Difficulty::getWidth(); j++){
        cout<<setw(2)<<j<<"  ";
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout<<endl;
    for (unsigned short i = 0; i < Difficulty::getLength(); i++){
        cout<<"\t\t";
        cout<<setw(2)<<i<<" ";
        for (unsigned short j = 0; j < Difficulty::getWidth(); j++)
    {
            if(Board[i][j].isPlayed()){
                switch(Board[i][j].getNum()){
                    case 0: SetConsoleTextAttribute(hConsole, 136);break;
                    case 1: SetConsoleTextAttribute(hConsole, 129);break;
                    case 2: SetConsoleTextAttribute(hConsole, 138);break;
                    case 3: SetConsoleTextAttribute(hConsole, 130);break;
                    case 4: SetConsoleTextAttribute(hConsole, 142);break;
                    case 5: SetConsoleTextAttribute(hConsole, 139);break;
                    case 6: SetConsoleTextAttribute(hConsole, 134);break;
                    case 7: SetConsoleTextAttribute(hConsole, 140);break;
                    case 8: SetConsoleTextAttribute(hConsole, 143);break;

                }

                cout <<" "<< Board[i][j].getNum() << " ";
                SetConsoleTextAttribute(hConsole, 15);
                cout<<'|';
            }
            else{
                switch(Board[i][j].getStatus()){
                    case 'e': SetConsoleTextAttribute(hConsole, 127);break;
                    case 'f': SetConsoleTextAttribute(hConsole, 124);break;
                    case 'q': SetConsoleTextAttribute(hConsole, 121);break;

                }

                cout <<" "<<Board[i][j].getStatus() << " ";
                SetConsoleTextAttribute(hConsole, 15);
                cout<<'|';
            }

    }
    cout<<'\n';
    }
};
//a effacer
void DemineurBoard::affichei()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<"\t\t   ";
    SetConsoleTextAttribute(hConsole, 15);
    for (unsigned short j = 0; j < Difficulty::getWidth(); j++){
        cout<<setw(2)<<j<<"  ";
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout<<endl;
    for (unsigned short i = 0; i < Difficulty::getLength(); i++){
            cout<<"\t\t"<<setw(2)<<i<<" ";
        for (unsigned short j = 0; j < Difficulty::getWidth(); j++)
    {
        switch(Board[i][j].getNum()){
                    case 0: SetConsoleTextAttribute(hConsole, 128);break;
                    case 1: SetConsoleTextAttribute(hConsole, 129);break;
                    case 2: SetConsoleTextAttribute(hConsole, 138);break;
                    case 3: SetConsoleTextAttribute(hConsole, 130);break;
                    case 4: SetConsoleTextAttribute(hConsole, 142);break;
                    case 5: SetConsoleTextAttribute(hConsole, 139);break;
                    case 6: SetConsoleTextAttribute(hConsole, 134);break;
                    case 7: SetConsoleTextAttribute(hConsole, 140);break;
                    case 8: SetConsoleTextAttribute(hConsole, 143);break;
                    case 9: SetConsoleTextAttribute(hConsole, 192);break;

                }


            cout <<" "<< Board[i][j].getNum() << " ";
                SetConsoleTextAttribute(hConsole, 15);
                cout<<'|';


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

    while(k<x) //2
    {


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

/*tuple_list DemineurBoard::neighbours(int i, int j)
{
    tuple_list tl;
    for (int x = -1; x < 2; x++)
    {
        for (int y = -1; y < 2; y++)
        {
            if (i + x <= getLength() && i + x > 0 && y + j <= getWidth() && y + j > 0)
            {
                tl.push_back(tuple<int, int>{i + x, j + y});
            }
        }
    }
};*/

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
void DemineurBoard::decouvrir_carre(int i, int j)
{
	if (!Board[i][j].isPlayed())
	{
	    Board[i][j].setPlayed();
	    if (Board[i][j].getNum() == 0)
                {
                if (i > 0)
                {
                    decouvrir_carre( i - 1, j);
                }
                if (i > 0 && j > 0)
                {
                    decouvrir_carre( i - 1, j - 1);
                }
                if (j > 0)
                {
                    decouvrir_carre( i, j - 1);
                }
                if (j > 0 && i < Difficulty::getLength() - 1)
                {
                    decouvrir_carre( i + 1, j - 1);
                }
                if (i < Difficulty::getLength() - 1)
                {
                    decouvrir_carre( i + 1, j);
                }
                if (i > Difficulty::getLength() - 1 && j < Difficulty::getWidth() - 1)
                {
                    decouvrir_carre(i + 1, j + 1);
                }
                if (j < Difficulty::getWidth() - 1)
                {
                    decouvrir_carre( i, j + 1);
                }
                if (i > 0 && j < Difficulty::getWidth() - 1)
                {
                    decouvrir_carre(i - 1, j + 1);
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
    //cout<<"longueur: "<<l.size()<<endl;
    for (coupleList::iterator it = l.begin(); it != l.end(); ++it)
    {
        //cout<<"for{"<<(*it).first<<','<<(*it).second<<"}"<<endl;
        if ((*it).first < Difficulty::getLength() && (*it).second < Difficulty::getWidth())
        {
            //cout<<"if1:{"<<(*it).first<<','<<(*it).second<<'}'<<endl;
            if (Board[(*it).first][(*it).second].isBomb())
            {
                //cout<<"if2:{"<<(*it).first<<','<<(*it).second<<'}'<<endl;
                res++;
                //cout<<"res: "<<res<<endl;
            }
        }
    }
    (*current).setnum(res);
}

Tile* DemineurBoard::operator [](int i){
    return Board[i];

}

