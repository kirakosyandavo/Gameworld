#include"GameWorld.h"
void GameWorld::battle(Hero* hero,Monster* monster){
    while(hero->get_helth()>0 && monster->get_helth()>0){ 
     cout<<"it is the heros turn"<<endl;
     cout<<"1.attack"<<endl;
     cout<<"2.Use Ability"<<endl;
     cout<<"3.Use item"<<endl;
     int n;
     cin>>n;
     switch(n){
     case 1:
     hero->attack(monster);
     break;
     case 2:
     hero->useAbility(monster);
     break;
     case 3:
     cout<<"you have such items at your disposal"<<endl;
      hero->printItem();
      cout<<"which item you want use in 0-2"<<endl;
      int h;
      cin>>h;
      hero->useItem(h);
      break;
      default:
      cout<<"invalid choice"<<endl;
      continue;
     }
     if(monster->get_helth()>0){
        cout<<"Monsters turn"<<endl;
        monster->attack(hero);
     }
     cout<<"Hero health is"<<hero->get_helth()<<"|Monster health is"<<monster->get_helth()<<endl;
    }
    if(hero->get_helth()>0){
        cout<<"you defeat the monster"<<endl;
          hero->gainXP(10);
    }
    else{
        cout<<"you hero is dead "<<endl;
        cout<<"game over"<<endl;
        exit(0);
    }

    }
void GameWorld::meetcharacter(Hero* hero,Location* location){
    if(location->get_entities().size()==0){
        cout<<"there is no personage here"<<endl; 
    }
    Character*encounter=location->get_entities()[0];
   if(dynamic_cast<NPC*>(encounter)){
    NPC*npc=dynamic_cast<NPC*>(encounter);
    npc->get_dialogue(hero);
    cout<<"after a long walk you meet a it"<<endl;
    Monster* monster=new Monster("shreik",Monstertype::Goblin);
    cout<<"the battle start"<<endl;
    battle(hero,monster);
    
   }
   if(dynamic_cast<Monster*>(encounter)){
    Monster*monst=dynamic_cast<Monster*>(encounter);
    cout<<"you meet a"<<monst->get_name()<<endl;
    cout<<"prepare for battle"<<endl;
     battle(hero,monst);
   }  
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
