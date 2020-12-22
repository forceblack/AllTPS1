#include "Chapitre7_LesTableaux.h"
#include "Chapitre7_PyramideData.h"



void Chap7_Tableau()
{
        int tab[NB_ELEMENT];
        f_tabEntry(tab, NB_ELEMENT);

        //declaration d'un moyenne
        float tabAverage = f_averageTab(tab, NB_ELEMENT);


        printf("la moyenne du tableau est : %f\n",tabAverage);
        printf("il y a %d valeurs au dessus de la moyenne \n",f_aboveAverageNumber(tab, NB_ELEMENT,tabAverage));
        printf("il y a %d valeurs au dessous de la moyenne \n",f_belowAverageNumber(tab, NB_ELEMENT,tabAverage));


        //declaration de 2 points (min et max)
        tabPoint minPoint;
        tabPoint maxPoint;

        //recherche des points min et max
        f_findMinTabValue(tab,NB_ELEMENT,&minPoint.pointValue,&minPoint.pointIndex);
        f_findMaxTabValue(tab,NB_ELEMENT,&maxPoint.pointValue,&maxPoint.pointIndex);

        printf("la valeur Min du tableau est : %d\nElle est a l'indice %d \n",minPoint.pointValue, minPoint.pointIndex);
        printf("la valeur Max du tableau est : %d\nElle est a l'indice %d \n",maxPoint.pointValue, maxPoint.pointIndex);


        //changement de sens du tableau
        printf("avant Tab permute\n");
        f_tabDisplay(tab,NB_ELEMENT);
    //    f_switchTab(tab,NB_ELEMENT);
    //    printf("apres Tab permute\n");
    //    f_tabDisplay(tab,NB_ELEMENT);

        //tri a bulle
        printf("apres tri a bulle croissant\n");
        f_bubbleSortingInc(tab,NB_ELEMENT);
        f_tabDisplay(tab,NB_ELEMENT);
        printf("apres tri a bulle decroissant\n");
        f_bubbleSortingDec(tab,NB_ELEMENT);
        f_tabDisplay(tab,NB_ELEMENT);
    return;
}


void Chap7_Pyramide()
{
        int tailleTabAnne = sizeof(annee)/sizeof(int);
        int tailleTabfemme = sizeof(femme)/sizeof(int);
        int tailleTabhomme = sizeof(homme)/sizeof(int);

        //age le plus representé chez les femmes....................................
        tabPoint  agePlusRepresenteFemme;
        f_findMaxTabValue (femme,tailleTabfemme,
                           &agePlusRepresenteFemme.pointValue,&agePlusRepresenteFemme.pointIndex);
        printf("l'age le plus represente chez les femme est le %d\n",annee[agePlusRepresenteFemme.pointIndex]);

        //calcul age moyen par sexe..............................................
        int ageMoyenFemme;
        int nombretotalFemme=f_summTab(femme,tailleTabfemme);
        for (int i=0 ; i<tailleTabfemme ; ++i)
        {
            ageMoyenFemme = ageMoyenFemme + (femme[i]* (2020-annee[i]));
        }
        ageMoyenFemme = ageMoyenFemme/nombretotalFemme;
        printf("age moyen femme = %d\n",ageMoyenFemme);


        //nombre d'individu par tranche de 5
        int borneMoins=0;
        int bornePlus=5;
        do   {
                int nbLocal=0;
                for (int i=0; i<5; ++i)
                    {
                     nbLocal=nbLocal+femme[borneMoins+i];
                    }
                printf ("il y a %d personne dans le groupe %d-%d soit %.2f%%\n",nbLocal,borneMoins,bornePlus,(100.0 * nbLocal) / nombretotalFemme);
                borneMoins = borneMoins + 5;
                bornePlus = bornePlus +5;
              } while (bornePlus < tailleTabfemme);

    return;
}






void f_tabEntry (int *inTab, int inSize)
{
    int i =0;
    for (i=0 ; i < inSize ; ++i)
    {
        printf("entrer la valeur %d du tableau\n",i+1);
        scanf("%d",&inTab[i]);
    }
}


void f_tabDisplay (int *inTab, int inSize)
{
    for (int i=0 ; i < inSize ; ++i)
    {
        printf ("voici la case %d du tableau : %d\n",i,inTab[i]);
    }
}

/*
 Exercice 1 : donner le code en langage C qui permet de saisir les valeurs d’un tableau de 50 entiers et qui
 affiche la moyenne des valeurs. Compléter le programme pour afficher le nombre de valeurs en dessous de la
 moyenne et le nombre de valeurs au dessus de la moyenne.
 */



