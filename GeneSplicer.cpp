#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "GeneSplicer.hpp"
using namespace pandemic;



GeneSplicer ::GeneSplicer(Board board, enum City a){
    CurrentCity = a;
    theBorad = board;
}
Player& GeneSplicer::discover_cure(){
    return *this;
}
string GeneSplicer::role(){
    return "GeneSplicer";
}