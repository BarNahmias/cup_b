//
// Created by בר נחמיאס on 24/04/2022.
//
#include <algorithm>

#include "Ambassador.hpp"
#include "Captain.hpp"
#include <iostream>
using namespace std;
#include <string>
using namespace coup;
constexpr int zero=0;

Ambassador ::Ambassador(Game &_game,  const string &_player_name):
Player(_game,_player_name,"Ambassador") {}

void  Ambassador::transfer (Player &take,Player &get) {
    unsigned long turn=(unsigned long)this->_game->this_turn;
    if(this->_game->all_players[turn]!=this) {
        throw std::out_of_range("Wrong turn");}
    if(this->_game->pl_count<2){
        throw out_of_range("minimum 2 players");
    }
    this->_game->game_on=1;
    if(take._coins >zero){
        _game->update();
        get._coins++;
        take._coins--;
    } else { throw out_of_range("no many to take");}
}

void Ambassador::block(Player &player) {
    if(player.last_action=="steel"){
        Captain * temp_Captain =dynamic_cast<Captain*>(&player);
        if (temp_Captain->stolen!= nullptr){
            player._coins-=2;
            temp_Captain->stolen->_coins+=2;
            temp_Captain->stolen= nullptr;
            this->last_action="block";
        }
    }
    else {
            throw out_of_range("Ambassador can't blocked Captain ");
        }
    }

