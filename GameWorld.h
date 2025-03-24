#ifndef GAMEWORLD
#define GAMEWORLD
#include"Character.h"
#include"Location.h"
#include"Hero.h"
class GameWorld{
GameWorld();
void addlocation(Location*location);
void setCurrentLocation(Location* location);
void exploreCurrentLocation() const;
void moveToLocation(int index);
void meetcharacter(Hero* hero,Location* location ); 

private:
Location* currentLocation;
vector<Location*>locations;

};
#endif