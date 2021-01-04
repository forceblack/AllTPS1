#include <stdio.h>
#include "ext/ez-draw.h"


#include "Chapitre4_Graphique.h"
#include "Chapitre5_Grapheur.h"


void Chap5_Graph()
{

    if (ez_init() < 0) exit(1); //initialisation de ez draw

    graphReference MyGraph = {500,500,-10,10,-10,10,0.1};

    ez_window_create (MyGraph.height, MyGraph.width, "Grapheur", Grapheur_event(MyGraph)); //creation de la fenetre et lancement du "programme" de la fenetre

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
    ez_draw_line      (ev->win,  60,  35, 130,  70);
}


void draw_axes (window w,graphReference inGraph)
{

    //on commence par tracer l'axe des X
    draw_line(w,0 ,(inGraph.width)/2,inGraph.height,(inGraph.width)/2);

    //puis l'axe des Y
    draw_line(w,(inGraph.height)/2 ,0,(inGraph.height)/2,inGraph.width);


    //repere central
    point2D centreGraph = {(inGraph.height)/2,(inGraph.width)/2};
    //draw_Cross (w,centreGraph.x,centreGraph.y,5); //on la voit pas a cause des axes



    /*on va tracer les reperes horizontaux
     * (le nombre de segements c'est = (Xmax - Xmin)
     * et on divise par 2 si on veux un segment tout les 2*/
    int nbPointX = (inGraph.Xmax-inGraph.Xmin)/2;

    int i;
    for (i = 0 ; i < nbPointX ; ++i)
    {
        draw_Cross (w, (inGraph.height/nbPointX) * i, centreGraph.y ,5 );
    }

    //meme idee pour les y
    int nbPointY = (inGraph.Ymax-inGraph.Ymin)/2;

    int j;
    for (j = 0 ; j < nbPointY ; ++j)
    {
        draw_Cross (w, centreGraph.x , (inGraph.width/nbPointY) * j ,5 );
    }


    //affichage des valeurs
    //on affiche la valeur Min, max et O sur les x
    char printXmin[4];                           //on peut afficher jusque 4 chiffres
    sprintf(printXmin,"%d",inGraph.Xmin);       //mise en forme pour l'affichage avec sprintf
    draw_text(w,0,centreGraph.y,printXmin);

    char printXmax[4];                           //on peut afficher jusque 4 chiffres
    sprintf(printXmax,"%d",inGraph.Xmax);       //mise en forme pour l'affichage avec sprintf
    draw_text(w,inGraph.height-20,centreGraph.y,printXmax); //petit decalage dans l'axe X pour de ma afficher en dehors du cadre


    //pareil pour les y
    char printYmin[4];
    sprintf(printYmin,"%d",inGraph.Ymin);
    draw_text(w,centreGraph.x,inGraph.width,printYmin);

    char printYmax[4];
    sprintf(printYmax,"%d",inGraph.Ymax);
    draw_text(w,centreGraph.x,0+15,printYmax);

    //l'origine
    draw_text(w,centreGraph.x,centreGraph.y,"0");


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



void draw_curve(window w,graphReference inGraph,equation2Deg inEquation)
{
    float i=0;
    point2D previousPoint , localPoint;
    point2D centreGraph = {(inGraph.height)/2,(inGraph.width)/2};

    printf("Xmin =%d Xmax=%d PAS=%f\n",inGraph.Xmin,inGraph.Xmax,inGraph.PAS);
    printf("%fx2+%fx+%f\n",inEquation.A,inEquation.B,inEquation.C);




    float coefX = inGraph.height / (inGraph.Xmax - inGraph.Xmin);
    float coefY = inGraph.width / (inGraph.Ymax - inGraph.Ymin);

    //init du previous point (le meme que le tout premier local point (on remplace i par inGraph.Xmin)
    previousPoint.x =  centreGraph.x + inGraph.Xmin * coefX;
    previousPoint.y =  centreGraph.y + ( (inEquation.A *inGraph.Xmin * inGraph.Xmin) + (inEquation.B) * inGraph.Xmin + inEquation.C ) * coefY;

    for (i=inGraph.Xmin ; i < inGraph.Xmax; i = i + inGraph.PAS)
    {
        localPoint.x =  centreGraph.x + i*coefX;
        localPoint.y =  centreGraph.y - ((inEquation.A *i * i ) + (inEquation.B) * i + inEquation.C ) * coefY;

        //printf("centre ->");
        //print_2Dpoint(centreGraph);
        printf("rang n ->");
        print_2Dpoint(localPoint);
        printf("rang n-1 ->");
        print_2Dpoint(previousPoint);

        draw_line(w,previousPoint.x,previousPoint.y,localPoint.x,localPoint.y);

        previousPoint.x=localPoint.x;
        previousPoint.y=localPoint.y;

    }

    flush_stdin();
    getch();
}

void print_2Dpoint(point2D inPoint)
{
    printf("X=%d Y=%d\n",inPoint.x,inPoint.y);
}



