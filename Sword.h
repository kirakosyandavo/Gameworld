#ifndef SWORD
#define SWORD
#include"Item.h"
class Sword:public Item{
    public:
    Sword(string name,int value):Item(name,value){}
    void use_Item(Character*character)override{
     character->improve_attack(m_value);
    }
   string getName()const override{
    return m_name;
   }
   
};
#endif