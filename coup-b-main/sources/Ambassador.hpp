//
// Created by בר נחמיאס on 24/04/2022.
//


//using namespace std;
#include <string>
#include "Player.hpp"
namespace coup{
    class Ambassador : public Player {
    private:

    public:
        Ambassador(Game &_game ,const string &   _player_name);
        void  transfer (Player &take,Player &get);
        void block(Player & player);

    };


}