float f_averageTab (int *inTab,int inSize)
{
    //test pour verifier avant une division par zero
    if (inSize == 0)
    {
        printf("attention tableau vide %s!\n",__FUNCTION__);
        return 0.f ;
    }

    float average=0.f;
    for (int i=0 ; i < inSize ; ++i)
    {
        average += (int)inTab[i];       //cast pour s'assurer qu'on met un float dans la somme de average
    }
    average /= inSize;
    return average;
}

int f_aboveAverageNumber (int *inTab,int inSize,float inMoy)
{

    int aboveNumber = 0;
    for (int i=0 ; i < inSize ; ++i)
    {
        if (inTab[i]>inMoy)
        {
            ++aboveNumber;
        }
    }

    return aboveNumber;
}

int f_belowAverageNumber (int *inTab,int inSize,float inMoy)
{
    int belowNumber = 0;
    for (int i=0 ; i < inSize ; ++i)
    {
        if (inTab[i]<inMoy)
        {
            ++belowNumber;
        }
    }

    return belowNumber;
}

/*
 Exercice 2 : donner le code en langage C qui permet de saisir les valeurs d’un tableau de 50 entiers et
 qui affiche la valeur maximale et minimale saisie. Compléter le programme pour afficher le premier et
 le dernier emplacement de la valeur minimale dans le tableau.
 */

void f_findMaxTabValue (int *inTab,int inSize, int *outMaxValue, int *outMaxIndex)
{
    *outMaxValue = inTab[0];
    *outMaxIndex = 0;
    int i=0;
    for (i=0 ; i < inSize ; ++i)
    {
        if (inTab[i]>*outMaxValue)
        {
            *outMaxValue = inTab[i];
            *outMaxIndex = i;
        }
    }
}


void f_findMinTabValue (int *inTab,int inSize,int *outMinValue, int *outMinIndex)
{
    *outMinValue = inTab[0];
    *outMinIndex = 0;
    int i = 0;
    for (i=0 ; i < inSize ; i++)
    {
        if (inTab[i]<*outMinValue)
        {
            *outMinValue = inTab[i];
            *outMinIndex = i;
        }
    }
}


int f_summTab(int *inTab, int inSize)
{
        int summTab = 0;
        for (int i=0 ; i<inSize ; ++i)
        {
            summTab = summTab + inTab[i];
        }
        return summTab;
}



void f_copyTab(int *inTab,int *copyTab, int inSize)
{
    for (int i=0 ; i < inSize ; ++i)
    {
        copyTab[i]=inTab[i];
    }
}

void f_switchTab(int *inTab, int inSize)
{
    int tabTemp[inSize];
    for (int i=0 ; i < inSize ; ++i)
    {
        tabTemp[inSize-i-1]=inTab[i];
    }
    f_copyTab(tabTemp,inTab,inSize);
}


/*
Tri d'une liste de valeurs par l'algorithme dit du "tri à bulles"
(pour le tri croissant) : Le principe du tri à bulles est de placer
 en fin de liste les éléments les plus légers (la bulle). Pour cela,
on compare chaque élément d’indice i à l’élément suivant d’indice i + 1
: si l’élément d’indice i est plus grand que l'élément d’indice i + 1
alors on permute les deux éléments. Puis l'on passe au couple d'éléments
suivants jusqu'au dernier. Le tri est garanti si l'on reproduit cette
séquence N fois, N nombre d'éléments à trier.
*/


void f_elementPermute (int *A, int *B)
{
    int temp = 0;
    temp = *B;
    *B = *A;
    *A = temp;
    //test de mon permute a copier dans le main pour verifier
    /*
    int A =1;
    int B =2;
    printf("A = %d, B = %d\n",A,B);
    f_elementPermute(&A,&B);
    printf("A = %d, B = %d\n",A,B);
    */
}


void f_bubbleSortingInc(int *inTab , int inSize)
{
    int sortingEnd = 0;
    int compteurTest = 0;
    for (int j = 0 ; j < inSize && sortingEnd == 0 ; ++j)
    {
        sortingEnd = 1;
        for (int i=0 ; i < inSize-1 ; ++i)
        {
            ++compteurTest ;
            if (inTab[i]>inTab[i+1])
            {
                f_elementPermute(inTab+i,inTab+i+1);
                sortingEnd = 0;
            }
        }
    }
    printf("compteur test inc= %d\n",compteurTest);
}

void f_bubbleSortingDec(int *inTab , int inSize)
{
    int sortingEnd = 0;
    int compteurTest = 0;
    for (int j = 0 ; j < inSize && sortingEnd == 0 ; ++j)
    {
        sortingEnd = 1 ;
        for (int i=0 ; i < inSize-1 ; ++i)
        {
            ++compteurTest ;
            if (inTab[i]<inTab[i+1])
            {
                f_elementPermute(inTab+i,inTab+i+1);
                sortingEnd = 0;
            }
        }
    }
    printf("compteur test dec = %d\n",compteurTest);
}
