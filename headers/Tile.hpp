#ifndef TILE_H
#define TILE_H
#include <iostream>
#include <utility>
#include <list>

using namespace std;

typedef list<pair<unsigned short, unsigned short>> coupleList;


class Tile
{

    unsigned short posRow;
    unsigned short posCol;
    unsigned short num; //Number that will be displayed if tile is played
    bool played;
    char status; // 'e'=empty, 'f'=flagged, 'q'= question mark

    public:
    Tile();
    Tile(unsigned short , unsigned short); // Constructor
    //~Tile(); // Destructor
    bool isBomb(); // Returns true if num==9
    bool isFlagged(); // Checks if tile is flagged
    bool isQuestion(); // Checks if tile has a question mark
    bool isPlayed(); // Checks if tile is opened
    bool isFree();
    unsigned short getNum();
    char getStatus();
    coupleList neighbours();

    //setters
    void setnum(unsigned short);
    void setPlayed();// Change the played attribute when left clicked
    void setBomb();// Makes the tile a bomb


    // The following methods will be used in case of event

    void setFlag();// Sets a flag on tile when right clicked (empty)
    void setQuestion();// Sets a question mark on tile when right clicked (flagged)
    void setFree();// Sets the tile empty when right clicked (question marked)

};



 Tile::Tile(){
    posRow=0;
    posCol=0;
    num=0;
    played=false;
    status='e';
}
 Tile::Tile(unsigned short x, unsigned short y)
{
    posRow=x;
    posCol=y;
    num=0;
    played=false;
    status='e';
}

bool Tile::isPlayed(){

    return played;
}

bool Tile::isBomb(){
    if(num==9)
    {return true;}

    return false;
}

bool Tile::isFlagged(){
    if(status=='f'){return true;}

    return false;
}

bool Tile::isQuestion(){
    if(status=='q'){return true;}

    return false;
}

bool Tile::isFree(){
return (status=='e');
}

unsigned short Tile::getNum(){
    return num;
    }

void Tile::setPlayed(){ played=true;}
void Tile::setBomb(){ num=9;}
void Tile::setFlag(){ status='f';}
void Tile::setQuestion(){ status='q';}
void Tile::setFree(){ status='e';}
void Tile::setnum(unsigned short x)
{
    num=x;
};
char Tile::getStatus()
{
    return status;
}
coupleList Tile::neighbours(){
    coupleList res;
    int i,j;
    //cout<<"I am in Tile: ("<<posRow<<','<<posCol<<')'<<endl;
    for (i=-1;i<2;i++){
        for (j=-1;j<2;j++){
            if((i!=0) || (j!=0) )
            {
                res.push_back({posRow+i,posCol+j});
                //cout<<'{'<<posRow+i<<','<<posCol+j<<'}'<<endl;
            }
        }
    }

    return res;
}

#endif
