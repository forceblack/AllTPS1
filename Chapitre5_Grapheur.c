#include <stdio.h>
#include "ext/ez-draw.h"


#include "Chapitre4_Graphique.h"
#include "Chapitre5_Grapheur.h"


void Chap5_Graph()
{

    if (ez_init() < 0) exit(1); //initialisation de ez draw

    ez_window_create (500, 500, "Grapheur", Grapheur_event); //creation de la fenetre et lancement du "programme" de la fenetre

    ez_main_loop ();
    exit(0);

    return;
}

void Grapheur_event (Ez_event *ev)                /* Called by ez_main_loop() */
{                                                /* for each event on win1   */
    switch (ev->type)
    {
       case Expose   : Grapheur_on_expose    (ev); break;   //appel la fonction d'affichage
       case KeyPress : Grapheur_on_key_press (ev); break;   //appel la fonction d'input clavier
    }
}

//fonction qui gère les entrées clavier de la fenetre
void Grapheur_on_key_press (Ez_event *ev)
{
    switch (ev->key_sym) {
        case XK_q : ez_quit (); break;  //pour l'instant seulement la touche q pour quitter
    }
}

void Grapheur_on_expose (Ez_event *ev)
{
    //deux variables pour la hauteur et largueur de la fenetre
    int winHeight,winWidth;
    //on utilise ez_windows_get_size pour recuperer ces valeurs
    ez_window_get_size(ev->win,&winHeight,&winWidth);
    graphReference myGraph = {winHeight,winWidth,-10,10,-10,10,0.1}; //on determine les parametres de notre graph

    //equation2Deg myEquation = {3,0,-1};
    equation2Deg myEquation = inputEquation2deg();


    draw_axes (ev,&myGraph);
    draw_curve(ev, myGraph,myEquation);


}


void draw_axes (Ez_event *ev,graphReference *inGraph)
{
    //grace au parametre du graph, on peut tracer 2 axes
    ez_draw_line(ev->win,0,(inGraph->width)/2,inGraph->height,(inGraph->width)/2); //axe des X
    ez_draw_line(ev->win,(inGraph->height)/2,0,(inGraph->height)/2,inGraph->width); //axe des Y

    //repere central
    point2D centreGraph = {(inGraph->height)/2,(inGraph->width)/2};

    // on va tracer les reperes horizontaux
    // (le nombre de segements c'est = (Xmax - Xmin)
    // et on divise par 2 si on veux un segment tout les 2
    int nbPointX = (inGraph->Xmax-inGraph->Xmin)/2;

    for (int i = 0 ; i < nbPointX ; ++i)
    {
        point2D refPoint = {(inGraph->height/nbPointX) * i, centreGraph.y};
        draw_Cross (ev->win, refPoint ,5 );
    }


    //meme idee pour les y
    int nbPointY = (inGraph->Ymax-inGraph->Ymin)/2;

    for (int j = 0 ; j < nbPointY ; ++j)
    {
        point2D refPoint = {centreGraph.x , (inGraph->width/nbPointY) * j};
        draw_Cross (ev->win, refPoint ,5 );
    }


    //affichage des valeurs
    //on affiche la valeur Min, max et O sur les x
    char printXmin[4];                           //on peut afficher jusque 4 chiffres
    sprintf(printXmin,"%d",inGraph->Xmin);       //mise en forme pour l'affichage avec sprintf
    ez_draw_text(ev->win,EZ_BL,0,centreGraph.y,printXmin);

    char printXmax[4];                           //on peut afficher jusque 4 chiffres
    sprintf(printXmax,"%d",inGraph->Xmax);       //mise en forme pour l'affichage avec sprintf
    ez_draw_text(ev->win,EZ_BR,inGraph->height,centreGraph.y,printXmax);

    //pareil pour les y
    char printYmin[4];
    sprintf(printYmin,"%d",inGraph->Ymin);
    ez_draw_text(ev->win,EZ_BL,centreGraph.x,inGraph->width,printYmin);

    char printYmax[4];
    sprintf(printYmax,"%d",inGraph->Ymax);
    ez_draw_text(ev->win,EZ_TL,centreGraph.x,0,printYmax);

    //l'origine
    ez_draw_text(ev->win,EZ_BL,centreGraph.x,centreGraph.y,"0");

    return;
}


equation2Deg inputEquation2deg (void)
{
    equation2Deg outEquation;
    printf("entre le premier coeeficient (en X^2)\n");
    scanf ("%f",&outEquation.A);
    printf("entre le deuxieme coeeficient (en X)\n");
    scanf ("%f",&outEquation.B);
    printf("entre le troisieme coeeficient (la constante)\n");
    scanf ("%f",&outEquation.C);

    //printf("%fx2+%fx+%f\n",outEquation.A,outEquation.B,outEquation.C);

    return outEquation;
}


void draw_curve(Ez_event *ev,graphReference inGraph,equation2Deg inEquation)
{
    float i=0;
    point2D previousPoint , localPoint;
    point2D centreGraph = {(inGraph.height)/2,(inGraph.width)/2};

    float coefX = inGraph.height / (inGraph.Xmax - inGraph.Xmin);
    float coefY = inGraph.width / (inGraph.Ymax - inGraph.Ymin);

    //init du previous point (le meme que le tout premier local point (on remplace i par inGraph.Xmin)
    previousPoint.x =  centreGraph.x + inGraph.Xmin * coefX;
    previousPoint.y =  centreGraph.y + ( (inEquation.A *inGraph.Xmin * inGraph.Xmin) + (inEquation.B) * inGraph.Xmin + inEquation.C ) * coefY;

    for (i=inGraph.Xmin ; i < inGraph.Xmax; i = i + inGraph.PAS)
    {
        localPoint.x =  centreGraph.x + i*coefX;
        localPoint.y =  centreGraph.y - ((inEquation.A *i * i ) + (inEquation.B) * i + inEquation.C ) * coefY;

        ez_draw_line(ev->win,previousPoint.x,previousPoint.y,localPoint.x,localPoint.y);

        previousPoint.x=localPoint.x;
        previousPoint.y=localPoint.y;

    }

}

void print_2Dpoint(point2D inPoint)
{
    printf("X=%d Y=%d\n",inPoint.x,inPoint.y);
}


void draw_Cross (Ez_window win,point2D inRef, int inSize)
{
    point2D A, B, C, D;

    A.x= inRef.x - inSize/2;
    B.x= inRef.x;
    C.x= inRef.x + inSize/2;
    D.x= inRef.x;

    A.y= inRef.y;
    B.y= inRef.y - inSize/2;
    C.y= inRef.y;
    D.y= inRef.y + inSize/2;

    ez_draw_line(win,A.x,A.y,C.x,C.y);
    ez_draw_line(win,B.x,B.y,D.x,D.y);

    return ;
}
