#ifndef Heros
#define Heros
#include"Character.h"
#include"Combatable.h"
#include"Interactable.h"
#include"Item.h"
#include<vector>
#include"Magic_Amulet.h"
#include"Sword.h"
#include"HealthPotion.h"
enum class Herotype{
    Warrior,
    Mage,
    Rogue
};
void print_herotype(Herotype herotype){
    if(herotype==Herotype::Warrior){
        cout<<"Warrior"<<endl;
    }
   if(herotype==Herotype::Mage){
    cout<<"Mag"<<endl;
   } 
   if(herotype==Herotype::Rogue){
    cout<<"Rogue"<<endl;
   }  
} 
   
class Hero:public Character,public Combatable,public Interactable{
    vector<Item*>m_inventory;
    int m_level;
    int m_XP;
    Herotype m_herotype;
    const int xptolevelup=100;
    public:
    Hero(string name,Herotype herotype);
    void addItem(Item*inventory);
    void displayStats()const override;
    void takeDamage(int damage)override;
    void attack(Character* target)override;
    void useAbility(Character*target)override;
    void interact(Character*target)override;
    string getDialogue()const override;
    void useItem(int index);
    void printItem()const;
    void gainXP(int xp);
    void levelup();
    int getlevel();
    ~Hero();

};
#endif
