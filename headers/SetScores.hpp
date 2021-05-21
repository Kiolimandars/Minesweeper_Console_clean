#include<iostream>
#include<fstream>
#include<vector>
#include <string>


void setScores(vector<Player> players){
    string line;
    ofstream scores("Scores.txt");
    for (int i=0; i<players.size(); i++){
        line=players[i].getName()+" " + to_string(players[i].getV()) + " " + to_string(players[i].getDef());
        scores<<line<<"\n";
    }


}
