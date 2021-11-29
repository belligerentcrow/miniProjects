#include <iostream>
#include <cmath>
using namespace std; 



int main(){
int N = 0; 	//il numero fino al quale trovare primi
short count = 0; 	//serve sia a contare il prossimo p per il quale dividere, che eventualmente a stampare 
int p = 2;		  		
cout << "Inserisci il numero intero >2 fino al quale devo contare i primi." <<endl; 
cin >> N;
int radN = sqrt(N); //smette di cercare primi oltre radiceDiN perché se p|N allora p|radicediN quindi sarebbe lavoro in più
int matrice[N]={}; //la chiamo matrice ma è un array, semplicemente nelle stampe commentate esce come matrice per gli endline	
for(int i = 0; i<N-1; i++){
	matrice[i] = i+2;	//inizializzo l'array di primi. forse dovrei rinominarlo
}
//cout << "Matrice iniziale" <<endl<<endl;  //decommentare per stampare la matrice iniziale.  
/*for(int i=0; i<N; i++){			//(sconsigliato per numeri grandi, fa crashare il terminale e
cout<< "|" << matrice[i] << "|\t";		// interrompe di botto il programma) 
if(count==10){
	count=0; 
	cout <<"\n";
}
count++; 
}
 */
while(p<=radN){		// minore uguale perché l'ultimo primo potrebbe essere N stesso
//cout << "\nCrivello, divido per "<< p << "\n\n"; 
//count = 0; 		//azzero count che serve in caso di stampa
for(int i=0; i<N-1; i++){
	if(matrice[i]%p==0&&matrice[i]!=p){	 
	matrice[i] = 0;			// qua scrivella via i non-primi, ovvero i divisibili per p 
	 
	}
	//cout <<"|" << matrice[i] << "|\t"; 
	//if(count==10){
	//count=0; 
	//cout <<"\n"; 
	//}
	//count++; 
}
count = p-1; 
while(count!=0){
	if(matrice[count]!=0){
		p= matrice[count];	//p diventa il prossimo primo non scrivellato
		count = -1; //così l'incremento successivo lo porta a zero facendolo uscire dal while
	}
	count++; 
}

short primi = 0; //conto quanti sono. uno short è sufficiente per numeri relativamente piccoli 
if(p>radN){
	cout << "\nMassimo valore di P raggiunto. P =" << p <<endl; //ultimo valore assegnato a p. non necessariamente l'ultimo per il quale ho diviso 
	cout << "Crivello ultimato: "<<endl; 

	for(int i =0; i<N-2; i++){
		if(matrice[i]!=0){	//setaccio la matrice 
		cout << matrice[i]<< ", "; // stampo quelli non nulli ovvero levo gli scrivellati
		primi ++; 		//aumento il contatore di primi
		}
	}
	cout << "I primi trovati sono: " << primi <<endl; //stampo il contatore di primi ovvero quanti primi ho trovato nell'intervallo 2 - N
}
}
}
