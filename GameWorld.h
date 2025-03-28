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
GameWorld();
void start(){
    cout<<"you start the game"<<endl;
    cout<<"what you want to do"<<endl;


}
void addlocation(Location*location);
void setCurrentLocation(Location* location);
void moveToLocation();
void meetcharacter(Hero* hero,Location* location ); 
void battle(Hero* hero,Monster* monster);
vector<Location*> get_location(){
    return locations;
}
private:
Location* currentLocation;
vector<Location*>locations;

};
#endif