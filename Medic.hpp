
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class Medic: public Player{

    public:

        Medic(Board board, enum City);
        Player& treat(enum City);
        string role();

};