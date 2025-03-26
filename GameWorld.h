#ifndef GAMEWORLD
#define GAMEWORLD
#include"Character.h"
#include"Location.h"
#include"Hero.h"
#include"Monster.h"
class GameWorld{
GameWorld();
void addlocation(Location*location);
void setCurrentLocation(Location* location);
void exploreCurrentLocation() const;
void moveToLocation(int index);
void meetcharacter(Hero* hero,Location* location ); 
void battle(Hero* hero,Monster* monster);
private:
Location* currentLocation;
vector<Location*>locations;

};
#endif