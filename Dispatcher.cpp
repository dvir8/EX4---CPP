#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Dispatcher.hpp"
using namespace pandemic;


Dispatcher::Dispatcher(Board board, enum City city){
    CurrentCity = city;
    theBorad = board;
    
}
Player& Dispatcher::fly_direct(enum City city){
    if(!getMap()[CurrentCity].theBuild&&Cards[(int)city]){
        throw invalid_argument("Cant do that");
    }
    CurrentCity = city;
    return *this;
}
string Dispatcher::role(){
    return "Dispatcher";
}