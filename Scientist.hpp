
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class Scientist: public Player{
    int toThrow;
    public:

        Scientist(Board board, enum City a , int toThrow2);
        Player& discover_cure(enum Color);
        string role();

};