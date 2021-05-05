#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
using namespace pandemic;


Researcher::Researcher(Board board, enum City a){
    CurrentCity = a;
    theBorad = board;
}
Player& Researcher::discover_cure(){
    return *this;
}
string Researcher::role(){
    return "Researcher";
}