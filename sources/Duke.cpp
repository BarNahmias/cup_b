//
// Created by בר נחמיאס on 24/04/2022.
//

#include "Duke.hpp"
#include "Player.hpp"
#include "Game.hpp"

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

using namespace coup;
Duke::Duke(Game & game , const  string & player_name): Player(game, player_name,"Duke"){}

void Duke:: block(Player & player) {
    if(player.last_action=="foreign_aid"){
        player._coins-=2;
        this->last_action= "block";
    } else{
        throw out_of_range("Duke can't blocked ");
    }
//    cout << "block" << endl;
}
void Duke:: tax() {
    unsigned long turn=(unsigned long)this->_game->this_turn;
    if(this->_game->all_players[turn]!=this) {
        throw std::out_of_range("Wrong turn");}
    if(this->_game->pl_count<2){
        throw out_of_range("minimum 2 players");
    }
    this->_game->game_on=1;
    this->_coins+=3;
    _game->update();
//    cout << "tax" << endl;
}
