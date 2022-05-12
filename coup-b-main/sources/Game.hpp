//
// Created by בר נחמיאס on 24/04/2022.
//
#ifndef GAME_H
#define GAME_H
//#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Player.hpp"

using namespace std;

namespace coup{
    class Player;
        class Game {

    public:

//          vector withe all the players in the game
            vector <Player*> all_players;
//          save how many player in the game
            unsigned int pl_count;
//          save the cornet turn
            unsigned int this_turn;
//          vector withe all the name players in the game
            vector <string> players_list;
//          game cash
            unsigned  int income;
//          if the game start then game on==1;
            int game_on;



//          constructor
            Game();
//          destructor
            ~Game() ;


//          return name of player that play now
            string turn() const;
//          return winner name
            string winner() const;
//          list of players
            vector <string> players();
//         this method add player to game
//            void add_player(Player & player);
//         this method remove player from game
            void remove_player(Player & player) const;
//         this method return player to game after coup
            void return_player(Player & player,unsigned int pos) const
            ;
//         this method update status game after any action
            void update();
//         this method check if the game start and there is 2 player munition in the game
//            void good_action(Player & player);


        };

}

#endif
