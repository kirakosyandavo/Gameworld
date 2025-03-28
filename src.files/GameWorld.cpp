#include"GameWorld.h"
void GameWorld::battle(Hero* hero,Monster* monster){
    while(hero->get_health()>0 && monster->get_health()>0){ 
     cout<<"it is the heros turn"<<endl;
     cout<<"1.attack"<<endl;
     cout<<"2.Use Ability"<<endl;
     cout<<"3.Use item"<<endl;
     int n;
     cin>>n;
     cout << "\033[2J\033[H"; 
     switch(n){
     case 1:
     hero->attack(monster);
     break;
     case 2:
     hero->useAbility(monster);
     break;
     case 3:
      hero->useItem();
      break;
      default:
      cout<<"invalid choice"<<endl;
      continue;
     }
     if(monster->get_health()>0){
    
        cout<<"Monsters turn "<<endl;
        monster->attack(hero);
     }
     
    cout<<"Hero health is "<<hero->get_health()<<"|Monster health is "<<monster->get_health()<<endl;

    }
    if(hero->get_health()>0){
        cout<<"you defeat the monster"<<endl;
          hero->gainXP(50);
    }
    else{
        cout<<"you hero is dead "<<endl;
        cout<<"game over"<<endl;
        exit(0);
    }

    }
void GameWorld::meetcharacter(Hero* hero,Location* location){
    if(location->get_entities().empty()){
        cout<<"there is no personage here"<<endl;
        cout<<"i adress you to move another location "<<endl;

        return; 
    }
    Character*encounter=location->get_entities()[0];
   if(dynamic_cast<NPC*>(encounter)){
    NPC*npc=dynamic_cast<NPC*>(encounter);
    npc->get_dialogue(hero);
    cout<<"after a long walk you meet a monster"<<endl;
    Monster* monster=new Monster("shreik",Monstertype::Goblin);
    cout<<"the battle start"<<endl;
    battle(hero,monster);
    
   }
   else if(dynamic_cast<Monster*>(encounter)){
    Monster*monst=dynamic_cast<Monster*>(encounter);
    cout<<"you meet a "<<monst->get_name()<<endl;
    cout<<"prepare for battle"<<endl;
     battle(hero,monst);
   }
   delete encounter;
   location->get_entities().erase((location->get_entities()).begin());

}
void GameWorld::addlocation(Location*location){
    locations.push_back(location);
}
void GameWorld::setCurrentLocation(Location* location) {
    currentLocation = location;
    std::cout << "Current location set to: " << location->get_Location_name() << endl;
}

void GameWorld::moveToLocation() {
    cout<<"which location you want to move"<<endl;
    for(int i=0;i<locations.size();i++){
        cout<<locations[i]->get_Location_name()<<endl;
    }
        int n;
        cin>>n;
    if ( n>= 0 && n < locations.size()) {
        currentLocation = locations[n];
        std::cout << "Moved to location: " << currentLocation->get_Location_name() <<endl;
    } else {
        std::cout << "Invalid location index!" << endl;
    }
}
