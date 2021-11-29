#include <iostream>
#include <cmath>
using namespace std; 

void divisibileper(int numero, int * arrayDivisori, bool * risultato){
		cout <<"Calcolo per " << numero<<"..." <<endl<<endl; 
		
		
	       for(int i = 0; i < 10; i++){	
		if(numero%arrayDivisori[i]==0){
			risultato[i] = 1; 
		}
	       }
	       
}

void stampa(int numero, int * arrayDivisori, bool * risultato){
	for(int i = 0; i < 10; i++) {
	
	cout << numero << (risultato[i]==0? " non ":"")<< " è divisibile per " << arrayDivisori[i] <<endl;   
	
	}
}

int main(){
	int divisori[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; 
	bool risultato[10] = {};
	int N; 
	cout<< "Inserisci un numero intero: ";
	cin >> N;

	divisibileper(N, divisori, risultato);
	stampa(N, divisori, risultato); 
}
