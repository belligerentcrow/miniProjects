#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main(){
	string messaggio;
       	char littera = 'a';
	int chiave = 0; 	
  	cout << "Inserisci un testo"<<endl; 
  	getline(cin, messaggio);
	cout << "Inserisci una chiave shift" <<endl; 
	cin >> chiave; 
	for(int i = 0; i<messaggio.length(); i++){
		if(messaggio[i]!=' '){
		littera = messaggio[i];
		littera = int(littera);
		littera = littera+chiave;
		littera = char(littera);
	       	messaggio[i] = littera; 
		}
	}
	cout << messaggio <<endl; 
} 
