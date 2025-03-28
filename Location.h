#ifndef LOCATION_H
#define LOCATION_H
#include"Character.h"
#include<vector>
class Location{
    public:
    Location(const string& name):m_name(name){};
    void addentity(Character*entity){
        entities.push_back(entity);
        cout<<entity->get_name()<<"added in location"<<endl;
    }
    void displayLocationInfo()const{
        cout << "You are in the " << m_name << endl;
        cout << "Characters here"<<endl;
        for (int i=0;i<entities.size();i++){
            entities[i]->displayStats();
        }
    }
     string get_Location_name()const{
        return m_name;
    }
   vector<Character*> get_entities(){
    return entities;
   } 
   void add_character(Character* p){
    entities.push_back(p);
   } 
private:
string m_name;
vector<Character*>entities;

};
#endif