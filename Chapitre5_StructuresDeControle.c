#include <stdio.h>
#include <math.h>
#include "Chapitre5_StructuresDeControle.h"


void Chap5_StructuresDeControle(void)
{
     int inKeyboard;
     do{
             printf("pour afficher une table de multiplication tapez 1\n"
                      "pour jouer au jeu des multiplications, tapez 2\n");
             scanf("%d",&inKeyboard);
        }while ((inKeyboard != 1) && (inKeyboard != 2));

     switch (inKeyboard)
     { case 1 : MultiplyTable(); break;
       case 2 : MultiplyGame(); break ;
     }

    return;
}



//fonction pour entrer un chiffre pour les tables de multiplication ou la jeu

int enterMultiplier()
{
    int multiplier ;
    do{
        printf ("Entrez une valeur entre 1 et 10\n");
        scanf ("%d",&multiplier);
        if (multiplier < 0)
            {
            printf ("veuillez saisir un nombre plus grand\n");
            }
        if (multiplier > 10)
            {
            printf ("veuillez saisir un nombre plus petit\n");
            }
        }while ((multiplier <= 0) || (multiplier >= 10));

    return multiplier;
}


void MultiplyTable ()
{
    int i, result=0;
    int M = enterMultiplier();
    for (i=1; i<11 ; ++i)
    {
        result = M * i;
        printf("%d x %d = %d \n",M,i,result);
    }
    return ;
}

void MultiplyGame()
{
    int M = enterMultiplier();
    printf("bienvenu dans le jeu des tables de multiplications\n");

    int result ,check , error = 0;

    int i;
    for (i=1; i<11 ; ++i)
    {
        check = 1 ;
        do{
        printf("%d x %d = ",M,i);
        scanf("%d",&result);
        check = checkMultiply(M,i,result,&error);
        }while(check == 1);
    }
    printf ("fin du jeu\n");
    printf ("vous avez fait %d erreur(s)\n",error);

    return ;
}


//fonction de verification d'un résultat avec retour booleen et un compteur en pointeur
int checkMultiply(int M1,int M2,int result,int *error)
{
    if (M1 * M2 == result)
    {
        printf("bien \n");
        return 0;
    }
    else
    {
         printf("faux, recommencez \n)");
         *error=*error + 1;
        return 1;
    }
}
