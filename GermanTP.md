#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Pila.h"

typedef struct
{
    int ID;                      /// ID:para numero de imagen;
    char nombre[30];             /// Nombre de la Imagen;
    char dibujo[40][100];        /// Con 100 espacios llega a mitad de pantalla;
    int fila;                    /// Variable para imprimir la cant de filas justas;
} stImagen;

typedef struct
{
    int inteligencia;           /// habilidades
    int habcarisma;
    int habcheat;
    char nombre[20];
    char dibujo[14][100];        /// Retrato de pj
    int fila;                    /// Filas de imagen del retratro
    int nivelAYSO;              /// control de ganarle a los profes
    int nivelOrga;
    int nivelMate;

} stpersonaje;

typedef struct
{
    char profesor [20];
    int dificultadParcial ;
    int Personalidad;
    int antiCheat;
} stprofesor;

/// CONSTANTES Y VARIABLES GLOBALES
const char teclaArriba = 'w', teclaAbajo = 's', teclaDerecha = 'd', teclaIzquierda = 'a';
stImagen nombreJuego, imagenVacia;
int variableSonido = 1;

///PROTOTIPADO
int moverse(int i, int opciones, void funcActual(), int funcSiguiente(), stImagen a);
void mensajeInicial(int i);
void cargaImagenes (char archivo[],stImagen imagen[]);
void verImagen (stImagen imagen);
int opcionesInicio(int i);
void mensajeOpciones(int i);
void menuOpciones(int i);
void reproducirSonido(int i);
void cambiarSonido();
void textoInicial(stImagen imagenes[]);
void introMate (stImagen imagen);

int seleccion(int i, int opciones, stImagen a[]);
stpersonaje fotopj (stImagen imagen);


void guardarPartida(char archivo[], stpersonaje a);
stpersonaje cargarPartida(char archivo[]);
void imagenCargaPartida(stpersonaje pj);
int menuCargaPartida(stpersonaje pj, int i);

///makano
int resultado (stprofesor p [],stpersonaje a);
int Pregunta1 (stpersonaje a, stprofesor p[]);
int pregunta2 (stpersonaje a, stprofesor p []);
int pregunta3 (stpersonaje a, stprofesor p []);
int pregunta4 (stpersonaje a, stprofesor p []);
void HabilRespuesta (stpersonaje a);

///cantuccici
int ProfesoraCantuccini (stprofesor pp[], stpersonaje a);
int preguntaOrga1 (stprofesor pp[], stpersonaje a);
int preguntaOrga2 ( stpersonaje a);
int preguntaOrga3 ( stpersonaje a);
int preguntaOrga4 (stpersonaje a);


