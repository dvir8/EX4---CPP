#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "FieldDoctor.hpp"
using namespace pandemic;


FieldDoctor::FieldDoctor(Board board, enum City a){
    CurrentCity = a;
    theBorad = board;
}
Player& FieldDoctor::treat(enum City a){
return *this;
}
string FieldDoctor::role(){
    return "FieldDoctor";
}