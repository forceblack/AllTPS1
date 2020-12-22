#ifndef CHAP7_LESTABLEAUX
#define CHAP7_LESTABLEAUX

#define NB_ELEMENT 10
#include <stdio.h>

//struct..................................................................................................

typedef struct tab_Point
{
    int pointValue;
    int pointIndex;
}tabPoint;





//prototype..................................................................................................

void Chap7_Tableau(void);

void f_tabEntry (int *inTab, int inSize);
void f_tabDisplay (int *inTab, int inSize);
float f_averageTab (int *inTab, int inSize);
int f_aboveAverageNumber (int *inTab, int inSize, float inMoy);
int f_belowAverageNumber (int *inTab, int inSize, float inMoy);
void f_findMaxTabValue (int *inTab, int inSize,int *outMaxValue, int *outMaxIndex);
void f_findMinTabValue (int *inTab, int inSize,int *outMinValue, int *outMaxIndex);

void f_switchTab(int *inTab, int inSize);
void f_copyTab(int *inTab,int *copyTab, int inSize);

void f_elementPermute (int *A, int *B);
void f_bubbleSortingInc (int *inTab , int inSize);
void f_bubbleSortingDec (int *inTab , int inSize);



#endif
