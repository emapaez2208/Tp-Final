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


typedef struct
{
    char profesor [20];
    int dificultadParcial ;
    int Personalidad;
    int antiCheat;
} stprofesor;

/// Prototipado
void funcionnombre (char nombre [],stpersonaje a[]);
void funciondibujo (char imagen [][100], stpersonaje a []);
void funcionhabilidades (stpersonaje a[]);
void Verfunciones (stpersonaje a[],int val);

void resultado (stprofesor p [],stpersonaje a []);

int Pregunta1 (stpersonaje a[], stprofesor p []);



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

    /// Profesor
    stprofesor profe [1];
    habilidadProfesor(profe);
    mostrarProfe(profe);

    resultado( profe,b );



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
    for(int i=0 ; i<val; i++)
    {
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

/// Funcion para profesor

void habilidadProfesor (stprofesor p[])
{

    int i=0;
    srand(time (NULL));
    printf("\n Nombre del Profesor a enfrentar ?......");
    fflush(stdin);
    gets(&p[i].profesor);

    p[i].Personalidad=  rand()%11;
    p[i].antiCheat= rand()%11;
    p[i].dificultadParcial= rand()%11;

}

void mostrarProfe (stprofesor p [])
{
    int i=0;
    printf("\n personalidad :  %i",p[i].Personalidad);
    printf("\n anticheat :  %i",p[i].antiCheat);
    printf("\n dificultad del parcial :  %i",p[i].dificultadParcial);

}

void resultado (stprofesor p [],stpersonaje a [])
{

    int respuesta=0;
    int respuesta2=0;
    int respuesta3=0;
    int respuesta4=0;
    int i =0;
    int ii=0;
    int elegir=0;
    int aula=0;


    int puntajetotal;

    printf("\n\n .....................BIENVENIDOS..AL..AULA..DEL.PROFESOR..MAKANO..................\n\n");

    printf("\n Con que habilidad quisiera enfretar al profesor para poder entrar al aula ? \n si lo conoce bien a este profesor ya sabrias que elegir!!!");
    printf("\nCarisma..............1");
    printf("\nInteligencia.........2");
    printf("\nCheat................3.......");

    scanf("%i",&elegir);
    if(elegir==1){
    if( p[i].Personalidad > a[ii].habcarisma)
    {
        printf("\n Personalidad Profesor: %i   vs   %i :Tu carisma\n",p[i].Personalidad , a[ii].habcarisma);
        printf("\n Duelo perdido vuelve mas tarde a intentarlo");

    }
    else
    {
        printf("\n Personalidad Profesor: %i   vs   %i :Tu carisma\n",p[i].Personalidad , a[ii].habcarisma);
        printf("\n Duelo Ganado , ahora se viene el parcial cuidado");
        aula=1;

    }
    }

    if(elegir==2){
    if( p[i].dificultadParcial > a[ii].habinteligencia)
    {
        printf("\n Dificultad Profesor: %i   vs   %i :Tu Inteligencia\n",p[i].dificultadParcial , a[ii].habinteligencia);
        printf("\n Duelo perdido vuelve mas tarde a intentarlo");
    }
    else
    {
        printf("\n Dificultad Profesor: %i   vs   %i :Tu Inteligencia\n",p[i].dificultadParcial , a[ii].habinteligencia);
        printf("\n Duelo Ganado , ahora se viene el parcial cuidado");
        aula=1;
    }
    }
    if(elegir==3){
    if (p[i].antiCheat > a[ii].habcheat)
    {
        printf("\n AntiCheat del Profesor: %i   vs   %i :Tu Habilidad para copiarte\n",p[i].antiCheat , a[ii].habcheat);
        printf("\n Duelo perdido vuelve mas tarde a intentarlo");
    }
    else
    {
        printf("\n AntiCheat del Profesor: %i   vs   %i :Tu Habilidad para copiarte\n",p[i].antiCheat , a[ii].habcheat);
        printf("\n Duelo Ganado , ahora se viene el parcial cuidado");
        aula=1;

    }

    }
    /// hasta aca
   if(aula==1)
        {



        /// Pregunta 1

        printf("\n\n Pasaste la prueba ahora viene la primer pregunta");
        respuesta = Pregunta1(a,p);
        puntajetotal=respuesta;
        printf ("\n\n Puntaje hasta el momento :  %i",puntajetotal);



        /// Pregunta 2
        printf("\n\n siguiete pregunta\n");
        respuesta2=pregunta2(a,p);
        puntajetotal=respuesta+respuesta2;
        printf ("\n\n Puntaje hasta el momento :  %i",puntajetotal);

        /// Pregunta 3

        printf("\n\n siguiete pregunta\n");
        respuesta3=pregunta3(a,p);
        puntajetotal=puntajetotal+respuesta3;
        printf ("\n\n Puntaje hasta el momento :  %i",puntajetotal);

        /// Pregunta 4

        printf("\n\n siguiete pregunta\n");
        respuesta4=pregunta4(a,p);
        puntajetotal=puntajetotal+respuesta4;
        printf ("\n\n Puntaje hasta el momento :  %i",puntajetotal);



    }
}
void HabilRespuesta (stpersonaje a[])
{
    int i=0;
    printf("\n opcion=  Habilidades :");
    printf("\n 1-              Inteligencia :  %i",a[i].habinteligencia);
    printf("\n 2-                   Carisma :  %i",a[i].habcarisma);
    printf("\n 3-                     Cheat :  %i",a[i].habcheat);

    printf("\n Que habilidad quiere elegir?");
}

int Pregunta1 (stpersonaje a[], stprofesor p[])
{
    int i=0;
    int ii=0;
    srand(time(NULL));
    int dado=0;
    int dadoprofe=0;
    int elegir=0;
    int respuesta=0;
    char mmm='n';

    int resultado=3;
    char opcion ='v';
    printf("\n\n\n\033[32m Pregunta 1:");
    printf("\n El interbloque se producecuando vaarios procesos quieren acceder al mismo recurso y el semaforo no se lo permite ");
    printf("\n Verdadero = [v]");
    printf("\n     Falso = [f]........\033[0m");
    fflush(stdin);

    do{
    if(mmm=='s')
    {
        printf("\n Marque la nueva opcion:");
    }
    scanf(" %c",&opcion);
    printf("\n Maraste la opcion....%c",opcion);

    if(opcion=='v')
    {

        resultado=0;
    }
    else if(opcion=='f')
    {
        resultado=1;

    }
    printf("\n Quieres cambiar la respuesta ?  s/n");
    scanf(" %c",&mmm);
    }while(mmm=='s');


    if(resultado==1)
    {

        printf("\n\n Su respuesta es correcta!!!! ,  A sumado un punto a su inteligencia felicitaciones");

        a[ii].habinteligencia=a[ii].habinteligencia + 1;
        respuesta=1;


    }
    else
    {
        printf("\n\n  Ojo tu companiero lo hizo distinto ojo, quieres copiarte ? s/n..... ");

        scanf(" %c",&mmm);
        if(mmm=='n')
        {
            resultado=2;
        }

        while(mmm=='s')
        {
            printf("\n Usa algunas de tus habilidades para marear al preofe ;) ");
            HabilRespuesta (a);

            scanf("%i",&elegir);
            if(elegir==1)
            {
                printf("\n Inteligencia");
                dado=rand()%3;
                dadoprofe=rand()%10;
                if( a[ii].habinteligencia+dado > p[i].dificultadParcial + dadoprofe)
                {
                    printf("\n Me has confundio Tu respuesta es correcta");
                    respuesta=1;
                }
                else
                {
                    printf("\n Casi me enganias , F de falso");
                    printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS\033[0m ");
                }
            }
            if(elegir==2)
            {
                printf("\n Carisma");
                dado=rand()%3;
                dadoprofe=rand()%10;
                if( a[ii].habcarisma+dado > p[i].Personalidad + dadoprofe)
                {
                    printf("\n Me has confundio Tu respuesta es correcta");
                    respuesta=1;
                }
                else
                {
                    printf("\n Casi me enganias , F de falso");
                    printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS\033[0m ");
                }
            }
            if(elegir==3)
            {
                printf("\n Eligio Cheat");
                dado=rand()%3;
                dadoprofe=rand()%10;
                if( a[ii].habcheat+dado > p[i].antiCheat + dadoprofe)
                {
                    printf("\n Me has confundio Tu respuesta es correcta");
                    respuesta=1;
                }
                else
                {
                    printf("\n Casi me enganias , F de falso");
                    printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS\033[0m ");
                }
            }
            mmm='n';
        }

        if(resultado==2)
        {
            printf("\n Perdiste , Tu respuesta es incorrecta");
        }


    }

    return respuesta;
}

int pregunta2 (stpersonaje a [], stprofesor p [])
{
    int i=0;
    int ii=0;
    srand(time(NULL));
    int dado=0;
    int dadoprofe=0;
    int elegir=0;
    int respuesta=0;
    char mmm='n';

    int resultado=3;
    char opcion ='v';
    printf("\n\n\n\033[32m Pregunta 2:");
    printf("\n Un semaforo evita que un proceso realice una espera activa en la memoria de disco mientras llega su turno de ejecucion ");
    printf("\n Verdadero = [v]");
    printf("\n     Falso = [f]........\033[0m");
    fflush(stdin);

     do{
    if(mmm=='s')
    {
        printf("\n Marque la nueva opcion:");
    }
    scanf(" %c",&opcion);
    printf("\n Maraste la opcion....%c",opcion);

    if(opcion=='v')
    {

        resultado=0;
    }
    else if(opcion=='f')
    {
        resultado=1;

    }
    printf("\n Quieres cambiar la respuesta ?  s/n");
    scanf(" %c",&mmm);
    }while(mmm=='s');

    if(resultado==1)
    {

        printf("\n\n Su respuesta es correcta!!!! ,  A sumado un punto a su inteligencia felicitaciones");
        a[ii].habinteligencia=a[ii].habinteligencia + 1;
        respuesta=1;
    }
    else
    {

        /// printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS \033[0m");

        printf("\n\n Quieres cambiar la respuesta ?s/n.. El profesor esta distraido..... ");

        scanf(" %c",&mmm);
        if(mmm=='n')
        {
            resultado=2;
        }

        while(mmm=='s')
        {
            printf("\n Usa alguna de tus habilidades para marear al preofe ;) ");
            HabilRespuesta (a);

            scanf("%i",&elegir);
            if(elegir==1)
            {
                printf("\n Inteligencia");
                dado=rand()%3;
                dadoprofe=rand()%10;
                if( a[ii].habinteligencia+dado > p[i].dificultadParcial + dadoprofe)
                {
                    printf("\n Me has confundio Tu respuesta es correcta");
                    respuesta=1;
                }
                else
                {
                    printf("\n Casi me enganias , F de falso");
                    printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS\033[0m ");
                }
            }
            if(elegir==2)
            {
                printf("\n Carisma");
                dado=rand()%3;
                dadoprofe=rand()%10;
                if( a[ii].habcarisma+dado > p[i].Personalidad + dadoprofe)
                {
                    printf("\n Me has confundio Tu respuesta es correcta");
                    respuesta=1;
                }
                else
                {
                    printf("\n Casi me enganias , F de falso");
                    printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS\033[0m ");
                }
            }
            if(elegir==3)
            {
                printf("\n Eligio Cheat");
                dado=rand()%3;
                dadoprofe=rand()%10;
                if( a[ii].habcheat+dado > p[i].antiCheat + dadoprofe)
                {
                    printf("\n Me has confundio Tu respuesta es correcta");
                    respuesta=1;
                }
                else
                {
                    printf("\n Casi me enganias , F de falso");
                    printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS\033[0m ");
                }
            }
            mmm='n';
        }

        if(resultado==2)
        {
            printf("\n Perdiste , Tu respuesta es incorrecta");
        }


    }

    return respuesta;
}
int pregunta3 (stpersonaje a[], stprofesor p [])
{
    int i=0;
    int ii=0;
    srand(time(NULL));
    int dado=0;
    int dadoprofe=0;
    int elegir=0;
    int respuesta=0;
    char mmm='n';

    int resultado=3;
    char letra='a';
    printf("\n\n\n\033[32m Pregunta 3:");
    printf("\n Elegir la apcion correcta ");
    printf("\n  Un proceso que ejecuta un SemWait con valor 2 :");
    printf("\n      Se envia a LISTOS :......a");
    printf("\n  Se envia a  BLOQUEADOS:......b");
    printf("\n            Queda en CPU: .....c");
    printf("\n Ninguna de las anteriores:....d.........\033[0m");
   


     do{
    if(mmm=='s')
    {
        printf("\n Marque la nueva opcion:");
    }
    scanf(" %c",&letra);
    printf("\n Maraste la opcion....%c",letra);

    if(letra=='c')
    {

        resultado=1;
    }
    else if(letra!='c')
    {
        resultado=0;

    }
    printf("\n mmmm esta pregunta es enganiosa!!! Quieres cambiar la respuesta ?  s/n");
    scanf(" %c",&mmm);
    }while(mmm=='s');


    if(resultado==1)
    {

        printf("\n\n Su respuesta es correcta!!!! ,  A sumado un punto a su inteligencia felicitaciones");
        a[ii].habinteligencia=a[ii].habinteligencia + 1;
        respuesta=1;
    }
    else
    {

        /// printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS \033[0m");

        printf("\n\n Quieres cambiar la respuesta ? s/n.. El profesor esta distraido..... ");

        scanf(" %c",&mmm);
        if(mmm=='n')
        {
            resultado=2;
        }

        while(mmm=='s')
        {
            printf("\n Usa alguna de tus habilidades para marear al preofe ;) ");
            HabilRespuesta (a);

            scanf("%i",&elegir);
            if(elegir==1)
            {
                printf("\n Inteligencia");
                dado=rand()%3;
                dadoprofe=rand()%10;
                if( a[ii].habinteligencia+dado > p[i].dificultadParcial + dadoprofe)
                {
                    printf("\n Me has confundio Tu respuesta es correcta");
                    respuesta=1;
                }
                else
                {
                    printf("\n Casi me enganias , F de falso");
                    printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS\033[0m ");
                }
            }
            if(elegir==2)
            {
                printf("\n Carisma");
                dado=rand()%3;
                dadoprofe=rand()%10;
                if( a[ii].habcarisma+dado > p[i].Personalidad + dadoprofe)
                {
                    printf("\n Me has confundio Tu respuesta es correcta");
                    respuesta=1;
                }
                else
                {
                    printf("\n Casi me enganias , F de falso");
                    printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS\033[0m ");
                }
            }
            if(elegir==3)
            {
                printf("\n Eligio Cheat");
                dado=rand()%3;
                dadoprofe=rand()%10;
                if( a[ii].habcheat+dado > p[i].antiCheat + dadoprofe)
                {
                    printf("\n Me has confundio Tu respuesta es correcta");
                    respuesta=1;
                }
                else
                {
                    printf("\n Casi me enganias , F de falso");
                    printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS\033[0m ");
                }
            }
            mmm='n';
        }

        if(resultado==2)
        {
            printf("\n Perdiste , Tu respuesta es incorrecta");
        }


    }
    return respuesta;

}

int pregunta4 (stpersonaje a [], stprofesor p [])
{
    int i=0;
    int ii=0;
    srand(time(NULL));
    int dado=0;
    int dadoprofe=0;
    int elegir=0;
    int respuesta=0;
    char mmm='n';

    int resultado=3;
    char letra='a';
    printf("\n\n\n\033[32m Pregunta 3:");
    printf("\n Elegir la apcion correcta ");
    printf("\n Dado el valor del semaforo con contador = -1 puedo afirmar que :  ");
    printf("\n Que hay un proceso bloqueado:...........a");
    printf("\n No hay ningun proceso bloqueado:........b");
    printf("\n Que hay al menos un proceso bloqueado:..c.........\033[0m");
  

    do{
    if(mmm=='s')
    {
        printf("\n Marque la nueva opcion:");
    }
    scanf(" %c",&letra);
    printf("\n Maraste la opcion....%c",letra);

    if(letra=='a')
    {

        resultado=1;
    }
    else if(letra!='a')
    {
        resultado=0;

    }
    printf("\n Estas seguroooooo!!! O quieres cambiar la respuesta ?  s/n");
    scanf(" %c",&mmm);
    }while(mmm=='s');

    if(resultado==1)
    {

        printf("\n\n Su respuesta es correcta!!!! ,  A sumado un punto a su inteligencia felicitaciones");
        a[ii].habinteligencia=a[ii].habinteligencia + 1;
        respuesta=1;
    }
    else
    {

        /// printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS \033[0m");

        printf("\n\n Quieres cambiar la respuesta ?.. El profesor esta distraido..... ");

        scanf(" %c",&mmm);
        if(mmm=='n')
        {
            resultado=2;
        }

        while(mmm=='s')
        {
            printf("\n Usa alguna de tus habilidades para marear al preofe ;) ");
            HabilRespuesta (a);

            scanf("%i",&elegir);
            if(elegir==1)
            {
                printf("\n Inteligencia");
                dado=rand()%3;
                dadoprofe=rand()%10;
                if( a[ii].habinteligencia+dado > p[i].dificultadParcial + dadoprofe)
                {
                    printf("\n Me has confundio Tu respuesta es correcta");
                    respuesta=1;
                }
                else
                {
                    printf("\n Casi me enganias , F de falso");
                    printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS\033[0m ");
                }
            }
            if(elegir==2)
            {
                printf("\n Carisma");
                dado=rand()%3;
                dadoprofe=rand()%10;
                if( a[ii].habcarisma+dado > p[i].Personalidad + dadoprofe)
                {
                    printf("\n Me has confundio Tu respuesta es correcta");
                    respuesta=1;
                }
                else
                {
                    printf("\n Casi me enganias , F de falso");
                    printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS\033[0m ");
                }
            }
            if(elegir==3)
            {
                printf("\n Eligio Cheat");
                dado=rand()%3;
                dadoprofe=rand()%10;
                if( a[ii].habcheat+dado > p[i].antiCheat + dadoprofe)
                {
                    printf("\n Me has confundio Tu respuesta es correcta");
                    respuesta=1;
                }
                else
                {
                    printf("\n Casi me enganias , F de falso");
                    printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS\033[0m ");
                }
            }
            mmm='n';
        }

        if(resultado==2)
        {
            printf("\n Perdiste , Tu respuesta es incorrecta");
        }


    }
    return respuesta;

}
