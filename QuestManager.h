#ifndef QUESTMANAGER
#define QUESTMANAGER
#include"Quest.h"
class QuestManager{
QuestManager()=default;    
void add_quest(Quest* quest);
void complete_quest(Hero*hero,Quest*quest);
bool checkQuestCompletion(Quest*quest);
void displayActiveQuests()const;
void displayCompletedQuests()const;
void assign_quest(Hero* hero,Quest* quest);
~QuestManager();
private:
 vector<Quest*>activeQuests;
 vector<Quest*>completedQuests; 

};
#endif