#ifndef Npc
#define Npc
#include"Character.h"
#include"QuestManager.h"
class NPC:public Character,public Interactable{
   public:
   NPC()=default;
   NPC(string name,QuestManager* questmanager):Character(name,0,0,0),m_questmanager{questmanager}{}
    void displayStats()const{
      cout<< m_name<<endl;
    }
      void virtual takeDamage(int damage){}
    void get_dialogue(Hero* hero){
       cout<<"im a villager can you help me"<<endl;
       cout<<"i have quest for you"<<endl;
       Quest*quest=m_questmanager->get_Quest();
       quest->get_description();
       m_questmanager->assign_quest(hero,quest);
    }
 private:
 string m_name;
 QuestManager* m_questmanager;
 
};
#endif