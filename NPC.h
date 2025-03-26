#ifndef npc
#define npc
#include"Character.h"
#include"Quest.h"
class NPC:public Character,public Interactable{
    NPC(string name);
    void displayStats()const;
    void virtual takeDamage(int damage)=0;
    void get_dialogue(){
       cout<<"im a villager can you help me"<<endl; 
    }
    






 private:
 string m_name;
 
  
 
};
#endif