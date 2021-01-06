#ifndef CHAPITRE5_GRAPHEUR
#define CHAPITRE5_GRAPHEUR

#include <stdio.h>
#include "ext/ez-draw.h"


//STRUC................................................STRUCT

//cette structure defini les parametres necessaire à la creation de la fenetre du grapheur
typedef struct
{   //taille de la fenetre
    int height;
    int width;
    //les valeurs min et max des X et Y
    int Xmin;
    int Xmax;
    int Ymin;
    int Ymax;
    //le pas entre 2 valeurs du tracé de courbe
    float PAS;
}graphReference;

typedef struct
{
    int x;
    int y;
}point2D;


//cette structure définie une equation du second degres
typedef struct
{
   //x2
   float A;
   //x
    float B;
  //cst
    float C;
    //de la forme Ax2+Bx+C
}equation2Deg;



//PROTOTYPE.....................................................PROTOTYPE

void Chap5_Graph(void);                         //fonction main du grapheur
void Grapheur_event (Ez_event *ev);             //fonction appelé a la creation de fenetre (dispatch les events en sourie-clavier-display etc...
void Grapheur_on_key_press (Ez_event *ev);      //fonction qui traite les events clavier
void Grapheur_on_expose (Ez_event *ev);         //fonction qui traite l'affichae de la fenetre

void draw_axes (Ez_event *ev,graphReference *inGraph);
void draw_Cross (Ez_window win,point2D inRef, int inSize);
equation2Deg inputEquation2deg (void);
void draw_curve(Ez_event *ev,graphReference inGraph,equation2Deg inEquation);
void print_2Dpoint(point2D inPoint);



#endif
