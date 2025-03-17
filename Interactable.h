#include"Character.h"
using namespace std;
class Interactable{
    virtual void interact(Character*target)=0;
    virtual  string getDialogue()const=0;
};