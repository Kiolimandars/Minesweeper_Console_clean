#include <iostream>
#include "headers/demineurboard.hpp"


using namespace std;
int main()
{
    DemineurBoard B;
    int i,j;
    char c;

    B.create();
    B.affichei();
    cout<<"-------------------------------------------------------------------------------"<<endl;
    B.affiche();
    do{
        cout<<"what to do? ";
            cin>>c;
        cout<<"Choose a tile to play: "<<endl;
            cin>>i;
            cin>>j;
        if(c=='p'){

            if (B[i][j].isBomb()){

                cout<<"YOU FAILED!! ya bhim(a) "<<endl;}

            else{
                    if (B[i][j].getNum()==0){
                        B.decouvrir_carre(i,j);

                    }
                    else
                        B[i][j].setPlayed();
                }
        }
        if(c=='f')
            B[i][j].setFlag();
        if (c=='m')
            B[i][j].setQuestion();
        B.affiche();

    }while(c!='q');
return 0;
}
