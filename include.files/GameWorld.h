#ifndef GAMEWORLD
#define GAMEWORLD
#include"Character.h"
#include"Location.h"
#include"Hero.h"
#include"Monster.h"
#include"NPC.h"
#include<memory>
class GameWorld{
public:
GameWorld()=default;
void start();
void addlocation(Location*location);
void print_location(){
    cout<<currentLocation->get_Location_name()<<endl;
}
void setCurrentLocation(Location* location);
void moveToLocation();
void meetcharacter(Hero* hero,Location* location ); 
void battle(Hero* hero,Monster* monster);
vector<Location*> get_location(){
    return locations;
}
Location* get_currentLocation(){
    return currentLocation;
}   
private:
Location* currentLocation;
vector<Location*>locations;

};
#endif