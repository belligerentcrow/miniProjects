//Calcolare l'ipotenusa di un triangolo rettangolo!
// UPDATE!! Formule inverse! Prima ti chiede che cosa vuoi calcolare.
//user_answ è il tipico menu da segreteria telefonica "DIGITA 1 / DIGITA 2" etc
// c1 / c2 -> cateto da fare
// _2 / _3 / _1 dopo c1/c2/ipoten-> quale delle user_answ stai usando
// (non so se mettere variabili attribuite allo stesso nome in "ifs" diversi possa risultare in complicazioni)


#include <stdio.h>
#include <math.h>

int main() {
   printf("Questo programma calcola i lati di un triangolo rettangolo.");
   int user_answ;
   printf("\nSe vuoi calcolare il cateto minore, inserisci 1.\n Se vuoi calcolare il cateto maggiore, inserisci 2. \nSe vuoi calcolare l'ipotenusa, inserisci 3. \n");
   scanf("%i", &user_answ);
   if(user_answ == 3){
        double c1_3;
        printf("\nInserire valore del primo cateto: ");
        scanf("%lf", &c1_3);

        double c2_3;
        printf("\n Inserire valore del secondo cateto: ");
        scanf("%lf", &c2_3);
   
        double ipoten_3;
        ipoten_3 = sqrt(pow(c1_3,2)+pow(c2_3,2));
        printf("\nIl valore dell'ipotentusa del triangolo è...%lf", ipoten_3); 
   }
   
   else if(user_answ == 2){
        double ipoten_2;
        printf("\nInserisci il valore dell'ipotenusa: ");
        scanf("%lf", &ipoten_2);
        
        double c1_2;
        printf("\nInserisci il valore del cateto minore: ");
        scanf("%lf", &c1_2);
        
        double c2_2;
        c2_2 = sqrt(pow(ipoten_2,2)-pow(c1_2,2));
        printf("\nIl valore del cateto maggiore è...%lf", c2_2);
   
   }
   else if(user_answ == 1){
        double ipoten_1;
        printf("\nInserisci il valore dell'ipotenusa: ");
        scanf("%lf", &ipoten_1);
        
        double c2_1; 
        printf("\n Inserisci il valore del cateto maggiore: ");
        scanf("%lf", &c2_1);
        
        double c1_1;
        c1_1 = sqrt(pow(ipoten_1,2)-pow(c2_1,2));
        printf("\n Il valore del cateto minore è...%lf", c1_1);
   }
   else{ 
       printf("\nNon ho compreso il comando. \nSe vuoi calcolare il cateto minore, inserisci 1.\n Se vuoi calcolare il cateto maggiore, inserisci 2. \nSe vuoi calcolare l'ipotenusa, inserisci 3.\n Ripetere l'operazione."); 
       
   }
   printf("\nGrazie e arrivederci!");
}
