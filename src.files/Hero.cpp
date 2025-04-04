#include"Hero.h"
Hero::Hero(string name,Herotype herotype):Character(name,100,25,15){
    m_herotype=herotype;
    m_level=1;
    m_XP=0;  
}
void Hero::addItem(Item*inventory){
  m_inventory.push_back(inventory);
}
  void Hero::useItem() {
    cout<<"which item you want to use"<<endl;
    printItem();
    int index;
    cin>>index;
    if (index >= 1 && index < m_inventory.size()+1) {
      cout<<"you use "<<m_inventory[index-1]->getName()<<endl;
        m_inventory[index-1]->use_Item(this); 
        delete m_inventory[index-1];
        m_inventory.erase(m_inventory.begin()+index-1);
        cout<<"your item was used"<<endl; 
    }else{
        std::cout << "Invalid item index.\n";
    }
    }
    void Hero::gainXP(int xp){
      cout<<"your hero gained "<<xp<<"xp"<<endl;
      m_XP+=xp;
      if(m_XP>=xptolevelup){
        levelup();
      }
    }
    int Hero::getlevel(){
      return m_level;
    }
    void Hero::levelup(){
         while(m_XP>=xptolevelup){
          m_XP-=xptolevelup;
          m_level++;
          m_health+=25;
          m_defense+=15;
          m_attackPower+=25;
          cout<<"your level is up"<<m_level<<endl;
          cout<<endl;
         }
    }
  
void Hero::displayStats()const{
    cout<<"Hero:"<<m_name<<endl;
    cout<<"your hero is:";print_herotype();cout<<endl;
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
            cout<<"your hero is dead ";
          }
    }   
 }

    void Hero::attack(Character* target){
        if(target==nullptr){
            return;
        }
        target->takeDamage(m_attackPower);
        cout<<"Your hero attack on "<<target->get_name()<<" in attackpower:"<<m_attackPower<<endl;     
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
    void Hero::printItem()const{
      int n=1;
      for(int i=0;i<m_inventory.size();i++){
        cout<<n<<"."<<m_inventory[i]->getName()<<endl;
        n++;
      }
    }
    void Hero::print_herotype()const{
      if(m_herotype==Herotype::Warrior){
          cout<<"Warrior"<<endl;
      }
     if(m_herotype==Herotype::Mage){
      cout<<"Mag"<<endl;
     } 
     if(m_herotype==Herotype::Rogue){
      cout<<"Rogue"<<endl;
     }  
  } 
    Hero::~Hero(){
     for(int i=0;i<m_inventory.size();i++){
      delete m_inventory[i];
     }
     m_inventory.clear();
    }
    

   
   