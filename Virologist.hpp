
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class Virologist: public Player{

    public:

        Virologist(Board board, enum City a);
        Player& treat(enum City a);
        string role();

};