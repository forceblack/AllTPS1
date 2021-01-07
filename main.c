#include <stdio.h>
#include "Chapitre2_TypesDeVariables.h"
#include "Chapitre4_Graphique.h"
#include "Chapitre5_StructuresDeControle.h"
#include "Chapitre5_Grapheur.h"
#include "Chapitre7_LesTableaux.h"

int main()
{
    printf("Bienvenu dans le programme TD info GEII S1\n");
    printf("Pour voir le chapitre 1, tapez 1\n");
    printf("Pour voir le chapitre 2, tapez 2\n");
    printf("Pour voir le chapitre 3, tapez 3\n");
    printf("Pour voir le chapitre 4, tapez 4\n");
    printf("Pour voir le chapitre 5, tapez 5\n");
    printf("Pour voir le chapitre 6, tapez 6\n");
    printf("Pour voir le chapitre 7, tapez 7\n");
    printf("Pour voir le chapitre 8, tapez 8\n");
    printf("Pour voir le chapitre 9, tapez 9\n");

    int Answer1=0;
    int Answer2=0;
    scanf("%d",&Answer1);

    switch (Answer1)
    {
       case 1 :
       printf("C'est le chapitre ou on installe QTCreator\n");
       break;

    //chapitre 2...............Types de Variables
       case 2 :
       typeDeVariable();
       break;

    //chapitre 3 ...pas fait
       case 3 :
       printf("pas fait\n");
       break;

    //chapitre 4 ..............bibliotheque graphique Xgeii ou plutot EZ-Draw
       case 4 :
       Chap4_Graph1();
       break;

    //chapitre 5................Structure de Controle
       case 5 :
        printf("partie 1 struct de controle\n"
               "partie 2 lib graphique\n");
        scanf("%d",&Answer2);
        switch(Answer2)
        {
            case 1:
            Chap5_StructuresDeControle();
            break;

            case 2:
            Chap5_Graph();
            break;
        }
       break;

    //chapitre 6 ...............Les Fonctions pas fait
        case 6 :
        printf("pas fait\n");
        break;

    //chapitre 7..............Les Tableaux
       case 7:
        printf("partie 1 tableau et tri a bulle\n"
               "partie 2 pyramide des ages\n");
        scanf("%d",&Answer2);
        switch(Answer2)
        {
            case 1:
            Chap7_Tableau();
            break;

            case 2:
            Chap7_Pyramide();
            break;
        }
       break;


        //chapitre 8 ...pas fait
         case 8 :
         printf("pas fait\n");
         break;


         //chapitre 9 ...Les chaines de caracteres
            case 9 :
            Chap9_String();
            break;
    }
    return 0;
}