int main()
{
    /// Variables

    char imagenesPepo[] = {"ImagenesEstaticas"};
    char archivoPartidas[] = {"PartidasGuardadas"};
    stImagen arreglo[30];
    stpersonaje Personaje1;
    char nombrePj[20];
    int menu = 0;
    int pj;
    int cargaExitosa;

    cargaImagenes(imagenesPepo, arreglo);
    nombreJuego = arreglo[0];

    ///Profesor makano
    stprofesor profemakano [1];
    int puntosMakano=0;

    ///Profesora cantuccini
    stprofesor profeOrga [1];
    int puntosCantuccini=0;

    do
    {

        switch(menu)
        {
        case 0:

            menu = moverse(0, 4, mensajeInicial, opcionesInicio, nombreJuego);
            break;


        case 1:
        {
            textoInicial(arreglo);
            system("pause");
            system("cls");

            pj=4+seleccion(0,4,arreglo);
            Personaje1=fotopj(arreglo[pj]);

            verImagenPJ(Personaje1);
            printf("Ingrese su nombre: ");
            gets(&nombrePj);
            strcpy(Personaje1.nombre,nombrePj);
            system("pause");
            system("cls");

            verImagenPJ(Personaje1);
            printf("Hola %s\n",Personaje1.nombre);

            printf("Ahora vamos a cargar tus habilidades!!!!\n");

            ///Se guarda el personaje

            system("pause");
            system("cls");

            menu=3;

            break;
        }
        case 2:
        {
            Personaje1 = cargarPartida(archivoPartidas);
            cargaExitosa = menuCargaPartida(Personaje1, 0);

            if(cargaExitosa == 0)
                menu = 3;
            else
                menu = 0;


            system("cls");


            break;
        }
        case 3:
        {
            do
            {
                system("cls");
                printf("                  Ingresaste   al    pasillo!!!!!! \n");
                verImagen(arreglo[10]);
                printf("      4:SALA AYSO              7:Laboratorio\n      5:SALA Org Empresarial   8:Guardar\n      6:SALA Mate              0:Salir          ELEGIR :");
                fflush(stdin);
                scanf("%i",&menu);
                system("cls");
            }
            while( menu < 0 || (menu > 0 && menu < 4) || menu > 8 );

            break;
        }
        case 4:
        {
            verImagen(arreglo[12]);
            printf("en lo de makano\n");

            puntosMakano=resultado( profemakano,Personaje1);
            printf("\n Usted a saco un puntaje de :: %i  Respuestas correctas\n\n",puntosMakano);

            printf("\n\ncompletaste el desafio\n");
            system("pause");
            system("cls");

            menu=3;
            break;
        }
        case 5:
        {
            verImagen(arreglo[14]);
            printf("en lo de cantuccini\n");
            puntosCantuccini=ProfesoraCantuccini( profeOrga,Personaje1);
            printf("\n Usted a saco un puntaje de :: %i  Respuestas correctas",puntosCantuccini);

            printf("\n\ncompletaste el desafio\n");
            system("pause");
            system("cls");

            menu=3;
            break;
        }
        case 6:
        {
            int puntos=0;

            if (1)
            {
                introMate(arreglo[13]);
                system("pause");
                system("cls");

                EjercicioMate1(arreglo[13]);
                system("pause");
                system("cls");

                EjercicioMate2 (arreglo[13]);
            }



            menu=3;
            break;
        }
        case 7:
        {
            verImagen(arreglo[15]);
            printf("en lo beretcher\n");
            verImagen(arreglo[16]);
            printf("ganaste??  \n");
            system("pause");
            system("cls");
            scanf("%i",&menu);
            break;
        }
        case 8:
        {
            guardarPartida(archivoPartidas, Personaje1);
            system("pause");
            system("cls");
            menu = 3;
            break;
        }
        case 9:
        {
            printf("Felicidades pasaste de etapa\n");
            system("pause");
            system("cls");
            menu=11;
            break;
        }
        default:
        {
            break;
        }

        }

    }
    while(menu!=777);


    return 0;
}
/// funcion para moverse por los menus
int moverse(int i, int opciones, void funcActual(), int funcSiguiente(), stImagen a)
{
    char tecla;
    int num;

    verImagen(a);
    funcActual(i);  /// mostramos una imagen y en donde estamos ubicados

    fflush(stdin);
    tecla = getch();  /// leemos la tecla, reproducimos sonido si esta activado
    reproducirSonido (variableSonido);

    system("cls");

    if(tecla == 13)
    {
        num = funcSiguiente(i);     /// si preciona enter pasamos a la siguiente mandando el valor actual de i

    }
    else
    {
        if(tecla == teclaAbajo && i<opciones-1)       /// dependiendo de que tecla se use le damos el valor a i
            i++;
        else if(tecla == teclaAbajo && i>opciones-2)
            i = 0;
        else if(tecla == teclaArriba && i>0)
            i--;
        else if(tecla == teclaArriba && i<1)
            i = opciones-1;


        num = moverse(i, opciones, funcActual, funcSiguiente, a);   /// llamada recursiva a la funcion
    }
    return num;     /// retornamos un numero para algunas funciones
}

/// funcion para mostrar el inicio segun el valor de i
void mensajeInicial(int i)
{
    if(i==0)
    {
        printf("                                                --> Nueva partida\n");
        printf("                                                    Cargar partida\n");
        printf("                                                    Opciones\n");
        printf("                                                    Salir\n");
    }
    else if(i==1)
    {
        printf("                                                    Nueva partida\n");
        printf("                                                --> Cargar partida\n");
        printf("                                                    Opciones\n");
        printf("                                                    Salir\n");
    }
    else if(i==2)
    {
        printf("                                                    Nueva partida\n");
        printf("                                                    Cargar partida\n");
        printf("                                                --> Opciones\n");
        printf("                                                    Salir\n");
    }
    else if(i==3)
    {
        printf("                                                    Nueva partida\n");
        printf("                                                    Cargar partida\n");
        printf("                                                    Opciones\n");
        printf("                                                --> Salir\n");
    }
}

///Carga todas las imagenes del archivo,    Loadind Imagenes ....
void cargaImagenes (char archivo[],stImagen imagen[])
{
    FILE* archi=fopen(archivo,"rb");
    int i=0;
    if(archi)
    {
        while(fread(&imagen[i++],sizeof(stImagen),1,archi)>0)
        {
        }
        fclose(archi);
    };
}

