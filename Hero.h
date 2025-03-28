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
class Hero:public Character,public Combatable,public Interactable{
    vector<Item*>m_inventory;
    int m_level;
    int m_XP;
    Herotype m_herotype;
    const int xptolevelup=100;
    public:
    void print_herotype()const;
    Hero(string name,Herotype herotype);
    void addItem(Item*inventory);
    void displayStats()const override;
    void takeDamage(int damage)override;
    void attack(Character* target)override;
    void useAbility(Character*target)override;
    void interact(Character*target);
    string getDialogue()const ;
    void useItem();
    void print_health()const;
    void printItem()const;
    void gainXP(int xp);
    void levelup();
    int getlevel();
    bool valid_item(){
        return m_inventory.size()>0;
    }
    ~Hero();
 
};
#endif
