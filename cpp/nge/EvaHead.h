#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
class Eva;

class Angel{
static int angeliTotali;
private:
  string name;
  int number;
  string shape;
  int health;
public:

  Angel(string itsName, int itsNumber, string itsShape, int itsHealth){
    this->name = itsName;
    this->number = itsNumber;
    this->shape = itsShape;
    this->health = itsHealth;
    cout <<"Creating angel"<<endl;
  };
  string getAngelName(){
    return this->name;
  }
  int getAngelNumber(){
    return this->number;
  }
  string getAngelShape(){
    return this->shape;
  }
  int getAngelHealth(){
    return this->health;
  }
  void angelDamaged(string attacker, int damage){
    cout << attacker << " has damaged the angel number"<< this->getAngelNumber() <<"! "<<endl;
    this->health = this->health - (damage);

    if(this->health <= 0){
      this->health = 0;
      cout << this->name <<" has been defeated by "<< attacker<< "!"<<endl;

    }else if(this->health >0 && this->health <=100){
      cout << this->name <<" has been damaged by the fight!"<<endl;
    }else if(this->health >100){
      cout << this->name <<" is almost unscathed and is ready to fight!"<<endl;
    }
    cout << "Angel health level: "<< this->health<<endl;
  }
  void angelAppeared(){
    angeliTotali++;
    cout <<endl<< "Warning! Code blue! It's an Angel! "<<endl;
    cout << "Angel name: "<< this->name<<endl;
    cout << "Angel number: "<< this->number<<endl;
    cout << "It is... "<< this->shape<<endl;
    cout << "Health at " <<this->health<<endl;
    cout << "Preparing countermeasures!"<<endl<<endl;
  }
  void angelAttack(Eva &evang){
    cout <<"Angel " <<this->number <<" prepares its attack!"<<endl;
    cout << this->name << " attacks "<< evang.getPilot <<"!"<<endl;
    int attack = rand()%(int)(health-((double)health/2));
    cout << "It has a damage of"<< attack <<endl;
  }
};
int Angel::angeliTotali = 0;
class Eva{
static int turni;
private:
  int number;
  string pilot;
  string colour;
  string weapons;
  int synchLevel;
public:
  Eva(int num, string pil, string col, string weap, int syncc){
    this->number = num;
    this->pilot = pil;
    this->colour = col;
    this->weapons = weap;
    this->synchLevel = syncc;
  };
  int getNumber(){
    return this->number;
  }
  string getPilot(){
    return this->pilot;
  };
  string getColour(){
    return this->colour;
  };
  string getWeapons(){
    return this->weapons;
  };
  int getSynchLevel(){
    return this->synchLevel;
  };
  void attackAngel(Angel &enemy){
    int attacking = this->synchLevel + (rand()%200)-(rand()%100);

    cout << endl<< this->pilot << "'s "<<this->colour <<" Eva attacks the angel! "<<endl;
    cout << attacking << " damage has been inflicted!!"<<endl;
    if(attacking>100){
    cout << "Nice shot!"<<endl;
    int bonus = round((double)attacking /10);
    synchEdit(bonus);
    }
    enemy.angelDamaged(this->pilot, attacking);
    aumentoTurni();
    if(turni>=3){
      azzeroTurni();
      cout << "Adesso tocca all'Angelo!"<<endl;

      enemy.angelAttack(*this);

    }
  };
  static void azzeroTurni(){
    turni = 0;
  }
  static void aumentoTurni(){
    turni++;
  }
  void synchEdit(int modified){
    if(modified>=0){
      cout << "Synch level has increased by " << modified<<"!"<<endl;
    }else if(modified<0){
      cout << "Synch level has decreased by "<<modified<<"!"<<endl;
      if(this->synchLevel > 0 && this->synchLevel<=30){
        cout << "Warning! Synchronization levels are dropping."<<endl;
      }
    }
    this->synchLevel = synchLevel + modified;
    cout << "Synch level is now "<< this->synchLevel <<"."<<endl;
  };
};
int Eva::turni = 0;
