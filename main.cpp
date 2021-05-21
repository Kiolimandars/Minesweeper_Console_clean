#include <iostream>
#include "headers/demineurboard.hpp"
#include "headers/Player.hpp"
#include "headers/vectorPlayers.hpp"
#include "headers/setScores.hpp"
#include <windows.h>
#include<fstream>
#include <vector>

using namespace std;

int main()
{
    DemineurBoard B;
    Player p;
    unsigned short i,j;
    char c;
    string name;
    vector<Player> vPlayers;
    HANDLE  hConsole;

    cout<<"Please enter your name: ";
    cin>>name;

    vectorPlayers(&vPlayers);

        int y=0;
        bool e= false;
        while(y<vPlayers.size() && !e){
            if (vPlayers[y].getName()==name){
                p.setName(vPlayers[y].getName());
                p.setDef(vPlayers[y].getDef());
                p.setV(vPlayers[y].getV());
                vPlayers.erase(vPlayers.begin()+y);
                e=true;
            }

            y++;
        }
        if(!e){
            p.setName(name);
            }



    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time_t(NULL));



    B.create();
    //B.displayAll();
    //cout<<"\t\t-------------------------------------------------------------------------------"<<endl;

    B.display();
    cout<<"\nPlayer: "<<p.getName();
    SetConsoleTextAttribute(hConsole, 303);
    cout<<" Victories: "<<p.getV();
    SetConsoleTextAttribute(hConsole, 207);
    cout<<" Defeats: "<<p.getDef()<<endl;
    SetConsoleTextAttribute(hConsole, 271);
    do{
        do {
            cout<<"what to do? p: play - f: flag - m: question mark: ";
            cin>>c;
            }while(c!='p' && c!='m' && c!='f' && c!='q' );
        cout<<"Choose a tile to play: "<<endl;
            do {
                cout<<"Row:  ";
                cin>>i;
                }while(i<0 || i>=B.getLength());
            do {
                cout<<"Column:  ";
                cin>>j;}while(j<0 || j>=B.getWidth());

        if(c=='p'){

            if (B[i][j].isBomb()){
                system("cls");

                SetConsoleTextAttribute(hConsole, 207);
                cout<<"\n\n\t\t-------------------YOU FAILED!! try again ------------------- \n\n"<<endl;
                p.setDef(p.getDef()+1);
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"\t\t\t\t\tYou played: ("<<i<<","<<j<<")"<<endl<<endl<<endl;;


                B.displayAll();
                break;
            }
            else{
                    if (B[i][j].getNum()==0){
                        B.uncoverTile(i,j);

                    }
                    else
                        B[i][j].setPlayed();
                }
        }
        if(c=='f'){
            if (!B[i][j].isFlagged()){
                    B[i][j].setFlag();
                    B.setFlags(1);
            }
            else{
                B[i][j].setFree();
                B.setFlags(-1);
            }
        }
        if (c=='m')
            B[i][j].setQuestion();

        //system("cls");
        B.display();
        if (B.minesLeft()==0){
            if(B.checkVectory()){
                cout<<"\n\t\t";
                SetConsoleTextAttribute(hConsole, 303);
                cout<<"VICTORY!";
                SetConsoleTextAttribute(hConsole, 271);
                p.setV(p.getV()+1);

            }

            c='q';
        }
    }while(c!='q' );

        vPlayers.push_back(p);
        setScores(vPlayers);
return 0;
}