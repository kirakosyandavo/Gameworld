#ifndef MAGICAMULET
#define MAGICAMULET
#include"Item.h"
class Magic_Amulet:public Item{
    public:
    Magic_Amulet(string name,int value):Item(name,value){}
    void use_Item(Character* character)override{
      character->improve_defense(m_value);
    }
   string getName()const override{
    return m_name;
   }
   
};
#endif
