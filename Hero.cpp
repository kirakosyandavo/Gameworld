#include"Hero.h"
Hero::Hero(string name,Herotype herotype):Character(name,100,25,10){
    m_herotype=herotype;
    m_level=1;
    m_XP=0;  
}
void Hero::addItem(Item*inventory){
   m_inventory.push_back(inventory);
}

void Hero::displayStats()const{
    cout<<"Hero:"<<m_name<<endl;
    cout<<"your hero is:";print_herotype(m_herotype);cout<<endl;
    cout<<"health:"<<m_health<<endl;
    cout<<"attackPower:"<<m_attackPower<<endl;
    cout<<"defense:"<<m_defense<<endl;
    cout<<"level:"<<m_level<<endl;
    cout<<"XP:"<<m_XP;
}
 void Hero::takeDamage(int damage){
    damage-=m_defense;
    if(damage>0){
        m_health-=damage;
          if(m_health<0){
            cout<<"your hero is dead";
          }
    }   
 }
    void Hero::attack(Character* target){
        if(target==nullptr){
            return;
        }
        target->takeDamage(m_attackPower);
        cout<<"Your hero attack on"<<target->get_name()<<"in attackpower:"<<m_attackPower<<endl;     
    }
    void Hero::useAbility(Character*target){
      if(target==nullptr){
        cout<<"there is no such target"<<endl;
        return;
      }
      if(m_herotype==Herotype::Warrior){
        cout<<"you use Power Strike on:"<< target->get_name()<<endl;
        target->takeDamage(20);
      }
      if(m_herotype==Herotype::Mage){
        cout<<"you use Fireball on:"<<target->get_name()<<endl;
        target->takeDamage(20); 
      }
      if(m_herotype==Herotype::Rogue){
        cout<<"you use Stealth Attack on:"<<target->get_name()<<endl;
        target->takeDamage(20);
      }
    }
    void Hero::interact(Character*target){
      cout<<"your hero interact with:"<<target->get_name()<<endl;
    }
    string Hero::getDialogue()const {
      return "Hello i am hero";
    }
    Hero::~Hero(){
     for(int i=0;i<m_inventory.size();i++){
      delete []m_inventory[i];
     }
     m_inventory.clear();
    }