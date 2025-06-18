
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct
{
    int habinteligencia;
    int habcarisma;
    int habcheat;
    char nombre [20];
    char dibujo [12][100];
} stpersonaje;

/// Prototipado
void funcionnombre (char nombre [],stpersonaje a[]);
void funciondibujo (char imagen [][100], stpersonaje a []);
void funcionhabilidades (stpersonaje a[]);
void Verfunciones (stpersonaje a[],int val);



int main()
{

    stpersonaje b [1];
    char nombre[20];
    printf("\n Nombre de su personaje :  ");
    fflush(stdin);
    gets(&nombre);
    funcionnombre(nombre,b);

    funcionhabilidades(b);
    Verfunciones(b,1);


    Pila DADA;
    inicpila(&DADA);
    apilar (&DADA,2);
    apilar (&DADA,1);
    apilar (&DADA,5);
    apilar (&DADA,8);
    apilar (&DADA,3);
    mostrar(&DADA);

    ordenarIsercion(&DADA);
    mostrar(&DADA);


    return 0;
}
/// Funcion par el nombre
void funcionnombre (char nombre [],stpersonaje a[])
{
    int i;
    strcpy(a[i].nombre,nombre);

}
/// Funcion para el dibujo

void funciondibujo (char imagen [][100], stpersonaje a [])
{
    int i;
    strcpy (a[i].dibujo,imagen);

}

/// Funcion de las habilidades
void funcionhabilidades (stpersonaje a[])
{
    int i;
    int habilidad =0;
    int puntos=0;
    a[i].habinteligencia=0;
    a[i].habcarisma=0;
    a[i].habcheat=0;

    printf("\n ATENCION : si usted carga mas puntos de los permitidos volvera a empezar!!!");
    printf("\nTiene 21 puntos en habilidad para cargar (inteligencia,carisma,cheat).Elija bien su estrategia , se puede poner dificil! \n\n ");

    do
    {
        habilidad=21;
        printf("\n Inteligencia :  ");
        scanf("%i",&a[i].habinteligencia);
        habilidad=habilidad-a[i].habinteligencia;
        //system("cls");
        if(habilidad>0)
        {

            printf("\n Le quedan %i  puntos",habilidad);
            printf("\n Carisma :  ");
            scanf ("%i",&a[i].habcarisma);

            habilidad=habilidad-a[i].habcarisma;
            // system("cls");
        }
        if(habilidad>0)
        {
            a[i].habcheat=0;
            printf("\n Le quedan %i  puntos",habilidad);
            printf("\n Cheat ");
            scanf("%i",&a[i].habcheat);
            habilidad=habilidad-a[i].habcheat;
            //system("cls");
        }
    }
    while(habilidad<0);


}

///funcion de mostrar (lo puse en un arreglo por que sino no copiaba los datos a esta funcion y no los podia retornar con la otra funcion)

void Verfunciones (stpersonaje a [], int val)
{
    for(int i=0 ;i<val;i++){
    puts("\033[34m \n=======================================");
    printf("       Nombre :  %s\n",a[i].nombre);
    printf("\n  Habilidades :");
    printf("\n              Inteligencia :  %i",a[i].habinteligencia);
    printf("\n                   Carisma :  %i",a[i].habcarisma);
    printf("\n                     Cheat :  %i",a[i].habcheat);
    printf("\n            Dibujo         :  %s",a[i].dibujo);
    puts("\n=======================================");
    printf("\033[0m");
    }
}

///  Insercion Pila

void insertarElementoPila (Pila*DADA, int dato)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(DADA)&& tope(DADA)>dato)
    {
        apilar(&aux,desapilar (DADA));
    }
    apilar (DADA,dato);
    while(!pilavacia(&aux))
    {
        apilar(DADA,desapilar(&aux));
    }

}

void ordenarIsercion (Pila*DADA)

{
    Pila aux, rr;
    inicpila(&aux);
    inicpila(&rr);
    while(!pilavacia(DADA))
    {
        insertarElementoPila(&aux,desapilar(DADA));

    }
    while(!pilavacia(&aux))
    {
        apilar (&rr,desapilar(&aux));
    }
    while(!pilavacia(&rr))
    {
        apilar(DADA,desapilar(&rr));
    }
}