/// Muestra 1 imagen
void verImagen (stImagen imagen)
{
    for (int i = 0; i < imagen.fila; i++)
    {
        printf("%s\n", imagen.dibujo[i]);
    }
}
/// muestra el dibujo del personaje pasado por parametro
void verImagenPJ (stpersonaje imagen)
{
    for (int i = 0; i < imagen.fila; i++)
    {
        printf("%s\n", imagen.dibujo[i]);
    }
}
/// funcion para retornar un valor dependiendo de donde se este ubicado con i , esto se usa para los case en el switch partiendo del menu principal
int opcionesInicio(int i)
{
    if(i==0)
    {
        return 1;
    }
    else if(i==1)
    {
        return 2;
    }
    else if(i==2)
        moverse(0, 4, mensajeOpciones, menuOpciones, nombreJuego);
    else if(i==3)
    {
        verImagen(nombreJuego);
        printf("\n\n                                    Gracias por jugar, vuelva pronto! \n\n");
        system("pause");
        return 777;
    }

}
/// funcion para mostrar el menu de opciones dependiendo del valor de i
void mensajeOpciones(int i)
{
    if(i==0)
    {
        printf("                                                --> Sonido\n");
        printf("                                                    Graficos\n");
        printf("                                                    Idioma\n");
        printf("                                                    Volver\n");
    }
    else if(i==1)
    {
        printf("                                                    Sonido\n");
        printf("                                                --> Graficos\n");
        printf("                                                    Idioma\n");
        printf("                                                    Volver\n");
    }
    else if(i==2)
    {
        printf("                                                    Sonido\n");
        printf("                                                    Graficos\n");
        printf("                                                --> Idioma\n");
        printf("                                                    Volver\n");
    }
    else if(i==3)
    {
        printf("                                                    Sonido\n");
        printf("                                                    Graficos\n");
        printf("                                                    Idioma\n");
        printf("                                                --> Volver\n");
    }
}
/// dependiendo del valor de i cuando se ingresa enter, es a donde mandamos al usuario. funcion para el mensaje anterior
void menuOpciones(int i)
{
    if(i==0)
    {
        cambiarSonido();
        system("cls");
        moverse(i, 4, mensajeOpciones, menuOpciones, nombreJuego);
    }
    else if(i==1)
    {
        printf("Graficos:\n     Parpadear siempre: Activo\n\n");
        system("pause");
        system("cls");
        moverse(i, 4, mensajeOpciones, menuOpciones, nombreJuego);
    }
    else if(i==2)
    {
        printf("Idioma:\n       Espaninglish: siempre\n\n");
        system("pause");
        system("cls");
        moverse(i, 4, mensajeOpciones, menuOpciones, nombreJuego);
    }
    else if(i==3)
    {
        moverse(2, 4, mensajeInicial, opcionesInicio, nombreJuego);
    }
}
/// funcion para reproducir sonido de tecla
void reproducirSonido(int i)
{
    if(i == 1)
        Beep(400, 170);
}
/// funcion para cambiar el sonido de tecla, activado o desactivado
void cambiarSonido()
{
    char tecla;
    do
    {

        if(variableSonido == 0)
        {
            printf("\n\n\n\n                                            Sonido de tecla: Activado\n\n");
            tecla = getch();
            variableSonido = 1;
            reproducirSonido(variableSonido);
            system("cls");

        }
        else
        {
            printf("\n\n\n\n                                            Sonido de tecla: Desactivado\n\n");
            tecla = getch();
            reproducirSonido(variableSonido);
            variableSonido = 0;
            system("cls");
        }
    }
    while(tecla != 13);

}
/// comienzo de partida nueva
void textoInicial(stImagen imagenes[])
{
    printf(" !Introduccion al Juego: Vida Universitaria: UTN !\n");
    verImagen(imagenes[1]);

    printf(" !Bienvenido a la Universidad Tecnologica Nacional! \n");
    printf("Este no es solo un campus; es el punto de partida de tu futuro profesional.\n");
    printf("Como nuevo universitario, cada decision, cada parcial, cada pequeño truco que descubras, moldeara tu camino.\n");
    printf("¿Seras el alumno ejemplar o el estratega astuto? Es hora de averiguarlo.\n");
    printf("La aventura comienza ahora!!!\n\n\n");
}

