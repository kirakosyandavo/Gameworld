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
    cout<<"you meet a villager"<<endl;
    cout<<npc->getDialogue()<<endl;
    
   }
   if(dynamic_cast<Monster*>(encounter)){
    Monster*monst=dynamic_cast<Monster*>(encounter);
    cout<<"you meet a"<<monst->get_name()<<endl;
    cout<<"prepare for battle"<<endl;
     battle(hero,monst);
   }  
}