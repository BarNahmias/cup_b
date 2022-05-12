//
// Created by בר נחמיאס on 24/04/2022.
//

#include "Assassin.hpp"
using namespace coup;
Assassin::Assassin(Game &_game, const string &_player_name) : Player(_game,  _player_name,"Assassin"){
    this->remove_this_player = nullptr;
    this->remove_index=0;
}

//void Assassin::coup (Player & player) {
////    cout << "block" << endl;
//}