/// funcion inicio de enfrentamiento matematicas
void introMate (stImagen imagen)
{
    printf("                              Bienvenido a Matematica !!!!!\n");
    verImagen(imagen);
    printf("Por recorte de tiempo no vas a tener clases vamos directo al examen\n");
    printf("Que dios te ayude!!\n");
}

/// primer ejercicio a resolver matematicas
int EjercicioMate1(stImagen imagen)
{

    int rta=0;

    do
    {

        verImagen(imagen);
        printf("\n");
        printf("Resolver: x^2+0=4  el valor de x es \n");
        printf("1:x=1;x=2  2:x=2;x=-2 3:x=-1;x=2\n\n");
        printf("RTA: ");
        fflush(stdin);
        scanf("%i",&rta);
        system("cls");
    }
    while ( rta > 3 || rta < 1 );

    if (rta==2)
    {
        printf("Rta correcta");
        return 1;
    }
    printf("Rta incorrecta");
    return 0;
}
/// segundo ejercicio matematicas
int EjercicioMate2 (stImagen imagen)
{
    int num;

    verImagen(imagen);
    printf("Desafio coreano!! \nApreta continuar solo si estas listo!!!\n");
    system("pause");
    system("cls");


    verImagen(imagen);
    printf(" _____ \n");
    printf("|     |\n");
    printf("|  5  |\n");
    printf("|_____|\n");
    usleep(700000);
    system("cls");

    verImagen(imagen);
    printf(" _____ \n");
    printf("|     |\n");
    printf("| +6  |\n");
    printf("|_____|\n");
    usleep(700000);
    system("cls");

    verImagen(imagen);
    printf(" _____ \n");
    printf("|     |\n");
    printf("| +9  |\n");
    printf("|_____|\n");
    usleep(700000);
    system("cls");

    verImagen(imagen);
    printf(" _____ \n");
    printf("|     |\n");
    printf("| -2  |\n");
    printf("|_____|\n");
    usleep(700000);
    system("cls");

    verImagen(imagen);
    printf(" _____ \n");
    printf("|     |\n");
    printf("| -4  |\n");
    printf("|_____|\n");
    usleep(700000);
    system("cls");

    verImagen(imagen);
    printf(" _____ \n");
    printf("|     |\n");
    printf("| +3  |\n");
    printf("|_____|\n");
    usleep(700000);
    system("cls");

    verImagen(imagen);
    printf(" _____ \n");
    printf("|     |\n");
    printf("| +6  |\n");
    printf("|_____|\n");
    usleep(700000);
    system("cls");

    verImagen(imagen);
    printf("Ingrese resultado: ");
    fflush(stdin);
    scanf("&i",&num);

    system("cls");

    if(num==23)
    {
        return 2;

    }

    return 0;
}

/**
int EjercicioMate3 (stImagen imagen)
{
    int num;
   do
    {
        printf("El ejercicio 3 esta dificil te pones nervioso \n");
        printf("La profe no te presta atencion y el ayudante se durmio\n");
        printf("Con que habilidad deseas resolver el ejercicio\n");
        printf(" 1:Inteligencia  2:Carisma 3:Trampa \n");
        fflush(stdin);
        scanf("%i",&num
              if(num==1)
              {
                  if (habilidad de pj )
              }
              if(num==2)
              {
                  printf("Le hablas al ayudante,pero...esta dormido no te oye y fallas\n");
                  return 0
              }
              if(num==3)
              {
                  printf("Lo tenes a el crack de la matematica al lado y miras su hoja\n");
                  if(habilidad de personaje > 6)
                  {
                      printf("Tu habilidad para saltarte las reglas te permiten safar el ejercicio\n");
                      return 1;
                  }
                  else
                  {
                      printf("Tu compa se da cuenta y tapa la hoja, suerte que no te delatara\n");
                      printf("Dejas el ejercicio incompleto\n");
                      return 0;
                  }

              }
    }while(num>3 || num<1);

}
*/

