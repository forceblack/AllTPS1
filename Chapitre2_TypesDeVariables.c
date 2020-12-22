#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "Chapitre2_TypesDeVariables.h"

void typeDeVariable()
{
    //2.2 types entiers

        printf("Signed\n");
        printf("La taille d’un char est en octet : %lu\n",sizeof(char));
        printf("La taille d’un short est en octet : %lu\n",sizeof(short));
        printf("La taille d’un int est en octet : %lu\n",sizeof(int));
        printf("La taille d’un long est en octet : %lu\n",sizeof(long));

        printf("Unsigned\n");
        printf("La taille d’un Unsignedchar est en octet : %lu\n",sizeof(unsigned char));
        printf("La taille d’un Unsignedshort est en octet : %lu\n",sizeof(unsigned short));
        printf("La taille d’un Unsignedint est en octet : %lu\n",sizeof(unsigned int));
        printf("La taille d’un Unsignedlong est en octet : %lu\n",sizeof(unsigned long));

        //hexadecimal
        int i = -5 ;
        printf("\nOn affiche avec x: %x\n",i);
        printf("On affiche avec X: %X\n",i);


        //limits
        //uchar
        printf("\nValeur max avec un unsignedchar: %d\n",UCHAR_MAX);
        //char
        printf("Valeur min avec un char: %d\n",SCHAR_MIN);
        printf("Valeur max avec un char: %d\n",SCHAR_MAX);
        //ushort
        printf("\nValeur max avec un unsignedshort: %d\n",USHRT_MAX);
        //short
        printf("Valeur min avec un short: %d\n",SHRT_MIN);
        printf("Valeur max avec un short: %d\n",SHRT_MAX);
        //uint
        printf("\nValeur max avec un unsignedint: %u\n",UINT_MAX);
        //int
        printf("Valeur min avec un int: %d\n",INT_MIN);
        printf("Valeur max avec un int: %d\n",INT_MAX);
        //ulong
        printf("\nValeur max avec un unsignedlong: %lu\n",ULONG_MAX);
        //long
        printf("Valeur min avec un long: %ld\n",LONG_MIN);
        printf("Valeur max avec un long: %ld\n",LONG_MAX);


        //2.3 Types Reels

        printf("\nValeur min avec un float: %.10e\n",__FLT_MIN__);
        printf("Valeur max avec un float: %.10e\n",__FLT_MAX__);

        int test_int = 42 ;
        float test_float = 0;

        test_float = test_int ;
        printf("int dans float = %f\n",test_float);

        test_float = 12.5 ;
        test_int = 0 ;
        test_int = test_float ;
        printf("float dans int = %d\n",test_int);

        //exo float
            /*
        float f = 1e10;
        printf("premier %.12f\n",f);

        int j = 0;
        for ( j = 0 ; j<10000 ; j++)
        {
            f = 1e10;
            f=f+j;
        printf("f= %.12f i=%d\n",f,j);
        }
        f=1.5;
        printf("1.5 %.12f\n",f);
        f=1.3;
        printf("1.3 %.12f\n",f);
        */

    return;
}
