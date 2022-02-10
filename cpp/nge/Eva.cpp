#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// class Eva; //questa linea non risolve il problema del metodo angelAttack();

class Angel{
static int angeliTotali; //variabile static comune a tutte le istanze
private:
  string name;
  int number;
  string shape;
  int health;
public:

  //costruttore + overloading costruttore
  Angel(string itsName, int itsNumber, string itsShape, int itsHealth){
    this->name = itsName;
    this->number = itsNumber;
    this->shape = itsShape;
    this->health = itsHealth;
    cout <<endl <<"Creating angel"<<endl;
    angelAppeared();
  };
  Angel(string itsName){
    this->name = itsName;
    this->number = angeliTotali+1;
    this->shape = "an average Angel.";
    this->health = 500;
    cout <<endl<<"Creating angel (overload1)"<<endl;
    angelAppeared();
    }
  Angel(){
    this->name = "NoName";
    this->number = angeliTotali+1;
    this->shape = "a totally average Angel.";
    this->health = 450;
    cout <<endl<<"Creating angel (overload2)"<<endl;
    angelAppeared();
  }

  //getters
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

  //quando viene attaccato da un Eva
  void angelDamaged(string attacker, int damage){
    cout << attacker << " has damaged the angel number"<< this->getAngelNumber() <<"! "<<endl;
    this->health = this->health - (damage);

    if(this->health <= 0){
      this->health = 0;
      cout << this->name <<" has been defeated by "<< attacker<< "!"<<endl;
      delete this;
    }else if(this->health >0 && this->health <=100){
      cout << this->name <<" has been damaged by the fight!"<<endl;
    }else if(this->health >100){
      cout << this->name <<" is almost unscathed and is ready to fight!"<<endl;
    }
    cout << "Angel health level: "<< this->health<<endl;
  }

  //quando appare per la prima volta
  void angelAppeared(){
    angeliTotali++;
    cout <<endl<< "Warning! Code blue! It's an Angel! "<<endl;
    cout << "Angel name: "<< this->name<<endl;
    cout << "Angel number: "<< this->number<<endl;
    cout << "It is... "<< this->shape<<endl;
    cout << "Health at " <<this->health<<endl;
    cout << "Preparing countermeasures!"<<endl<<endl;
  }

  //quando è il suo turno - problemi!!! (metodo sottostante angelAttack)
  //error : invalid use of incomplete type ‘class Eva’
  //messo evang come reference perché il metodo cambierà un parametro
  //dell'oggetto evang (abbasserà il synchLevel)

/*  void angelAttack(Eva &evang){
    cout <<"Angel " <<this->number <<" prepares its attack!"<<endl;
    cout << this->name << " attacks "<< evang.getPilot <<"!"<<endl;
    int attack = rand()%(int)(health-((double)health/2));
    cout << "It has a damage of"<< attack <<endl;
  }
*/

};
int Angel::angeliTotali = 0; //da inizializzare fuori dalla classe
class Eva{
static int turni;
static int evaSeries;
private:
  int number;
  string pilot;
  string colour;
  string weapons;
  int synchLevel;
public:
  friend void stampaParametri(Eva);
  //costruttore + overloads
  Eva(int num, string pil, string col, string weap, int syncc){
    this->number = num;
    this->pilot = pil;
    this->colour = col;
    this->weapons = weap;
    this->synchLevel = syncc;
    evaSeries++;
    stampaParametri(*this);
    };
  Eva(string pil, int syncc = 20){
    this->number = evaSeries+1;
    this->pilot = pil;
    this->colour = "Silver";
    this->weapons = "Knife";
    this->synchLevel = syncc;
    evaSeries++;
    stampaParametri(*this);
  }
  Eva(){
    this->number = evaSeries+1;
    this->pilot = "[CLASSIFIED]";
    this->colour = "Metal";
    this->weapons = "Gun";
    this->synchLevel = 0;
    evaSeries++;
    stampaParametri(*this);
  }

  //getters
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

  //quando un Eva attacca un angelo
  void attackAngel(Angel &enemy){
    //attacco influenzato dal synch level ma anche randomico
    //da ricercare in futuro un sistema migliore
    //perché talvolta l'output può essere negativo
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
        //questa parte non funziona a causa dell'error del compilatore
      cout << "Now it's the opponent's turn!"<<endl;
     //enemy.angelAttack(*this); //dereferenzio il puntatore all'oggetto stesso
                                //per passare by reference?
    }

  };

  //funzioni static che lavorano con il parametro static
  static void azzeroTurni(){
    turni = 0;
  }
  static void aumentoTurni(){
    turni++;
  }
  void synchEdit(int modified){
    if(modified>=0){
      cout << "Synch level has increased by " << modified<<"!"<<endl;
      this->synchLevel = synchLevel + modified;
      cout << "Synch level is now "<< this->synchLevel <<"."<<endl;
    }else if(modified<0){
      cout << "Synch level has decreased by "<<modified<<"!"<<endl;
      if(this->synchLevel > 0 && this->synchLevel<=30){
        this->synchLevel = synchLevel + modified;
        cout << "Synch level is now "<< this->synchLevel <<"."<<endl;
        cout << "Warning! Synchronization levels are dropping."<<endl;
      }else if(this->synchLevel <= 0){
        cout << "The synchronization has dropped to zero!!! Disconnecting..."<<endl;

      }
    }


  };
};
int Eva::turni = 0; //da inizializzare fuori dalla classe
int Eva::evaSeries = 0;

void stampaParametri(Eva whichEva){
  cout <<endl<< "Getting data..."<<endl<<endl;
  cout << "Eva number: "<< whichEva.getNumber()<<endl;
  cout << "Eva pilot: "<< whichEva.getPilot()<<endl;
  cout << "Eva colour: "<<whichEva.getColour()<<endl;
  cout << "Eva weapons: "<<whichEva.getWeapons()<<endl;
  cout << "Synchronization rate: "<<whichEva.getSynchLevel()<<endl;

  if(whichEva.getSynchLevel()>=80&&whichEva.getSynchLevel()<100){
    cout <<endl<< "This pilot is very synchronized with its Eva."<<endl;
  }else if(whichEva.getSynchLevel()>=100&&whichEva.getSynchLevel()<150){
    cout << endl<< "This pilot is perfectly synchronized with its Eva."<<endl;
  }else if(whichEva.getSynchLevel()>150){
    cout << endl<< "Synchronization levels are reaching critical values."<<endl;
    cout << "Warning. Possible Berserk activity detected."<<endl;
  }else if(whichEva.getSynchLevel()<=30){
    cout << endl << "Uh oh! Synchronization levels are dropping."<<endl;
  }
};

int main(){
  srand(time(0));
  cout << "Initialization..."<<endl;
  cout << "Creating EVA."<<endl;

  Eva n00(0, "Rei Ayanami", "Blue", "Knife", 60); //pilota 1
  //stampaParametri(n00);

  Eva n02("Soryuu Asuka Langley"); //pilota 2
  //stampaParametri(n02);

  Eva n03; //pilota 3
  //stampaParametri(n03);

  Angel Raphael("Raphael", 1, "kinda monster-y", 500); //creo il primo angelo
  //Angel Gabriel("Gabriel");
  //Angel Michael;

  n00.attackAngel(Raphael);
  n02.attackAngel(Raphael);
  n03.attackAngel(Raphael);


}
