#include"QuestManager.h"
void QuestManager::add_quest(Quest* quest){
    activeQuests.push_back(quest);
}    
void QuestManager::complete_quest(Hero* hero,Quest* quest){
    quest->completedQuest(hero);
    for(int i=0;i<activeQuests.size();i++){
        if(completedQuests[i]==quest){
            activeQuests.erase(activeQuests.begin()+i);
            completedQuests.push_back(quest);
        }
    }
}
void QuestManager::assign_quest(Hero* hero,Quest* quest){
    cout<<hero->get_name()<<"assign"<<quest->get_description()<<endl;

}
bool QuestManager::checkQuestCompletion(Quest*quest){
    return quest->iscompleted();
}
void QuestManager::displayActiveQuests()const{
    for(int i=0;i<activeQuests.size();i++){
        cout<<activeQuests[i]->get_description()<<endl;
    }
}

void QuestManager::displayCompletedQuests()const{
    for(int i=0;i<completedQuests.size();i++){
        cout<<activeQuests[i]->get_description()<<endl;
    }
}
QuestManager::~QuestManager(){
    for(int i=0;i<activeQuests.size();i++){
        delete activeQuests[i];
    }
    activeQuests.clear();
    for(int i=0;i<completedQuests.size();i++){
         delete activeQuests[i];
    }
    completedQuests.clear();
}

