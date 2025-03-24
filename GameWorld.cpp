#include"GameWorld.h"
void GameWorld::meetcharacter(Hero* hero,Location* location){
    if(location->get_entities().size()==0){
        cout<<"there is no personage here"<<endl; 
    }
    Character*encounter=location->get_entities()[0];
   if(dynamic_cast<NPC*>(encounter)){
    npc=dynamic_cast<NPC*>(encounter);
    cout<<"you meet a villager"<<endl;
    cout<<npc->getDialogue()<<endl;

   }  
}