/// seleccion de personaje
int seleccion(int i, int opciones, stImagen a[])
{
    char tecla;
    int pj;

    printf("Elija se personaje: \n\n");
    verImagen(a[i+2]);

    fflush(stdin);
    tecla = getch();
    reproducirSonido (variableSonido);

    system("cls");

    if(tecla == 13)
    {
        pj = i+2;

    }
    else
    {
        if((tecla == teclaAbajo || tecla == teclaDerecha) && i<opciones-1)
            i++;
        else if((tecla == teclaAbajo || tecla == teclaDerecha) && i>opciones-2)
            i = 0;
        else if((tecla == teclaArriba || tecla == teclaIzquierda) && i>0)
            i--;
        else if((tecla == teclaArriba || tecla == teclaIzquierda) && i<1)
            i = opciones-1;


        pj=seleccion(i, opciones, a);
    }
    return pj;
}
/// copiamos el personaje elegido y lo guardamos en la estructura del personaje
stpersonaje fotopj (stImagen imagen)
{
    stpersonaje personaje;

    for(int i=0; i<imagen.fila; i++)
    {
        strcpy(personaje.dibujo[i],imagen.dibujo[i]);
    }
    personaje.fila=imagen.fila;

    return personaje;
}
/// guardar partida
void guardarPartida(char archivo[], stpersonaje a)
{
    FILE* buffer = fopen(archivo, "wb");
    int flag = 0;

    if(buffer)
    {

        flag = fwrite(&a, sizeof(stpersonaje), 1, buffer);

        fclose(buffer);
    }

    if(flag == 1)
        printf("La partida fue guardada exitosamente!\n\n");
    else
        printf("No se pudo guardar la partida, intente nuevamente!\n\n");

}

