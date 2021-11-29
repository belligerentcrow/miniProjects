#include <stdio.h>

int main() {
    printf("Battaglia navale!!\n Inserisci prima la riga e poi la colonna. Il reticolo è 5x5.\n Per visualizzare il campo di battaglia, inserisci 8 due volte.\n ");
    
    int const rows = 5;
    int const columns = 5;
    int arrayBattlefield[rows][columns]= {
      {0,0,1,0,0},
      {1,0,1,0,0},
      {1,0,0,1,0},
      {0,0,0,0,1},
      {1,0,0,1,0},
    };
    
    int const rows_hid = 5;
    int const columns_hid = 5;
    char arrayBattlefieldHid[rows_hid][columns_hid]= {
      {'?','?','?','?','?'},
      {'?','?','?','?','?'},
      {'?','?','?','?','?'},
      {'?','?','?','?','?'},
      {'?','?','?','?','?'},
    };
    do{
        printf("\nInserisci la coordinata della RIGA e della COLONNA del posto che vuoi BOMBARDARE!");
        int i, j;
        scanf("%d  %d", &i,&j);
        i= --i;
        j= --j;
        if(arrayBattlefield[i][j]==1)
        {
        arrayBattlefield[i][j]=0;
        printf("colpito!\n");
        arrayBattlefieldHid[i][j]= 'X';
        }

        else if(arrayBattlefield[i][j]==0)
        {
        printf("acqua!\n");
        arrayBattlefieldHid[i][j]= 'O';
        }
        
        if(i == 7 && j == 7){
            for(int h = 0; h < rows; h++)
            {
                for(int k = 0; k < columns; k++)
                {
                    
                    printf("%c\t", arrayBattlefieldHid[h][k]);
                }
                
            printf("\n");
            }
        
        }
            
 
    }while (arrayBattlefield[0][2] == 1 ||  arrayBattlefield[1][0] == 1 || arrayBattlefield[1][2] == 1 || arrayBattlefield[2][0] == 1 || arrayBattlefield[2][3] == 1 ||  arrayBattlefield[3][4] == 1 || arrayBattlefield[4][0] == 1 || arrayBattlefield[4][3] == 1);

        if(arrayBattlefield[0][2] == 0 ||  arrayBattlefield[1][0] == 0 || arrayBattlefield[1][2] ==0 || arrayBattlefield[2][0] == 0 || arrayBattlefield[2][3] == 0 ||  arrayBattlefield[3][4] == 0 || arrayBattlefield[4][0] == 0 || arrayBattlefield[4][3] == 0){printf("Tutte le navi sono affondate!\n");
        for(int h = 0; h < rows; h++){
        for(int k = 0; k < columns; k++){
            printf("%c\t", arrayBattlefieldHid[h][k]);}
            printf("\n");
        }
        
    }
        return 0;
        
}
 
 
 
 
