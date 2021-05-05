#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include "City.hpp"
#include "Color.hpp"
using namespace std;
using namespace pandemic;

enum Color StringToColor(std::string color);
enum City StringToEnum(string city);
class Board  {
    
    class Node{
        public:
        enum City currenyCity[6];
        enum Color colorOfCity;
        enum City CityNow;
        unsigned int cube;
        bool theBuild;
        Node(){
            currenyCity[0] = City::Algiers;
            colorOfCity = Color::Yellow;
            CityNow = City::Algiers;
            cube = 0;
            theBuild =false;

        }
        Node(std::string color, std::string city, enum City x[]);

    };
    private:
    std::unordered_map<enum City ,Node> theMap2;
    std::unordered_map<enum Color, bool> Cures;    
    public:
    
    Board();
    unsigned int& operator[](enum City);    
    friend ostream& operator<<(ostream& os , Board board);
    bool is_clean();
    void remove_cures();

    friend class Player;

    
    
    


    
};



