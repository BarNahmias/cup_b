//
// Created by בר נחמיאס on 24/04/2022.
//

#include "Contessa.hpp"
#include "Assassin.hpp"

using namespace coup;


using namespace std;

using namespace coup;
Contessa::Contessa(Game &_game, const string &_player_name) : Player(_game,_player_name,"Contessa"){}
void Contessa:: block(Player & player) {
    if(player._role=="Assassin"){
    Assassin* temp_Assassin = dynamic_cast<Assassin*>(&player);
    if(temp_Assassin->remove_this_player!= nullptr){
    _game->return_player(*temp_Assassin->remove_this_player,temp_Assassin->remove_index);
    temp_Assassin->remove_this_player= nullptr;}
    else{throw out_of_range("Contessa can't blocked ");}
    }
    else{throw out_of_range("Contessa can't blocked ");}

//    cout << "block" << endl;
}

