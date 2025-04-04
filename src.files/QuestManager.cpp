#include"QuestManager.h"
QuestManager::QuestManager(){
  activeQuests.push_back(new Quest("You should defeat the goblin",25));
  activeQuests.push_back(new Quest("you should defeat the monster",26));
  activeQuests.push_back(new Quest("You should defet the dragon",27));
}
void QuestManager::add_quest(Quest* quest){
    activeQuests.push_back(quest);
}    
void QuestManager::complete_quest(Hero* hero,Quest* quest){
    quest->completedQuest(hero);
    for(int i=0;i<activeQuests.size();i++){
        if(completedQuests[i]==quest){
            activeQuests.erase(activeQuests.begin()+i);
            completedQuests.push_back(quest);
            break;
        }
    }
}

bool QuestManager::checkQuestCompletion(Quest*quest){
    return quest->iscompleted();
}
void QuestManager::displayActiveQuests()const{
    for(int i=0;i<activeQuests.size();i++){
        cout<<activeQuests[i]->get_description()<<endl;
    }
}
Quest* QuestManager::get_Quest(){
    if(activeQuests.empty()){
        cout<<"there is no quest for you";
        return nullptr;
    }
    else{
        return activeQuests[0];
    }
}

void QuestManager::displayCompletedQuests()const{
    for(int i=0;i<completedQuests.size();i++){
        cout<<completedQuests[i]->get_description()<<endl;
    }
}
QuestManager::~QuestManager(){
    for(int i=0;i<activeQuests.size();i++){
        delete activeQuests[i];
    }
    activeQuests.clear();
    for(int i=0;i<completedQuests.size();i++){
         delete completedQuests[i];
    }
    completedQuests.clear();
}

