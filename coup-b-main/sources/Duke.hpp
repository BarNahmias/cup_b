//
// Created by בר נחמיאס on 24/04/2022.
//
#include <string>

#include "Player.hpp"
using namespace std;

 namespace coup{

class Duke : public Player {
    private:

    public:
        Duke(Game &_game , const string &   _player_name);

        virtual void block( Player & player);

        virtual void tax();

    };

}
