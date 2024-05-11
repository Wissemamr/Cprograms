#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Programme analyseur syntaxique : AUTOMATE A ETATS FINIS (FSM)
//Recupere la colonne de la matrice de transition du AEF
int getcol(char c) {
if (c=='l') return 0;
    else if (c=='s') return 1;
        else if(c=='e') return 2;
            else if (c=='r') return 3;
                else if (c=='q') return 4 ;
                    else return -1 ;


/*La matrice
    0|1 |2 |3 |4
    e|s |e |r |q |
 0|1 |-1|-1|-1|-1|
 1|-1| 2|-1|3 |4 |
 2|-1|-1| 1|-1|-1|
 3|-1|-1| 1|-1|-1|
 4|-1|-1|-1|-1|-1|
*/

}
int main()
{
    int matrice[5][5]={ {1, -1, -1, -1}, {-1,2,-1,3,4}, {-1,-1,1,-1,-1}, {-1,-11,-1,-1} };
    char sequence[50];
    scanf("%s", &sequence);
    int i=0;
    int ec=0; //current state
    while(  (i<strlen(sequence))&&((getcol(sequence[i]))!=-1)&&( (matrice[ec][getcol(sequence[i])] )!=-1 ) ) {
        ec=matrice[ec][getcol(sequence[i])];
        i++;
        }
        if (i==strlen(sequence) && ec==4) {
            printf("La sequence respect la politique de P1 \n");
                                          }
        else {printf("La séquence ne respecte pas la politique de P1 \n");
             }
    return 0;
}
