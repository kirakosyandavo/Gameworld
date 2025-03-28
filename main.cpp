#include <iostream>
#include "GameWorld.h"
#include "Hero.h"
#include "Monster.h"
#include "Sword.h"
#include "HealthPotion.h"
#include "QuestManager.h"
#include "Location.h"

using namespace std;

int main() {
    cout<<"the game start first you must create the hero"<<endl;
    cout<<"enter the name"<<endl;
    string name;
    cin>>name;
    Herotype herotype;
    do{
    cout<<"select the type you want"<<endl;
    cout<<"1.Warrior"<<"  "<<"2.Mage"<<"  "<<"3.Rogue "<<endl;
    int n;
    cin>>n;
    switch(n){
     case 1: herotype=Herotype::Warrior;
     break;
     case 2: herotype=Herotype::Mage;
     break;
     case 3: herotype=Herotype::Rogue;
     break;
     default:cout<<"invalid choice.try again"<<endl;
     continue;

    }
    break;
}while(true);
     cout<<"you created your hero"<<endl;
     Hero hero(name,herotype);
    GameWorld game;
    Location* village = new Location("Village");
    Location* forest = new Location("Dark Forest");
    Location* castle= new Location("Ancient casle");
    game.addlocation(village);
    game.addlocation(forest);
    game.addlocation(castle);
    Sword* sword = new Sword("Tur Kecaki", 15);
    HealthPotion* potion = new HealthPotion("potiion",20);
    Magic_Amulet* amulet=new Magic_Amulet("amulet",12);
    hero.addItem(sword);
    hero.addItem(potion);
    hero.addItem(amulet);
    cout<<"by default your hero have items"<<endl;
    Monster* monster = new Monster("Goblin",Monstertype::Goblin);
    Monster* dragon=new Monster("draco",Monstertype::Troll);
    Monster* trol=new Monster("valdem",Monstertype::Dragon);
    Monster* monster2 = new Monster("Gob",Monstertype::Goblin);
    Monster* dragon2=new Monster("malf",Monstertype::Troll);
    Monster* trol2=new Monster("snap",Monstertype::Dragon);
    (game.get_location())[0]->add_character(monster);
    (game.get_location())[0]->add_character(monster2);
    (game.get_location())[1]->add_character(trol);
    (game.get_location())[1]->add_character(trol2);
    (game.get_location())[2]->add_character(dragon);
    (game.get_location())[2]->add_character(dragon2);
     QuestManager questManager;
     questManager.add_quest(new Quest("Defeat the Goblin in the Dark Forest",10));
     questManager.add_quest(new Quest("Slay the Dragon in the Ancient Castle",10));
     questManager.add_quest(new Quest("kill the troll",15));
     NPC* wiseOldMan=new NPC("Wise old man",&questManager);    

    // Quest system setup
    QuestManager questManager;
    questManager.addQuest("Defeat the Goblin in the Dark Forest");
    
    // Game loop
    bool gameRunning = true;
    while (gameRunning) {
        cout << "\nCurrent Location: " << hero->getLocation()->getName() << endl;
        cout << "1. Move to another location" << endl;
        cout << "2. Attack enemy" << endl;
        cout << "3. Use an item" << endl;
        cout << "4. Check quests" << endl;
        cout << "5. Quit Game" << endl;
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "Choose a location: 1. Village 2. Dark Forest" << endl;
                int locChoice;
                cin >> locChoice;
                if (locChoice == 1) hero->setLocation(village);
                else if (locChoice == 2) hero->setLocation(forest);
                break;
            }
            case 2:
                if (hero->getLocation() == monster->getLocation()) {
                    hero->attack(monster);
                    if (monster->isDefeated()) {
                        cout << monster->getName() << " is defeated!" << endl;
                        questManager.completeQuest("Defeat the Goblin in the Dark Forest");
                        cout << "Quest completed!" << endl;
                    } else {
                        monster->attack(hero);
                    }
                } else {
                    cout << "No enemies here!" << endl;
                }
                break;
            case 3:
                cout << "Hero uses a potion!" << endl;
                potion->use_Item(hero);
                break;
            case 4:
                questManager.displayQuests();
                break;
            case 5:
                gameRunning = false;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    
    // Clean up
    delete hero;
    delete monster;
    delete sword;
    delete potion;
    delete village;
    delete forest;
    
    return 0;
}
