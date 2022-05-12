//
// Created by בר נחמיאס on 24/04/2022.
//
#ifndef PLAYER_H
#define PLAYER_H
//#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include "Game.hpp"
#include <stdexcept>
#include <vector>
using namespace std;
#include <string>


namespace coup{
    class Game;

    class Player {

//    protected:
    public:


        string _player_name;
        string _role;
        int _coins;
        Game * _game;
        int status;
        string last_action;
//        vector <coup::player*> players_in_game;



        //    constructor
        Player(Game & game, const string & player_name ,const string & role) ;

//        methods
         void income();

         void  foreign_aid();

         void virtual coup(Player & player);

        virtual string role();

         int  coins() const;


         void do_coup() const;


    };

}

#endif