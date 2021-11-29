/*
-fare in modo che non cicli infinitamente se si immette un char

 -magari più avanti si può scegliere il numero (ovvero il "colore")
*/


#include <iostream>

int main() {
  const int m = 8;
  const int n = 8;
  int griglia[m][n] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  };

  bool wrongAttempt = false;
  int userColumn = 0;
  std::cout << "Forza 4!\n";
  std::cout << "Per uscire, scrivi 404. Per stampare la griglia scrivi 777.\n";
  int keepPlaying = 0;

  //keep track of who's playing
  int player = 1;

  while(keepPlaying<3){
    //messaggio di istruzione (non viene visualizzato al primo giro perché c'è quello fuori dal while). il doNotRepeat lo posso usare nelle situazioni in cui non voglio che si visualizzi il messaggio

    if(player==1){
      std::cout << "Giocatore 1: Inserisci un disco in una colonna da 1 a 8.\n";
    }else if(player==2){
     std::cout << "Giocatore 2: Inserisci un disco in una colonna da 1 a 8.\n";
    }


  userColumn = 0;

  /*tu scegli solo la colonna e il numero va automaticamente al posto più basso disponibile (simulando il fatto che i dischetti cadano per la gravità)*/


  std::cin>> userColumn;
  wrongAttempt=false;

  if((userColumn<=8 && userColumn>=1)||userColumn==404||userColumn==777){
      //modo per uscire dal while
      if(userColumn<=8 && userColumn>=1){
        //faccio in modo che l'indice slitti di 1 indietro e che la colonna selezionata dall'utente corrisponda agli indici della matrice
      userColumn--;


      std::cout << "Entro nel loop. numero: "<< userColumn <<"\n";



      //se la colonna è del tutto piena
      if(griglia[0][userColumn]!=0){
         std::cout << "Nope! Colonna piena, prova un'altra colonna.\n";
        }

      //se c'è già un elemento (1) nella colonna allora ciclo finché non trovo un posto vuoto.

      if(griglia[m-1][userColumn]==0){
        if(player==1){
          griglia[m-1][userColumn] = 1;
        } else if (player==2){
          griglia[m-1][userColumn] = 2;
        }
         } else {
      int i = 0;
      while (i<m){
        if(griglia[i][userColumn]!=0){
          if(player==1){
            griglia[i-1][userColumn] = 1;
            break;
          } else if(player==2){
            griglia[i-1][userColumn] = 2;
            break;
          }
          }
        i++;
      }
         }

      //controllo se ci sono dei forza4 vincenti
      int k=0;
          while(k<m){
            int z=0;
              while(z<n){
                if(griglia[k][z]==player&&griglia[k][z+1]==player&&griglia[k][z+2]==player&&griglia[k][z+3]==player){
                  std::cout << "Forza 4 per Giocatore" << player << "! (orizzontale) \n";
                  keepPlaying=8;
                  break;
                }
                else if(griglia[k][z]==player&&griglia[k+1][z]==player&&griglia[k+2][z]==player&&griglia[k+3][z]==player){
                  std::cout <<"Forza 4 per Giocatore "<< player <<"! (verticale) \n";
                  keepPlaying=8;
                  break;
                } else if (griglia[k][z]==player&&griglia[k+1][z+1]==player&&griglia[k+2][z+2]==player&&griglia[k+3][z+3]==player){
                  std::cout << "Forza 4 per Giocatore "<< player <<"! (diagonale) \n";
                  keepPlaying=8;
                  break;
                }
                z++;
              }
            k++;
            }

      }else if(userColumn==777){
        //ciclo che stampa la griglia
          int i=0;
          while(i<m){
            int j=0;
              while(j<n){
                std::cout << " " << griglia[i][j] << " ";
                j++;
              }
            std::cout << "\n";
            i++;
            }
            if(player==1){
              player = 2;
            } else if (player==2){
              player = 1;
            }
    } else {
       std::cout << "bye!\n";
        break;
    }
  } else {
    std::cout << "Input invalido. Prova di nuovo.\n";
    userColumn = 0;
    wrongAttempt = true;
    keepPlaying++;
  }

  if(player==1){
    player = 2;
  } else if (player==2){
    player = 1;
  }
}
if(keepPlaying==3){
  std::cout << "Hai inserito troppi inputs invalidi. Devo kickarti dal gioco finché non trovo un modo per farlo funzionare senza andare in loop infinito. Addio <3";
}else if(keepPlaying==8){
  std::cout << "Congrats! U won! \n";
  int i=0;
          while(i<m){
            int j=0;
              while(j<n){
                std::cout << " " << griglia[i][j] << " ";
                j++;
              }
            std::cout << "\n";
            i++;
            }

}
}
