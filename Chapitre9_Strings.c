#include "Chapitre9_Strings.h"
#include <stdio.h>
#include <string.h>


void Chap9_String()
{
    //entreFirstName();
    resistorValue();
    return;
}

void entreFirstName()
{
    //saisie et affichage d'une chaine de caractere
    char prenom[10];
    printf("entrer votre prenom\n");
    scanf("%s",prenom);
    printf("le prenom entre est : %s\n",prenom);
    return;
}


void resistorValue()
{
    char tabcodecoul[10][7]={"noir",
                             "marron",
                             "rouge",
                             "orange",
                             "jaune",
                             "vert",
                             "bleu",
                             "violet",
                             "gris",
                             "blanc"};

    printColorCode(tabcodecoul,10);

    printf("\nfonction de calcul de valeur de resistance\n");
    printf("entrez la premiere couleur\n");
    char color1[7];
    int index1;
    do{
        scanf("%s",color1);
    }while(checkColor(tabcodecoul,10,color1,&index1) != 1);
    //premiere couleur ok

    printf("entrez la deuxieme couleur\n");
    char color2[7];
    int index2;
    do{
        scanf("%s",color2);
    }while(checkColor(tabcodecoul,10,color2,&index2) != 1);


    printf("l'index 1=%d et l'index 2=%d\n",index1,index2);
    int resValue = 10*index1 + index2;
//    printf("res = %d\n",resValue);

    //test E12
    int tabvalE12[]={10,12,15,18,22,27,33,39,47,56,68,82};
    if (checkE12(tabvalE12,sizeof (tabvalE12)/sizeof (int),resValue) == 1)
        printf("la valeur de la resistance est bien dans E12\n");
    else
        printf("la valeur de la resistance n'est pas dans E12\n");

    return ;
}

void printColorCode (char inTab[][7], int inSize)
{
    for(int i=0 ; i < inSize ; ++i)
    {
        printf("%d : %s\n",i,inTab[i]);
    }
    return;
}

int checkColor (char inTab[][7],int inSize,char *inColor,int *outIndex)
{
    //printf("%s = inColor\n",inColor);
    int bool=0;
    int i=0;
    do{
        //  printf("bool = %d\n",bool);
        if (strcmp(inTab[i],inColor) == 0)
        {
            bool = 1;
            *outIndex=i;
        }
        i++;
    }while((i<inSize) && (bool==0));
    return bool;
}


int checkE12(int *E12Value, int E12Size, int resValue)
{
    int bool = 0;
    int i = 0;
    do{
        if (resValue == E12Value[i])
        {
            bool = 1;
        }
        i++;
    }while((i<E12Size) && (bool==0));

    return bool;
}
