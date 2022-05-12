//
// Created by בר נחמיאס on 24/04/2022.
//

#include "Player.hpp"
#include "Assassin.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <sstream>

using namespace std;

constexpr int cash_to_coup=7;
constexpr int Assassin_cash_to_coup=3;
constexpr int min_players=2;
constexpr int max_players=6;
constexpr int must_coup=10;
using namespace coup;

Player :: Player(Game & game, const string  & player_name ,const string & role) {
    int start=game.game_on;
    if (game.pl_count<max_players && start==0){
        this->_game=&game;
        this->_player_name=player_name;
        this->_role=role;
        this->_coins=0;
        this->status=1;
        this->last_action="";
        this->_game->all_players.push_back(& *this);
        this->_game->pl_count++;
    }
    else{
        throw out_of_range("game full");}

}

void Player :: do_coup() const{
    if(this->_coins>=must_coup){
        throw out_of_range("you have money do coup!");
    }
}

void Player :: income(){

    unsigned long turn=(unsigned long)this->_game->this_turn;
    if(this->_game->all_players.at(turn)!=this) {
        throw std::out_of_range("Wrong turn");
    }
    if(this->_game->pl_count<2){
        throw out_of_range("minimum 2 players");
    }
    this->_game->game_on=1;

    if(this->_coins>=must_coup){
        throw out_of_range("you have money do coup!"); }
    this->_coins++;

    this->_game->income--;
    this->_game->update();
    this->last_action="income";
}

void Player ::  foreign_aid(){
    unsigned long turn=(unsigned long)this->_game->this_turn;
    if(this->_game->all_players[turn]!=this) {
        throw std::out_of_range("Wrong turn");
    }
    if(this->_game->pl_count<2){
        throw out_of_range("minimum 2 players");
    }
    this->_game->game_on=1;

    if(this->_coins>=must_coup){
        throw out_of_range("you have money do coup!");}

        this->_coins+=2;
    this->_game->income-=2;
    this->_game->update();
    this->last_action="foreign_aid";
}



void Player :: coup(Player & player){

    unsigned long turn=(unsigned long)this->_game->this_turn;
    if(this->_game->all_players[turn]!=this) {
        throw std::out_of_range("Wrong turn");}

    if(this->_game->pl_count<2){
        throw out_of_range("minimum 2 players");
    }
    this->_game->game_on=1;

    if (player.status==0){
        throw out_of_range("coup this player");
    }

    if(this->_coins>=cash_to_coup){
        this->_game->remove_player(player);
        this->_game->update();
        this->_coins-=cash_to_coup;
        this->last_action="coup";
        return;}

    if(!(this->_role!="Assassin"|| (this->_coins<Assassin_cash_to_coup|| this->_coins>=cash_to_coup))){

        Assassin * temp_Assassin = dynamic_cast<Assassin*>(this);
        temp_Assassin->remove_this_player=&player;
        for (unsigned int i = 0; i <this->_game->pl_count ; ++i) {
        if(this->_game->all_players.at(i)==&player)    {
            temp_Assassin->remove_index=i;
        }
        }

        this->_game->remove_player(player);
        this->_game->update();
        this->_coins-=Assassin_cash_to_coup;
        this->last_action="coup";
        return;
    }
    throw out_of_range("coup this player");
}


string Player ::  role() {  return this->_role;}

int Player :: coins()  const {return this->_coins;}

