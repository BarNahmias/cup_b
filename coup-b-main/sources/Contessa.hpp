//
// Created by בר נחמיאס on 24/04/2022.
//
#include <iostream>

#include <string>
#include "Player.hpp"

 namespace coup{

    class Contessa : public Player {
//    private:

    public:
        Contessa(Game &_game , const string &  _player_name);

         void block(Player & player);

    };


}