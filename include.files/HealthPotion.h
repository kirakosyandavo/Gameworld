#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H
#include"Item.h"
#include"Hero.h"
class HealthPotion:public Item{
    public:
    HealthPotion(string name,int value):Item(name,value){}
    void use_Item(Character* character)override{
     character->recover(m_value);
    }
   string getName()const override{
    return m_name;
   }
   

};
#endif
