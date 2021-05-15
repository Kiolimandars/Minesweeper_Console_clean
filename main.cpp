#include <iostream>
#include "headers/demineurboard.hpp"
#include "headers/Player.hpp"
#include <windows.h>
#include<fstream>

using namespace std;
int main()
{
    DemineurBoard B;
    unsigned short i,j;
    char c;
    string name;
    HANDLE  hConsole;

    cout<<"Please enter your name: ";
    cin>>name;
    Player p(name);

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time_t(NULL));



    B.create();
    B.displayAll();
    cout<<"\t\t-------------------------------------------------------------------------------"<<endl;

    B.display();
    do{
        do {
            cout<<"what to do? ";
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
                cout<<"\n\n\t\t-------------------YOU FAILED!! ya bhim(a)------------------- \n\n"<<endl;
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
                SetConsoleTextAttribute(hConsole, 303);
                cout<<"\n\t\tVICTORY!";
                SetConsoleTextAttribute(hConsole, 271);

            }

            c='q';
        }
    }while(c!='q' );
return 0;
}

