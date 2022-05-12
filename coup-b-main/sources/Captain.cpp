//
// Created by בר נחמיאס on 24/04/2022.
//

#include "Captain.hpp"

#include <algorithm>
using namespace coup;
constexpr int two=2;
constexpr int one=1;

Captain::Captain(Game &game, const string &player_name) : Player(game,player_name,"Captain"){
    this->stolen= nullptr;
    this->captain= nullptr;
}
void Captain::  steal (Player & player) {
    unsigned long turn=(unsigned long)this->_game->this_turn;
    if(this->_game->all_players[turn]!=this) {
        throw std::out_of_range("Wrong turn");}
    if(this->_game->pl_count<2){
        throw out_of_range("minimum 2 players");
    }
    this->_game->game_on=1;
    this->_game->update();
    this->last_action="steel";
    this->stolen=&player;

    if(player._coins>=two){
        this->_coins+=2;
        player._coins-=2;
    }
    if(player._coins==one){
        this->_coins+=1;
        player._coins-=1;
    }
//    cout << "steal" << endl;
}
void Captain:: block(Player & player){
    if(player.last_action=="steal" ){

        Captain * temp_Captain =dynamic_cast<Captain*>(&player);
        if (temp_Captain->stolen!= nullptr){
        player._coins-=2;
        temp_Captain->stolen->_coins+=2;
        temp_Captain->stolen= nullptr;
        this->last_action="block";}
    } else{throw out_of_range("can't blocked ");}
}

