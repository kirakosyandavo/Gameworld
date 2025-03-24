#ifndef MONSTER
#define MONSTER
#include"Character.h"
#include"Combatable.h"
enum class Monstertype{
    Goblin,
    Troll,
    Dragon

};
void print_monstertype(Monstertype monstertype){
    if(monstertype==Monstertype::Goblin){
        cout<<"Giblin"<<endl;
    }
   if(monstertype==Monstertype::Troll){
    cout<<"Troll"<<endl;
   } 
   if(monstertype==Monstertype::Dragon){
    cout<<"Dragon"<<endl;
   }  
} 
   
class Monster:public Character,public Combatable{
  public:
  Monster(string name,Monstertype type);
  void  displayStats()const override;
  void  takeDamage(int damage)override;
  void attack(Character* target)override;
  void useAbility(Character*target)override;
   
private:
Monstertype m_type;



};
#endif