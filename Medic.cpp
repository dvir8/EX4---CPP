#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Medic.hpp"
using namespace pandemic;


Medic ::Medic(Board board, enum City a){
    CurrentCity = a;
    theBorad = board;
}
Player& Medic::treat(enum City city){
    return *this;
}
string Medic::role(){
    return "Medic";
}