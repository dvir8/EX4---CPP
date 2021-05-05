#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include "City.hpp"
#include"Color.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;


Board::Node::Node(std::string color, std::string city, enum City x[]){
    colorOfCity = StringToColor(color);
    CityNow = StringToEnum(city);
    for (size_t i = 0; i < 6; i++)
    {
        currenyCity[i]=x[i];
    }
    
    cube =0;
    theBuild = false;
}
Board::Board(){
    Cures[Color::Yellow];
    Cures[Color::Black];
    Cures[Color::Blue];
    Cures[Color::Red];
    ifstream file("cities_map.txt");
    string Line;
    string city1;
    string city2;
    string color;
    while(getline(file,Line)){
        istringstream word{Line};
        word >> city1;
        word >> color;
        
        int i = 0;
        enum City m[6];
        while(word){
            word >> city2;
            m[i++]= StringToEnum(city2);           
            
        }
        Node x{color,city1,m};
        theMap2.insert({StringToEnum(city1),x});
    }
    
    
    

}
unsigned int& Board::operator[](enum City a){
    return theMap2[a].cube;
}
void Board::remove_cures(){
    for(auto& it : Cures){
        it.second=false;
    }
}
bool Board::is_clean(){
    bool ans = true;
    for(auto const& theKeyOfMap:theMap2){
        if(theKeyOfMap.second.cube != 0 ){
            ans = false;
            return ans;
        }
     }
     return ans;
}
ostream& operator<<(ostream& os , Board board){
 return os;
}


enum Color StringToColor(string color){
    if(color=="Yellow"){
        return Color::Yellow;
    }
    else if(color=="Black"){
        return Color::Black;
    }
    else if(color=="Red"){
        return Color::Red;
    }
    else if(color=="Blue"){
        return Color::Blue;
    }
    return Color::Red;


}
enum City StringToEnum(string city){

    if(city=="Algiers"){
        return City::Algiers;
    }
    else if(city=="Atlanta"){
        return City::Atlanta;
    }
    else if(city=="Baghdad"){
        return City::Baghdad;
    }
    else if(city=="Bangkok"){
        return City::Bangkok;
    }
    else if(city=="Beijing"){
        return City::Beijing;
    }
    else if(city=="Bogota"){
        return City::Bogota;}
        
    else if(city=="BuenosAires"){
        return City::BuenosAires;}
    
    else if(city=="Cairo"){
        return City::Cairo;}
    
    else if(city=="Chennai"){
        return City::Chennai;}
    
    else if(city=="Chicago"){
        return City::Chicago;}
    
    else if(city=="Delhi"){
        return City::Delhi;}
    
    else if(city=="Essen"){
        return City::Essen;}
    
    else if(city=="HoChiMinhCity"){
        return City::HoChiMinhCity;}
    
    else if(city=="HongKong"){
        return City::HongKong;}
    
    else if(city=="Istanbul"){
        return City::Istanbul;}
    
    else if(city=="Jakarta"){
        return City::Jakarta;}
    
    else if(city=="Johannesburg"){
        return City::Johannesburg;}
    
    else if(city=="Karachi"){
        return City::Karachi;}
    
    else if(city=="Khartoum"){
        return City::Khartoum;}
    
    else if(city=="Kinshasa"){
        return City::Kinshasa;}
    
    else if(city=="Kolkata"){
        return City::Kolkata;}
    
    else if(city=="Lagos"){
        return City::Lagos;}
    
    else if(city=="Lima"){
        return City::Lima;}
    
    else if(city=="London"){
        return City::London;}
    
    else if(city=="LosAngeles"){
        return City::LosAngeles;}
    
    else if(city=="Madrid"){
        return City::Madrid;}
    
    else if(city=="Manila"){
        return City::Manila;}
    
    else if(city=="MexicoCity"){
        return City::MexicoCity;}
    
    else if(city=="Miami"){
        return City::Miami;}
    
    else if(city=="Milan"){
        return City::Milan;}
    
    else if(city=="Montreal"){
        return City::Montreal;}
    else if(city=="Moscow"){
        return City::Moscow;
    }
    else if(city=="Mumbai"){
        return City::Mumbai;
    }
    else if(city=="NewYork"){
        return City::NewYork;
    }
    else if(city=="Osaka"){
        return City::Osaka;
    }
    else if(city=="Paris"){
        return City::Paris;
    }
    else if(city=="Riyadh"){
        return City::Riyadh;
    }
    else if(city=="SanFrancisco"){
        return City::SanFrancisco;
    }
    else if(city=="Santiago"){
        return City::Santiago;
    }
    else if(city=="SaoPaulo"){
        return City::SaoPaulo;
    }
    else if(city=="Seoul"){
        return City::Seoul;
    }
    else if(city=="Shanghai"){
        return City::Shanghai;
    }
    else if(city=="StPetersburg"){
        return City::StPetersburg;
    }
    else if(city=="Sydney"){
        return City::Sydney;
    }
    else if(city=="Taipei"){
        return City::Taipei;
    }
    else if(city=="Tehran"){
        return City::Tehran;
    }
    else if(city=="Tokyo"){
        return City::Tokyo;
    }
    else if(city=="Washington"){
        return City::Washington;
    }
    return City::SanFrancisco;

}
