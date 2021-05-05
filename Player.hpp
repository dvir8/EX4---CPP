#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
using namespace pandemic;
class Player {
   
    protected:
    Board theBorad;
    enum City CurrentCity;
    bool Cards[48];
    std::unordered_map<enum City ,Board::Node>& getMap(){
        return theBorad.theMap2;
    }
    std::unordered_map<enum Color, bool>& getCures(){
        return theBorad.Cures;
    }

    public:
    
    Player& drive (enum City);
    virtual Player& fly_direct(enum City);
    Player& fly_shuttle(enum City);
    Player& fly_charter(enum City);
    virtual Player& build();
    virtual Player& discover_cure(enum Color);
    virtual Player& treat(enum City);
    virtual string role() =0;
    Player& take_card(enum City);
};