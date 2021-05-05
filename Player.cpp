#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"
using namespace pandemic;
const int MAX_CARDS =48;

Player& Player::fly_direct(enum City a){
    if(Cards[(int)a] == false){
        throw invalid_argument("you dont own the card");
    }
    CurrentCity = a;
    return *this;
}
Player& Player::fly_shuttle(enum City a){
    if(!(theBorad.theMap2[CurrentCity].theBuild && theBorad.theMap2[a].theBuild)){
        throw invalid_argument("Can't do that, no research facility");
    }
    return *this;
}
Player& Player::fly_charter(enum City a){
    if(!Cards[(int)CurrentCity]){
        throw invalid_argument("you dont own that card");
    }
    Cards[(int)CurrentCity]=false;
    CurrentCity = a;
    return *this;
}
Player& Player::build(){
    if(!Cards[(int)CurrentCity]){
        throw invalid_argument("you dont own that card");
    }
    theBorad.theMap2[CurrentCity].theBuild=true;
    Cards[(int)CurrentCity]=false;
    return *this;
}

Player& Player::take_card(enum City a){
    Cards[int(a)]=true;
    return *this;
}
Player& Player::treat(enum City a){
    if(CurrentCity!=a){
        throw invalid_argument("you are not in this city");
    }
    if(!theBorad.theMap2[CurrentCity].cube){
        throw invalid_argument("there are no cubes in this city");
    }
    if(theBorad.Cures[theBorad.theMap2[a].colorOfCity]){
        theBorad.theMap2[a].cube=0;
    }
    else{
        theBorad.theMap2[a].cube--;
    }

    return *this;
}
Player& Player::discover_cure(enum Color a){
    int count = 0;
    if(!theBorad.theMap2[CurrentCity].theBuild){
        throw invalid_argument("no research facility");
    }
    if(theBorad.Cures[a]){
        return *this;
    }
    for (size_t i = 0; i < MAX_CARDS; i++)
    {
        if(Cards[i]&&theBorad.theMap2[(enum City)i].colorOfCity==a){
            count++;
            Cards[i]=false;
        }
        if(count==5){
            theBorad.Cures[a]=true;
            break;
        }
        
    }
    if(count!=5){
        throw invalid_argument("not enough chards");
    }
    
    
    return *this;
}
Player& Player::drive (enum City a){
    

    for (size_t i = 0; i < 6; i++)
    {   
        if(theBorad.theMap2.at(CurrentCity).currenyCity[i]==a){
            break;
        }
        if(i==5){
            
            throw invalid_argument("City is not connected");
        }
    }
    
    CurrentCity = a;
    return *this;
}

