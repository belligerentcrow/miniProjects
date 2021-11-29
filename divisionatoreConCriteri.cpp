#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
using namespace std; 

bool primo(int N){
	int p = 2;
	int isitprime = 0; 
	while(p <N){ 
		if(N%p==0){ 
		isitprime++;  	
		}
	p++; 
	}
	if(isitprime==0){
		return 1; 
	}else{
		return 0; 
	}
}

bool per2(int N){
	stringstream ss;
       	ss << N; 
	string frase;
       	ss >> frase;
	char lettera = frase[frase.length()-1];	
 	if((lettera=='0')||(lettera=='2')||(lettera=='4')||(lettera=='6')||(lettera=='8')){
	return 1;
	}else{
	return 0;
	} 	
}
bool per3(int N){
	stringstream ss; 
	string frase; 
	ss <<N;
       	ss >>frase; 	
	short somma = 0; 
	short i = 0;
       	stringstream ss2;
	int intermedio = 0; 	
	while(i<ss.str().size()){
		ss2 << frase[i];
		ss2 >>intermedio;
		somma = somma+ intermedio;
		i++; 
		ss2.clear(); 
	}
	if(somma%3==0){
	return 1;
	}else{
	return 0;
	}	
}
bool per5(int N){
	stringstream ss; 
	string frase; 
	ss << N;
       	ss >> frase; 	
	char lettera= frase[frase.length()-1]; ;
	if((lettera=='5')||(lettera=='0')){
		return 1; 
	}else{
		return 0;
	}

}

bool per7(int N, int q, int r){
	
	if((q-(2*r))%7==0){
		return 1; 
	}else{
	return 0; 
	}
}

bool per9(int N){
	stringstream ss; 
	string frase;
	ss << N; 
	ss >>frase; 
	short ultimalett = frase.length(); 
	int somma = 0; 
	int i=0; 
	int intermedio=0; 
	stringstream ss2; 
	while(i<ultimalett){
	ss2 << frase[i];
	ss2 >> intermedio; 
	somma = somma + intermedio;	
	i++; 
	ss2.clear(); 
	}
	if(somma%9==0){
		return 1;
	}else{
		return 0; 
	}
}

bool per11(int N){
	stringstream ss;
       	string frase; 	
	ss << N; 
	ss >> frase;
	short ultimalett = frase.length(); 
	short i = 0;
       	int sommapari = 0, sommadispari = 0; 	
	while(i < ultimalett){
		switch(i%2){
		 	case 0: 
			sommapari = sommapari + (int)frase[i];
			break; 
			case 1:
			sommadispari = sommadispari + (int)frase[i]; 
			break; 
		}
	i++;
       	}
	if((sommapari-sommadispari)%11==0){
		return 1;
	}else{
		return 0;
	}	
}
bool per13(int N, int q, int r){
	 
	if((q+(4*r))%13==0){
		return 1;
	}else{
		return 0;
	}	
}
bool per17(int N, int q, int r){
	 
	if((q-(5*r))%17==0){
		return 1;
	}else{
		return 0;
	}	
}

bool per23(int N, int q, int r){
	
	if((q+(7*r))%23==0){
		return 1; 
	}else{
		return 0; 
	}
}

void divisibileper(int numero, int * arrayDivisori, bool * risultato){
		cout <<"Calcolo per " << numero<<"..." <<endl<<endl; 
		
		int quoziente = numero/10; 
		int resto = numero%10; 
		

		risultato[0] = per2(numero);
		risultato[1] = per3(numero);	
	       	risultato[2] = per5(numero);
		risultato[3] = per7(numero, quoziente, resto);
 		risultato[4] = per9(numero);
		risultato[5] = per11(numero);
	       	risultato[6] = per13(numero, quoziente, resto); 	
		risultato[7] = per17(numero, quoziente, resto); 
		risultato[8] = per23(numero, quoziente, resto);
				
}

void stampa(int numero, int * arrayDivisori, bool * risultato){
	if(primo(numero)==1){
		cout << numero << " è un numero primo. " <<endl; 
	}
	for(int i = 0; i < 9; i++) {
		if(risultato[i]==1){
			cout << numero << " è divisibile per "<<arrayDivisori[i]<<endl;
		}
	}
}

int main(){
	 
	int divisori[10] = {2, 3, 5, 7, 9, 11, 13, 17, 23, 29}; 
	bool risultato[10] = {};
	int N; 
	cout<< "Inserisci un numero intero: ";
	cin >> N;

	divisibileper(N, divisori, risultato);
	stampa(N, divisori, risultato); 
}
