#include <iostream>
#include "Hero.h"
#include "Monster.h"
#include "Sword.h"
#include "HealthPotion.h"
#include "QuestManager.h"
#include "Location.h"
#include"GameWorld.h"

using namespace std;

int main() {
    cout<<"the game start first you must create the hero"<<endl;
    cout<<"enter the name"<<endl;
    string name;
    cin>>name;
    Herotype herotype;
    do{
    cout << "\033[2J\033[H";     
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
     cout << "\033[2J\033[H"; 
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
    HealthPotion* potion = new HealthPotion("potion",20);
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
     (game.get_location())[0]->add_character(wiseOldMan);
     NPC*villageElder=new NPC("village elder",&questManager);   
      (game.get_location())[1]->add_character(villageElder);
     NPC* castleGuard=new NPC("Castle Guard",&questManager);
     (game.get_location())[2]->add_character(castleGuard);
     while (true) {
        cout << "Choose your starting location:\n1. Village\n2. Dark Forest\n3. Ancient Castle\nEnter choice: ";
        int startlocation;
        cin >> startlocation;
        if (startlocation== 1) { 
            game.setCurrentLocation(village);
            break;
        }
        if (startlocation == 2) {
             game.setCurrentLocation(forest);
             break;
             }
        if (startlocation == 3) {
             game.setCurrentLocation(castle);
             break;
             }
        cout << "Invalid location. Try again.\n";
    }
    bool flag=true;
    cout << "\033[2J\033[H"; 
    cout <<"your game started"<<endl;
    while(flag){
      cout<<"your current location is ";
      game.print_location();
        cout << "1. Move to another location" << endl;
        cout << "2. Use an item" << endl;
        cout << "3. Meet a character" << endl;
        cout << "4. Quit Game" << endl;
        
        int choice;
        cin >> choice;
        cout << "\033[2J\033[H"; 
        switch (choice) {
            case 1: {
                cout << "Choose a location: 1. Village 2. Dark Forest 3.ancient castle" << endl;
                int n;
                cin >> n;
                cout << "\033[2J\033[H"; 
                if (n== 1) game.setCurrentLocation(village);
                if (n == 2) game.setCurrentLocation(forest);
                if(n==3) game.setCurrentLocation(castle);
                break;
            }
            case 2:{
            if(hero.valid_item()){
                hero.useItem();
        }
        else{ cout<<"you dont have item"<<endl;
            
        }
        break;

        }
        case 3:{
         game.meetcharacter(&hero,game.get_currentLocation());
         break;
        }
        case 4:{
            exit(0);
            break;
        }
    }  
}
    return 0;
    }
  