#include <iostream>
#include "headers/demineurboard.hpp"
#include <windows.h>

using namespace std;
int main()
{
    DemineurBoard B;
    int i,j;
    char c;
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    srand(time_t(NULL));
    B.create();
    B.affichei();
    cout<<"-------------------------------------------------------------------------------"<<endl;

    B.affiche();
    do{
        do {
            cout<<"what to do? ";
            cin>>c;}while(c!='p' && c!='m' && c!='f' && c!='q' );
        cout<<"Choose a tile to play: "<<endl;
            do {
                cout<<"Row:  ";
                cin>>i;}while(i<0 || i>=B.getLength());
            do {
                cout<<"\nColumn:  ";
                cin>>j;}while(j<0 || j>=B.getWidth());

        if(c=='p'){

            if (B[i][j].isBomb()){
                system("cls");

                SetConsoleTextAttribute(hConsole, 207);
                cout<<"\n\n-----------------YOU FAILED!! ya bhim(a)------------------- \n\n"<<endl;
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"\t\tYou played: ("<<i<<","<<j<<")"<<endl<<endl<<endl;;


                B.affichei();
                break;
            }
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
/*#include <iostream>
#include <windows.h>   // WinApi header

using namespace std;    // std::cout, std::cin

int main()
{
  HANDLE  hConsole;
	int k;

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  // you can loop k higher to see more color choices
  for(k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(hConsole, k);
    cout << k << " I want to be nice today!" << endl;
  }

  cin.get(); // wait
  return 0;
}*/
