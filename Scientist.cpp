#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Scientist.hpp"
using namespace pandemic;


Scientist::Scientist(Board board, enum City a, int toThrow1){
    CurrentCity = a;
    theBorad = board;
    toThrow1 = toThrow;
}
Player& Scientist::discover_cure(enum Color){
    return *this;
}
string Scientist::role(){
    return "Scientist";
}