//
// Created by בר נחמיאס on 24/04/2022.
//
#include <iostream>

#include <string>
#include "Player.hpp"
namespace coup{

    class Captain : public Player {
//    private:

    public:
        Captain(Game &game , const string &  player_name);
         void steal(Player & player);
         void block(Player & player);
         Captain * captain;
         Player *stolen;

    };

}
