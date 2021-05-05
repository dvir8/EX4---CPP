#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Virologist.hpp"
using namespace pandemic;

Virologist::Virologist(Board board, enum City a){
    CurrentCity = a;
    theBorad = board;
}
Player& Virologist::treat(enum City a){
    return *this;
}
string Virologist::role(){
    return "Virologist";
}