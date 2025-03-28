#ifndef CHARACTER
#define CHARACTER
#include<iostream>
using namespace std;

class Character{
  protected:
  string m_name;
  int m_health; 
  int m_attackPower;
  int m_defense;
  public:
  Character(string name,int health,int attackPower,int defense):m_name(name),m_health(health),m_attackPower(attackPower),m_defense(defense){}
  void virtual displayStats()const=0;
  void virtual takeDamage(int damage)=0;
  virtual ~Character()=default;
  virtual void improve_defense(int value){
    m_defense+=value;
    cout<<"you improve your defense in "<<value<<endl;
    cout<<"your defense now is "<<get_defense()<<endl;
  }
  virtual void improve_attack(int value){
    m_attackPower+=value;
    cout<<"your hero attack improved in "<<value<<endl;
    cout<<"your hero attack now is "<<get_attackpower()<<endl;
 }
  virtual void recover(int value){
    m_health+=value;
    cout<<"your hero recovered in "<<value<<endl;
    cout<<"your health now is "<<get_health()<<endl;
  }
  int get_health(){
    return m_health;
  }
  int get_attackpower(){
    return m_attackPower;
  }
  int get_defense(){
    return m_defense;
  }
  string get_name(){
    return m_name;
  }
  
};
#endif 