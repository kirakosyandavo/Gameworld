#include"Monster.h"
Monster::Monster(string name,Monstertype type):Character(name,50,25,10){
    m_type=type;
}
void Monster::displayStats() const{
    cout<<"Monster:"<<m_name<<endl;
    cout<<"monster is:";print_monstertype();cout<<endl;
    cout<<"health:"<<m_health<<endl;
    cout<<"attackPower:"<<m_attackPower<<endl;
    cout<<"defense:"<<m_defense<<endl;
}
void  Monster::takeDamage(int damage){
    damage-=m_defense;
    if(damage>0){
        m_health-=damage;
          if(m_health<0){
            cout<<"monster is dead ";
          }
    }   
 }   
 void Monster::print_monstertype()const{
    if(m_type==Monstertype::Goblin){
        cout<<"Giblin"<<endl;
    }
   if(m_type==Monstertype::Troll){
    cout<<"Troll"<<endl;
   } 
   if(m_type==Monstertype::Dragon){
    cout<<"Dragon"<<endl;
   }  
} 

void Monster::attack(Character* target){
    if(target==nullptr){
        return;
    }
    target->takeDamage(m_attackPower);
    cout<<"monster attack on "<<target->get_name()<<" in attackpower: "<<m_attackPower<<endl;     
}
void Monster::useAbility(Character*target){
    if(m_type==Monstertype::Goblin){
        cout<<"Goblin use poison attack on"<<target->get_name()<<endl;
        cout<<"your hero was damaged in 25 health"<<endl;
        target->takeDamage(25);
    }
    if (m_type==Monstertype::Dragon){
        cout<<"Dragon use fire attack on"<<target->get_name()<<endl;
        cout<<"your hero was damaged in 25 health"<<endl;
        target->takeDamage(25);   
    }
    if(m_type==Monstertype::Troll){
        cout<<"Troll use area attack on"<<target->get_name()<<endl;
        cout<<"your hero was damaged in 25 health"<<endl;
        target->takeDamage(25);
    }
}
 