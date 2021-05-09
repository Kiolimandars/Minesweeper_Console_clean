#include "headers/Tile.hpp"
#include <iostream>
using namespace std;
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
/*void Tile::visible()
{
    cout<< getNum()<< endl ;
}*/
bool Tile::isPlayed(){

    return played;
}
unsigned short Tile::getX()
{
    return posRow;
};
    unsigned short Tile::getY()
    {
        return posCol;
    };
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