/// cargar la partida desde el archivo
stpersonaje cargarPartida(char archivo[])
{
    FILE* buffer = fopen(archivo, "rb");
    stpersonaje pj;

    if(buffer)
    {

        fread(&pj, sizeof(stpersonaje), 1, buffer);

        fclose(buffer);
    }
    return pj;
}
/// funcion para mostrar la carga de partida
void imagenCargaPartida(stpersonaje pj)
{
    verImagen(nombreJuego);

    printf("\n\n                                                Ultima partida\n\n");
    printf("-----------------------------------------------------------------------\n");
    verImagenPJ(pj);
    printf("                           Nombre: %s                                                            \n", pj.nombre);
    printf("                           Habilidades:                                                          \n");
    printf("                                  Inteligencia: %i                                               \n", pj.inteligencia);
    printf("                                       Carisma: %i                                               \n", pj.habcarisma);
    printf("                                         Cheat: %i                                               \n", pj.habcheat);
    printf("-----------------------------------------------------------------------\n\n\n");
    printf("                                                   Desea cargar la partida?\n\n");
}
/// funcion del menu de carga partida, con la eleccion de si acepta o no
int menuCargaPartida(stpersonaje pj, int i)
{
    char tecla;
    imagenCargaPartida(pj);
    if(i==0)
        printf("                                               --> Si                No\n\n");
    else
        printf("                                                   Si            --> No\n\n");

    fflush(stdin);
    tecla = getch();
    reproducirSonido (variableSonido);

    system("cls");

    if(tecla == 13)
    {
        return i;

    }
    else
    {

        if(tecla == teclaDerecha && i<1)
            i++;
        else if(tecla == teclaDerecha && i>0)
            i = 0;
        else if(tecla == teclaIzquierda && i>0)
            i--;
        else if(tecla == teclaIzquierda && i<1)
            i = 1;


        menuCargaPartida(pj, i);
    }
}
int resultado (stprofesor p [],stpersonaje a)
{

    int respuesta=0;
    int respuesta2=0;
    int respuesta3=0;
    int respuesta4=0;
    int i =0;
    int ii=0;
    int elegir=0;
    int aula=0;
    int total=0;

    p[i].antiCheat=0;
    p[i].dificultadParcial=0;
    p[i].Personalidad=0;


    printf("\n\n .....................BIENVENIDOS..AL..AULA..DEL.PROFESOR..MAKANO..................\n\n");

    printf("\n Con que habilidad quisiera enfretar al profesor para poder entrar al aula ? \n si lo conoce bien a este profesor ya sabrias que elegir!!!");
    printf("\nCarisma..............1");
    printf("\nInteligencia.........2");
    printf("\nCheat................3.......");

    do
    {

        scanf("%i",&elegir);
        if(3<elegir || elegir<1)
        {

            printf("\n opcion incorrecta , vuelva a elegir .....");
        }
    }
    while(elegir!=1 && elegir !=2 && elegir!=3);
    if(elegir==1)
    {
        if( p[i].Personalidad > a.habcarisma)
        {
            printf("\n Personalidad Profesor: %i   vs   %i :Tu carisma\n",p[i].Personalidad, a.habcarisma);
            printf("\n Duelo perdido vuelve mas tarde a intentarlo");

        }
        else
        {
            printf("\n Personalidad Profesor: %i   vs   %i :Tu carisma\n",p[i].Personalidad, a.habcarisma);
            printf("\n Duelo Ganado , ahora se viene el parcial cuidado");
            aula=1;

        }
    }

    if(elegir==2)
    {
        if( p[i].dificultadParcial > a.inteligencia)
        {
            printf("\n Dificultad Profesor: %i   vs   %i :Tu Inteligencia\n",p[i].dificultadParcial, a.inteligencia);
            printf("\n Duelo perdido vuelve mas tarde a intentarlo");
        }
        else
        {
            printf("\n Dificultad Profesor: %i   vs   %i :Tu Inteligencia\n",p[i].dificultadParcial, a.inteligencia);
            printf("\n Duelo Ganado , ahora se viene el parcial cuidado");
            aula=1;
        }
    }
    if(elegir==3)
    {
        if (p[i].antiCheat > a.habcheat)
        {
            printf("\n AntiCheat del Profesor: %i   vs   %i :Tu Habilidad para copiarte\n",p[i].antiCheat, a.habcheat);
            printf("\n Duelo perdido vuelve mas tarde a intentarlo");
        }
        else
        {
            printf("\n AntiCheat del Profesor: %i   vs   %i :Tu Habilidad para copiarte\n",p[i].antiCheat, a.habcheat);
            printf("\n Duelo Ganado , ahora se viene el parcial cuidado");
            aula=1;

        }

    }

    if(aula==1)
    {



        /// Pregunta 1

        printf("\n\n Pasaste la prueba ahora viene la primer pregunta");
        respuesta = Pregunta1(a,p);
        puts("\n.........................................................................................\n");
        /// Pregunta 2
        printf("\n\n siguiete pregunta\n");
        respuesta2=pregunta2(a,p);
        puts("\n.........................................................................................\n");
        /// Pregunta 3
        puts("\n.........................................................................................\n");
        printf("\n\n siguiete pregunta\n");
        respuesta3=pregunta3(a,p);
        puts("\n.........................................................................................\n");
        /// Pregunta 4

        printf("\n\n siguiete pregunta\n");
        respuesta4=pregunta4(a,p);



        total=respuesta+respuesta2+respuesta3+respuesta4;

        return total;
    }
}
int Pregunta1 (stpersonaje a, stprofesor p[])
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

    do
    {
        if(mmm=='s')
        {
            printf("\n Marque la nueva opcion:");
        }
        scanf(" %c",&opcion);
        printf("\n Marcaste la opcion....%c",opcion);

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
    }
    while(mmm=='s');


    if(resultado==1)
    {

        printf("\n\n Su respuesta es correcta!!!! ,  A sumado un punto a su inteligencia felicitaciones");

        a.inteligencia=a.inteligencia + 1;
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
                if( a.inteligencia+dado > p[i].dificultadParcial + dadoprofe)
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
                if( a.habcarisma+dado > p[i].Personalidad + dadoprofe)
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
                if( a.habcheat+dado > p[i].antiCheat + dadoprofe)
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

int pregunta2 (stpersonaje a, stprofesor p [])
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

    do
    {
        if(mmm=='s')
        {
            printf("\n Marque la nueva opcion:");
        }
        scanf(" %c",&opcion);
        printf("\n Maraste la opcion....%c",opcion);

        if(opcion=='v')
        {

            resultado=1;
        }
        else if(opcion=='f')
        {
            resultado=0;

        }
        printf("\n Quieres cambiar la respuesta ?  s/n");
        scanf(" %c",&mmm);
    }
    while(mmm=='s');

    if(resultado==1)
    {

        printf("\n\n Su respuesta es correcta!!!! ,  A sumado un punto a su inteligencia felicitaciones");
        a.inteligencia=a.inteligencia + 1;
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
                if( a.inteligencia+dado > p[i].dificultadParcial + dadoprofe)
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
                if( a.habcarisma+dado > p[i].Personalidad + dadoprofe)
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
                if( a.habcheat+dado > p[i].antiCheat + dadoprofe)
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
int pregunta3 (stpersonaje a, stprofesor p [])
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



    do
    {
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
    }
    while(mmm=='s');


    if(resultado==1)
    {

        printf("\n\n Su respuesta es correcta!!!! ,  A sumado un punto a su inteligencia felicitaciones");
        a.inteligencia=a.inteligencia + 1;
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
                if( a.inteligencia+dado > p[i].dificultadParcial + dadoprofe)
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
                if( a.habcarisma+dado > p[i].Personalidad + dadoprofe)
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
                if( a.habcheat+dado > p[i].antiCheat + dadoprofe)
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

int pregunta4 (stpersonaje a, stprofesor p [])
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


    do
    {
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
    }
    while(mmm=='s');

    if(resultado==1)
    {

        printf("\n\n Su respuesta es correcta!!!! ,  A sumado un punto a su inteligencia felicitaciones");
        a.inteligencia=a.inteligencia + 1;
        respuesta=1;
    }
    else
    {

        /// printf("\n\n\033[41m su respuesta es incorrecta , PENSE QUE SABIAS MAS \033[0m");

        printf("\n\n  El profesor esta distraido.....Tienes una chances mas de cambiar la respuesta, apurate dale ? s/n... ");

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
                if( a.inteligencia+dado > p[i].dificultadParcial + dadoprofe)
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
                if( a.habcarisma+dado > p[i].Personalidad + dadoprofe)
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
                if( a.habcheat+dado > p[i].antiCheat + dadoprofe)
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
void HabilRespuesta (stpersonaje a)
{
    int i=0;
    printf("\n opcion=  Habilidades :");
    printf("\n 1-              Inteligencia :  %i",a.inteligencia);
    printf("\n 2-                   Carisma :  %i",a.habcarisma);
    printf("\n 3-                     Cheat :  %i",a.habcheat);

    printf("\n Que habilidad quiere elegir?");
}
/// Organizacion empresarial (cantuccini );
int ProfesoraCantuccini (stprofesor pp[], stpersonaje a)
{
    int i=0;
    int ii=0;

    pp[i].Personalidad= 3;
    pp[i].antiCheat=8 ;
    pp[i].dificultadParcial= 5;


    int respuesta1=0;
    int respuesta2=0;
    int respuesta3=0;
    int respuesta4=0;
    int total=0;

    printf("\n\n.....................BIENVENIDOS..A..LA..CLASE..DE..CANTUCCINI..............\n\n");

    printf("\n Tiene un pase directo al aula, piense bien sus estrategias para lograr objetivos!!!");
    printf("\n\n Se viene la primer pregunta");

    respuesta1=preguntaOrga1(pp,a);
    puts("\n.........................................................................................\n");
    respuesta2=preguntaOrga2(a);
    puts("\n.........................................................................................\n");
    respuesta3=preguntaOrga3(a);
    puts("\n.........................................................................................\n");
    respuesta4=preguntaOrga4(a);


    total=respuesta1+respuesta2+respuesta3+respuesta4;

    return total;

}

int preguntaOrga1 (stprofesor pp[], stpersonaje a)
{
    srand(time(NULL));
    int dado=0;
    int dadoprofe=0;
    int respuesta=0;
    int i=0;
    int ii=0;
    char mmm='n';
    int elegir=0;
    char palabra[20];


    printf("\n\n \033[32m.................Complete la palabra que falta............ ");
    printf("\nHablemos de una matriz FODA ...Que significa cada una de esas siglas ?");
    printf("\nF = fortaleza");
    printf("\nO = oportunidad");
    printf("\nD = ...........");
    printf("\nA = amenaza");
    printf("\033[0m");

    printf("\n Quiere usar algunas de tus habilidades para contestar las pregunta ? s/n... si es 'n' complete la palabra ");
     do
        {
            printf("\n MARQUE LA OPCION BIEN....s/n...... ");

             fflush(stdin);
       scanf(" %c",&mmm);

        }
        while(mmm!='s' && mmm !='n');

    if(mmm=='s')
    {
        HabilRespuesta (a);

        scanf("%i",&elegir);
        if(elegir==1)
        {
            printf("\n Inteligencia");
            dado=rand()%3;
            dadoprofe=rand()%10;
            if( a.inteligencia+dado > pp[i].dificultadParcial + dadoprofe)
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
            if( a.habcarisma+dado > pp[i].Personalidad + dadoprofe)
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
            if( a.habcheat+dado > pp[i].antiCheat + dadoprofe)
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

    }
    else
    {
        printf("\n Su respues es......");
        fflush(stdin);
        gets(&palabra);
        if(strcmpi(palabra,"debilidad")==0)
        {
            printf("\n Su respuesta es correcta , Felicitaciones");
            printf("\n Tome 1 puntos de carisma");
            respuesta=1;
            a.habcarisma=a.habcarisma+1;

        }
        else
        {

            printf("\nLo siento tu respuesta es incorrecta");
        }
    }


    return respuesta;
}
int preguntaOrga2 ( stpersonaje a)
{
    int ii=0;
    int respuesta = 0;
    char palabra[20];
    printf("\n\n \033[32m.................Complete la palabra que falta............ ");
    printf("\n\n Cuando decimos que está ligada a características de alta COMPETITIVIDAD, magnificencia,\n productividad,GRAN IMPACTO, CALIDAD, efectividad.");
    printf("\n\nHablamos de una empresa moderna o tradicional?");
    printf("\n     Empresa ......");

    printf("\033[0m");
    fflush(stdin);
    gets(&palabra);
    if(strcmpi(palabra, "moderna")==0)
    {
        printf("\n Respuesta correcta , segui asi");
        printf("\n Te ganaste 1 puntos de carisma");
        a.habcarisma=a.habcarisma+1;
        respuesta=1;
    }
    else
    {
        printf("\n La proxima te va a ir mejor , respuesta INCORRECTA");
    }

    return respuesta;
}
int preguntaOrga3 ( stpersonaje a)

{
    int i=0;
    int respuesta=0;
    char resultado='f';
    printf("\n\033[32m..............Conteste verdaderos (v) o falso (f).................... ");
    printf("\nHablando de las habilidades de una persona");
    printf("\nEl concepto de habilidades blandas hace referencia a todos los conocimientos teóricos o técnicos que posee un profesional,");
    printf("\nindependiente de su área de trabajo. se relacionan con el nivel de conocimientos técnicos y preparación académica.");
    printf("\nVERDADERO......V");
    printf("\nFALSO..........F......");
    printf("\033[0m");
    fflush(stdin);
    scanf(" %c",&resultado);

    if(resultado=='f')
    {

        printf("\n\nFELICITACIONES , muy bien!!!");
        respuesta=1;
    }
    else
    {

        printf("\n La respuesta es incorrecta , en este caso estamos hablando de una Habilidad 'DURA'");
    }

    return respuesta;
}
int preguntaOrga4 (stpersonaje a)
{
    char letra='n';
    int opcion= 0;
    int respuesta=0;

    printf("\n..............OJO..LA..PROFESORA..ESTA..OBSEBANDO................\n\n ");
    printf("\n                      o  o o          o o  o    ");
    printf("\n                    o        o      o        o  ");
    printf("\n                    o    00   o     o   00   o  ");
    printf("\n                    o    00   o     o   00   o            ");
    printf("\n                     o       o       o      o    ");
    printf("\n                       o o o           o o o                   ");


    printf("\n\n\n\033[32m Te ofrecieron un machete!!! para esta pregunta. Lo deseas usar ?     s/n   .......");
    fflush(stdin);
    scanf(" %c",&letra);

    if(letra=='s')
    {
        printf("\033[0m");
        printf("\n LA PROFESORA TE VIOOOOOOOOOOO , FALLASTE.... AHORA CORRRRREEEEEEE......!!!!");

    }
    else
    {

        printf ("\n ...........................ESTRUCTURAS..ORGANIZACIONALES......................\n");
        printf("\n             Elije la opcion correcta! titulo 'Organizaciones Horizontales'   ");
        printf("\n\n  Cuando se habla de:\n Estructura: Organización sin jerarquías formales. Se basa en redes de  \npersonas que se autoorganizan según el contexto y la necesidad. ");
        printf("\n  Liderazgo: Flexible y emergente. No hay líderes fijos, sino que el liderazgo surge de manera  \norgánica dependiendo de la situación y las habilidades de cada persona.");
        printf("\033[0m");
        printf("\n\n   Se Dice que es una: ");
        printf("\n...HOLOCRACIA........1");
        printf("\n...REDARQUIA.........2");
        printf("\n...SOCIOCRACIA.......3");



        do
        {
            printf("\n MARQUE LA OPCION BIEN !");
            printf("\n        RESPUESTA :..");

            fflush(stdin);
            scanf("%i",&opcion);

        }
        while(opcion!=1 && opcion !=2 && opcion !=3);
        if(opcion==2)
        {
            printf("\n CORRECTOOOOOOOOOO , muy bien era una pregunta muy dificil !!! te voy a dar 2 puntos por no copiarte ");
            respuesta=2;
        }
        else
        {
            printf("\n  FALLASTE , la opcion correcta era la 'b' : REDARQUIA");
        }
    }

    return respuesta;
}
