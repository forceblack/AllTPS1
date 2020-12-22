#include "ext/ez-draw.h"
#include "Chapitre4_Graphique.h"


void Chap4_Graph1 ()
{
    if (ez_init() < 0) exit(1); //initialisation de ez draw

    ez_window_create (400, 300, "Demo 01: Hello World", win1_on_event); //creation de la fenetre et lancement du "programme" de la fenetre

    ez_main_loop ();
    exit(0);

    return;
}



void win1_on_event (Ez_event *ev)                /* Called by ez_main_loop() */
{                                                /* for each event on win1   */
    switch (ev->type)
    {
       case Expose   : win1_on_expose    (ev); break;   //appel la fonction d'affichage
       case KeyPress : win1_on_key_press (ev); break;   //appel la fonction d'input clavier
    }
}

//fonction qui gère les entrées clavier de la fenetre
void win1_on_key_press (Ez_event *ev)
{
    switch (ev->key_sym) {
        case XK_q : ez_quit (); break;
    }

}



//fonction qui gère ce qui est affiché dans la fenetre
void win1_on_expose (Ez_event *ev)
{
    ez_draw_line      (ev->win,  60,  35, 130,  70);
}
