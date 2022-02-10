#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//strumento per un numero casuale double tra fmin e fmax
double fRand(double fMin, double fMax){
  double f = (double)rand()/RAND_MAX;
  return fMin + f *(fMax - fMin);
}

class Singer{
private:
  string name;
  double rating;
  int numAlbums;
  string* albumNames = new string;

public:
  //constructors
  Singer(string nme, double rate){
    this->name = nme;
    this->rating = rate;
    this->numAlbums = 0;
  }
  Singer(string nme){
    this->name = nme;
    this->rating = 5.0;
    this->numAlbums = 0;
  }

  //generic public methods
  void goOnTour(){
    srand(time(0));
    cout << this->name << " has gone on tour!"<<endl;
    double x = fRand(0, 3);
    this->rating += x;
    cout << this->name << "'s popularity rises..."<<endl;
    cout << " + "<< x << "!"<<endl;

  }
  void present(){
    cout << "Today's artist is..." << this->name << "!"<<endl;
    cout << "They have " << this->numAlbums << " albums to their name."<<endl;
    cout << "Their overall rating is "<< this->rating <<endl;

  }
  void addAlbum(string albname){
    this->albumNames[numAlbums] = albname;
    this->numAlbums += 1;
    cout << this->name << " has made "<< this->numAlbums << " albums now."<<endl;
  }

  //getters
  string getName(){
    return name;
  }
  double getRating(){
    return rating;
  }

  //friends
  friend ostream & operator<< (ostream &s, Singer &sing);
};

class Album{
private:
  int numTracks;
  string * tracksNames = new string;
  string name;
  Singer author;
  double price;
  int copiesSold;
public:
  //constructors
  Album(string title, Singer &auth) : author(auth){
    this->numTracks = 0;
    this->name = title;
    this->author = auth;
    this->copiesSold = 0;
    calcPrice();
    auth.addAlbum(title);
  }

  //generic public
  double gain = 0.0;
  void sell(int cop){
      cout << cop << " copies have been sold right now!"<<endl;
      for(int i = 0; i < cop; i++){
      this->gain += getPrice();
      }
      this->copiesSold += cop;
      cout << this->name << "'s gain is now " << this->gain<<endl;
  }
  void calcPrice(){
    this->price = (this->author.getRating() * 2) + 3;
  }
  void present(){
    cout << "Today's album is "<< this->name <<", by "<< this->getNameSinger()<<"!"<<endl;
    cout << "It has "<< this->numTracks << " tracks."<<endl;
    cout << "It costs "<< this->price << " golds."<<endl;
    cout << "It has sold "<< this->copiesSold <<" copies, and the total gain up to now has been "<<this->gain<<" golds."<<endl;
  }
  void addSongToAlbum(string songname){
    this->tracksNames[numTracks] = songname;
    this->numTracks += 1;
    cout << songname << " has been added to "<< this->name << "!";
  }

  //getters
  int getTracks(){
    return numTracks;
  }
  string getName(){
    return name;
  }
  double getPrice(){
    return price;
  }
  string getNameSinger(){
    return this->author.getName();
  }

  //friends
  friend ostream & operator<< (ostream &s, Album& alb);
};

class Song{
private:
  double songLength;
  string songTitle;
  Album songsAlbum;
public:
  Song(double lng, string name, Album&albmm) : songsAlbum(albmm){
    this->songLength = lng;
    this->songTitle = name;
    this->songsAlbum = albmm;
    albmm.addSongToAlbum(name);
  }

  //getters
  double getSongLength(){
    return this->songLength;
  }
  string getSongTitle(){
    return this->songTitle;
  }
};

//overloading operatori
ostream & operator<< (ostream &s, Album& alb){
  s << alb.getName() << " by "<< alb.getNameSinger();
  return s;
}
ostream & operator<< (ostream &s, Singer& sing){
  s << sing.getName() << ", " << sing.getRating();
  return s;
}

int main(){
  Singer Ado("Ado", 5);
  Album Kyougen("Kyougen", Ado);
  Kyougen.sell(20);
  cout << endl;
  Song Usseewa(3.0, "Usseewa", Kyougen);
  Song Dance(4.30, "Dance", Kyougen); 
  cout << endl;
  Kyougen.present();
  Ado.goOnTour();
  Ado.goOnTour();
  Ado.present();

  //prova overloading operatori <<
  cout << endl;
  cout << Ado<<endl;
  cout << Kyougen <<endl;
}
