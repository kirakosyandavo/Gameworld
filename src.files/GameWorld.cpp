#include"GameWorld.h"
void GameWorld::battle(Hero* hero,Monster* monster){
    while(hero->get_health()>0 && monster->get_health()>0){ 
     cout<<"it is the heros turn"<<endl;
     cout<<"1.attack"<<endl;
     cout<<"2.Use Ability"<<endl;
     cout<<"3.Use item"<<endl;
     int n;
     cin>>n;
     cout << "\033[2J\033[H"; 
     switch(n){
     case 1:
     hero->attack(monster);
     break;
     case 2:
     hero->useAbility(monster);
     break;
     case 3:
      hero->useItem();
      break;
      default:
      cout<<"invalid choice"<<endl;
      continue;
     }
     if(monster->get_health()>0){
    
        cout<<"Monsters turn "<<endl;
        monster->attack(hero);
     }
     
    cout<<"Hero health is "<<hero->get_health()<<"|Monster health is "<<monster->get_health()<<endl;

    }
    if(hero->get_health()>0){
        cout<<"you defeat the monster"<<endl;
          hero->gainXP(50);
    }
    else{
        cout<<"you hero is dead "<<endl;
        cout<<"game over"<<endl;
        exit(0);
    }

    }
void GameWorld::meetcharacter(Hero* hero,Location* location){
    if(location->get_entities().empty()){
        cout<<"there is no personage here"<<endl;
        cout<<"i adress you to move another location "<<endl;

        return; 
    }
    Character*encounter=location->get_entities()[0];
   if(dynamic_cast<NPC*>(encounter)){
    NPC*npc=dynamic_cast<NPC*>(encounter);
    npc->get_dialogue(hero);
    cout<<"after a long walk you meet a monster"<<endl;
    Monster* monster=new Monster("shreik",Monstertype::Goblin);
    cout<<"the battle start"<<endl;
    battle(hero,monster);
    
   }
   else if(dynamic_cast<Monster*>(encounter)){
    Monster*monst=dynamic_cast<Monster*>(encounter);
    cout<<"you meet a "<<monst->get_name()<<endl;
    cout<<"prepare for battle"<<endl;
     battle(hero,monst);
   }
   delete encounter;
   location->get_entities().erase((location->get_entities()).begin());

}
void GameWorld::addlocation(Location*location){
    locations.push_back(location);
}
void GameWorld::setCurrentLocation(Location* location) {
    currentLocation = location;
    std::cout << "Current location set to: " << location->get_Location_name() << endl;
}

void GameWorld::moveToLocation() {
    cout<<"which location you want to move"<<endl;
    for(int i=0;i<locations.size();i++){
        cout<<locations[i]->get_Location_name()<<endl;
    }
        int n;
        cin>>n;
    if ( n>= 0 && n < locations.size()) {
        currentLocation = locations[n];
        std::cout << "Moved to location: " << currentLocation->get_Location_name() <<endl;
    } else {
        std::cout << "Invalid location index!" << endl;
    }
}
void GameWorld::start(){
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
    /*GameWorld game;*/
    Location* village = new Location("Village");
    Location* forest = new Location("Dark Forest");
    Location* castle= new Location("Ancient casle");
    addlocation(village);
    addlocation(forest);
    addlocation(castle);
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
    (get_location())[0]->add_character(monster);
    (get_location())[0]->add_character(monster2);
    (get_location())[1]->add_character(trol);
    (get_location())[1]->add_character(trol2);
    (get_location())[2]->add_character(dragon);
    (get_location())[2]->add_character(dragon2);
     QuestManager questManager;
     questManager.add_quest(new Quest("Defeat the Goblin in the Dark Forest",10));
     questManager.add_quest(new Quest("Slay the Dragon in the Ancient Castle",10));
     questManager.add_quest(new Quest("kill the troll",15));
     NPC* wiseOldMan=new NPC("Wise old man",&questManager); 
     (get_location())[0]->add_character(wiseOldMan);
     NPC*villageElder=new NPC("village elder",&questManager);   
      (get_location())[1]->add_character(villageElder);
     NPC* castleGuard=new NPC("Castle Guard",&questManager);
     (get_location())[2]->add_character(castleGuard);
     while (true) {
        cout << "Choose your starting location:\n1. Village\n2. Dark Forest\n3. Ancient Castle\nEnter choice: ";
        int startlocation;
        cin >> startlocation;
        if (startlocation== 1) { 
            setCurrentLocation(village);
            break;
        }
        if (startlocation == 2) {
             setCurrentLocation(forest);
             break;
             }
        if (startlocation == 3) {
             setCurrentLocation(castle);
             break;
             }
        cout << "Invalid location. Try again.\n";
    }
    bool flag=true;
    cout << "\033[2J\033[H"; 
    cout <<"your game started"<<endl;
    while(flag){
      cout<<"your current location is ";
      print_location();
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
                if (n== 1) setCurrentLocation(village);
                if (n == 2) setCurrentLocation(forest);
                if(n==3) setCurrentLocation(castle);
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
         meetcharacter(&hero,get_currentLocation());
         break;
        }
        case 4:{
            exit(0);
            break;
        }
    }  
}










}
