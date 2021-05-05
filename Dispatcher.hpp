
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class Dispatcher: public Player{

    public:

        Dispatcher(Board board, enum City a);
        Player& fly_direct(enum City a);
        string role(); 


};