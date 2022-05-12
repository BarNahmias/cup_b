//
// Created by בר נחמיאס on 24/04/2022.
//

#include "Player.hpp"

constexpr int min_players=2;
constexpr int max_players=6;
using namespace coup;
constexpr int INT_MAX=2147483647;


#include "Game.hpp"

Game ::Game() {
    this->this_turn=0;
    this->pl_count=0;
    this->game_on=0;
    this->income=INT_MAX;

}
Game ::~Game() {}



//add player name to player name list
vector<string> Game::players()  {
    players_list.clear();
    for (unsigned int i =0;i<pl_count;i++) {
        if(all_players.at(i)->status==1){
            string add_name= this->all_players.at(i)->_player_name;
            players_list.push_back(add_name);}
        }
    return  players_list;}



    void Game ::update() {
            for (unsigned i = this->this_turn+1; i <= pl_count;i++) {
                if( i>=pl_count){
                    i=0;
                 if(this->all_players.at(i)->status==1){
                        this->this_turn =i ;
                     return;}
                }
                else {
                    if(this->all_players.at(i)->status==1){
                        this->this_turn =i ;
                        return;}
                        }
                  }
            }


    string Game::turn()const {
             return this->all_players.at(this->this_turn)->_player_name;}

string Game::winner() const {
    string the_winner;
    int player_now=0;
    if(this->game_on==0){
        throw out_of_range("The game is not over yet");
    }
    for (unsigned  int i = 0; i <pl_count ; ++i) {
        if(all_players.at(i)->status==1) {
            the_winner = all_players.at(i)->_player_name;
            player_now++;
            if (player_now != 1) {
                throw out_of_range("The game is not over yet");
            }
        }
    }

    return the_winner;}

    void Game::remove_player(Player &player) const {
        for (unsigned int i =0;i<pl_count;i++){
            if(&player== this->all_players[i]){
                this->all_players[i]->status=0;
                return;
            }
        }
}

void Game::return_player(Player &player, unsigned int pos) const{
    for (unsigned int i =0;i<pl_count;i++){
        if(& player== this->all_players[i]){
            this->all_players[i]->status=1;
            return;
        }
    }
}