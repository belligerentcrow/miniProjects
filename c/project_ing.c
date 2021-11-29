#include <stdio.h>
 

int main()
{
    char str[];
    int letters, i;

    letters = i = 0;

   
    printf("\nEnter any english verb: ");
    scanf("%s", &str);


    while(str[i]!='\0')
    {
        if(str[i]>='a' && str[i]<='z')
        {
            letters++;
        }
        i++;
    }
    if((str[letters-3]=='e' && str[letters-2]== 'e') || (str[letters-2]== 'e' && str[letters-1]== 'e')){
        str[letters] = 'i';
        str[letters+1] = 'n';
        str[letters+2] = 'g';
        printf("%s",str); // caso "see" e "bleed"
        return 0;
    }
    else if(str[letters-2]== 'i' && str[letters-1]== 'e'){
        str[letters-2] = 'y';
        str[letters-1] = 'i';
        str[letters] = 'n';
        str[letters+1] = 'g'; 
        printf("%s",str); //caso "die"
        return 0;
    }
    else if(str[letters-1] =='y' || str[letters-1]=='x' || str[letters-1]=='w'){
        str[letters] = 'i';
        str[letters+1] = 'n';
        str[letters+2] = 'g';
        printf("%s",str); // caso "draw" e "hex" e "key"
        return 0;
    }
   
    else if(str[letters-3]=='e' && str[letters-2]=='a'){
        str[letters] = 'i';
        str[letters+1] = 'n';
        str[letters+2] = 'g';
        printf("%s",str); // caso "read"
        return 0;
    }
    else if(str[letters-2]=='e' && (str[letters-1]=='r' || str[letters-1]=='n')){
        str[letters] = 'i';
        str[letters+1] = 'n';
        str[letters+2] = 'g';
        printf("%s",str); // caso "answer" e "happen"
        return 0;
    }
    else if((str[letters-3]!= 'a' || str[letters-3]!= 'e' || str[letters-3]!= 'i'|| str[letters-3]!= 'o'|| str[letters-3]!= 'u' )&&( str[letters-2]== 'a' ||str[letters-2]== 'e' || str[letters-2]== 'i' || str[letters-2]== 'o' || str[letters-2]== 'u') && (str[letters-1]!= 'a' || str[letters-1]!= 'e' || str[letters-1]!= 'i' || str[letters-1]!= 'o' || str[letters-1]!= 'u')){
        
        char cons;
        cons = str[letters-1];
        str[letters] = cons;
        str[letters+1] = 'i';
        str[letters+2] = 'n';
        str[letters+3] = 'g';
        printf("%s",str); // caso "run" o "stop"
        return 0;
    }
    else if(str[letters-1] == 'e' ){
        str[letters-1] = 'i';
        str[letters] = 'n';
        str[letters+1] = 'g';
        printf("%s",str); // caso "dance"
        return 0;
    }
    else {
        str[letters] = 'i';
        str[letters+1] = 'n';
        str[letters+2] = 'g';
        printf("%s",str); // default (caso "punch")
        return 0;
    }
}
