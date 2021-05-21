#include "Player.hpp"
#include "vector"
#include <string>
#include <fstream>

void vectorPlayers(vector<Player>* res){
    string line,name,def,vict;

    ifstream players("Scores.txt");
    if(players.is_open()){

        while (getline(players,line)){
                Player p;
                name=line.substr(0,line.find(" "));
                vict=line.substr(line.find(" ")+1,1);
                def=line.substr(line.find(" ")+3,1);
                p.setName(name);
                p.setDef(stoi(def));
                p.setV(stoi(vict));
                (*res).push_back(p);

            }
        players.close();
    }
    else{
        cout<<"Couldnt open file"<<endl;
    }

}
