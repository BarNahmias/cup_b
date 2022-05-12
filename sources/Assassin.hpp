//
// Created by בר נחמיאס on 24/04/2022.
//
#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;

namespace coup{
class Assassin : public Player {
    private:

    public:
        Assassin(Game &_game , const string &  _player_name);
        Assassin(Assassin & assassin);
        Player * remove_this_player;
        unsigned  int  remove_index;

    };

}
