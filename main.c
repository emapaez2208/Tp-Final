#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    int ID;                      /// ID:para numero de imagen;
    char nombre[30];             /// Nombre de la Imagen;
    char dibujo[40][100];        /// Con 100 espacios llega a mitad de pantalla;
    int fila;                    /// Variable para imprimir la cant de filas justas;
}stImagen;

typedef struct
{
    int inteligencia;
    int habcarisma;
    int habcheat;
    char nombre[20];
    char dibujo[14][100];        /// Retrato de pj
    int fila;                    /// Filas de imagen del retratro
    int nivelAYSO;
    int nivelOrga;
    int nivelMate;

} stpersonaje;

/// CONSTANTES
const char teclaArriba = 'w', teclaAbajo = 's';
stImagen nombreJuego, imagenVacia;
int variableSonido = 1;

///PROTOTIPADO
int moverse(int i, int opciones, void funcActual(), int funcSiguiente(), stImagen a);
void mensaje(int i);
void cargaImagenes (char archivo[],stImagen imagen[]);  /// Archivo de imagen y un arreglo de imagenes cargatodas;
void verImagen (stImagen imagen);                       /// Por parametro la imagen a ver;
int opcionesInicio(int i);
void mensJuego(int i);
void menuOpciones(int i);
void reproducirSonido(int i);
void cambiarSonido();

int seleccion(int i, int opciones, stImagen a[]);       ///Seleccion de pj
stpersonaje fotopj (stImagen imagen);                   /// Copia imagen del pj Seleccionado en la struct de pj.


void guardarPartida(char archivo[], stpersonaje a);
stpersonaje cargarPartida(char archivo[]);
void imagenCargaPartida(stpersonaje pj);
int menuCargaPartida(stpersonaje pj, int i);


int main()
{
    ///Variables

    char imagenesPepo[] = {"ImagenesEstaticas"};
    char archivoPartidas[] = {"PartidasGuardadas"};
    stImagen arreglo[30];
    stpersonaje Personaje1;
    char nombrePj[20];
    int menu;
    int pj;
    int cargaExitosa;


    cargaImagenes(imagenesPepo, arreglo);
    nombreJuego = arreglo[0];
    menu = moverse(0, 4, mensaje, opcionesInicio, nombreJuego);

    do
    {

        switch(menu)
        {
        case 0:

            menu = moverse(0, 4, mensaje, opcionesInicio, nombreJuego);
            break;


        case 1:
            {
                Textoinicia(arreglo);
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
                system("cls");
                int aux;
                printf("                  Ingresaste   al    pasillo!!!!!! \n");
                verImagen(arreglo[10]);
                printf("      4:SALA AYSO              7:Laboratorio\n      5:SALA Org Empresarial   8:Guardar\n      6:SALA Mate              11:Salir          ELEGIR :");
                scanf("%i",&aux);

                if(aux<9 && aux>3)
                {
                    menu=aux;
                }
                system("cls");
                break;
            }
        case 4:
            {
                verImagen(arreglo[12]);
                printf("en lo de makano\n");
                printf("completaste el desafio\n");
                system("pause");
                system("cls");

                menu=3;
                break;
            }
        case 5:
            {
                verImagen(arreglo[14]);
                printf("en lo de cantuccini\n");
                printf("completaste el desafio\n");
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
                    IntroMate(arreglo[13]);
                    system("pause");system("cls");

                    EjercicioMate1(arreglo[13]);
                    system("pause");system("cls");

                    EjercicioMate2 (arreglo[13]);
                }



                menu=3;
                break;
            }
        case 7:
            {

                printf("en lo beretcher\n");

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

    }while(menu!=11);


    return 0;
}

int moverse(int i, int opciones, void funcActual(), int funcSiguiente(), stImagen a)
{
    char tecla;
    int num;

    verImagen(a);
    funcActual(i);

    fflush(stdin);
    tecla = getch();
    reproducirSonido (variableSonido);

    system("cls");

    if(tecla == 13){
        num = funcSiguiente(i);

    }else{
        if(tecla == teclaAbajo && i<opciones-1)
                i++;
            else if(tecla == teclaAbajo && i>opciones-2)
                i = 0;
            else if(tecla == teclaArriba && i>0)
                i--;
            else if(tecla == teclaArriba && i<1)
                i = opciones-1;


            num=moverse(i, opciones, funcActual, funcSiguiente, a);
    }
    return num;
}


void mensaje(int i)
{
    if(i==0){
        printf("                                                --> Nueva partida\n");
        printf("                                                    Cargar partida\n");
        printf("                                                    Opciones\n");
        printf("                                                    Salir\n");
    }else if(i==1){
        printf("                                                    Nueva partida\n");
        printf("                                                --> Cargar partida\n");
        printf("                                                    Opciones\n");
        printf("                                                    Salir\n");
    }else if(i==2){
        printf("                                                    Nueva partida\n");
        printf("                                                    Cargar partida\n");
        printf("                                                --> Opciones\n");
        printf("                                                    Salir\n");
    }else if(i==3){
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
    for (int i = 0; i < imagen.fila; i++) {
        printf("%s\n", imagen.dibujo[i]);
    }
}

void verImagenPJ (stpersonaje imagen)
{
    for (int i = 0; i < imagen.fila; i++) {
        printf("%s\n", imagen.dibujo[i]);
    }
}
int opcionesInicio(int i)
{
    if(i==0){
        return 1;
    }else if(i==1){
        return 2;
    }else if(i==2)
        moverse(0, 4, mensJuego, menuOpciones, nombreJuego);
    else if(i==3)
        printf("Gracias por jugar, vuelva pronto! \n\n");

}

void mensJuego(int i)
{
    if(i==0){
        printf("                                                --> Sonido\n");
        printf("                                                    Graficos\n");
        printf("                                                    Idioma\n");
        printf("                                                    Volver\n");
    }else if(i==1){
        printf("                                                    Sonido\n");
        printf("                                                --> Graficos\n");
        printf("                                                    Idioma\n");
        printf("                                                    Volver\n");
    }else if(i==2){
        printf("                                                    Sonido\n");
        printf("                                                    Graficos\n");
        printf("                                                --> Idioma\n");
        printf("                                                    Volver\n");
    }else if(i==3){
        printf("                                                    Sonido\n");
        printf("                                                    Graficos\n");
        printf("                                                    Idioma\n");
        printf("                                                --> Volver\n");
    }
}

void menuOpciones(int i)
{
        if(i==0){
        cambiarSonido();
        system("cls");
        moverse(i, 4, mensJuego, menuOpciones, nombreJuego);
    }else if(i==1){
        printf("Graficos:\n     Parpadear siempre: Activo\n\n");
        system("pause");
        system("cls");
        moverse(i, 4, mensJuego, menuOpciones, nombreJuego);
    }else if(i==2){
        printf("Idioma:\n       Espaninglish: siempre\n\n");
        system("pause");
        system("cls");
        moverse(i, 4, mensJuego, menuOpciones, nombreJuego);
    }else if(i==3){
        moverse(2, 4, mensaje, opcionesInicio, nombreJuego);
    }
}

void reproducirSonido(int i)
{
    if(i == 1)
        Beep(400, 170);
}

void cambiarSonido()
{
    char tecla;
    do{

        if(variableSonido == 0){
            printf("\n\n\n\n                                            Sonido de tecla: Activado\n\n");
            tecla = getch();
            variableSonido = 1;
            reproducirSonido(variableSonido);
            system("cls");

        }else{
            printf("\n\n\n\n                                            Sonido de tecla: Desactivado\n\n");
            tecla = getch();
            reproducirSonido(variableSonido);
            variableSonido = 0;
            system("cls");
        }
    }while(tecla != 13);

}
void Textoinicia(stImagen imagenes[])
{
    printf(" !Introduccion al Juego: Vida Universitaria: UTN !\n");
    verImagen(imagenes[1]);

    printf(" !Bienvenido a la Universidad Tecnologica Nacional! \n");
    printf("Este no es solo un campus; es el punto de partida de tu futuro profesional.\n");
    printf("Como nuevo universitario, cada decision, cada parcial, cada pequeño truco que descubras, moldeara tu camino.\n");
    printf("¿Seras el alumno ejemplar o el estratega astuto? Es hora de averiguarlo.\n");
    printf("La aventura comienza ahora!!!\n\n\n");
}


void IntroMate (stImagen imagen)
{
    printf("                              Bienvenido a Matematica !!!!!\n");
    verImagen(imagen);
    printf("Por recorte de tiempo no vas a tener clases vamos directo al examen\n");
    printf("Que dios te ayude!!\n");
}

int EjercicioMate1(stImagen imagen)
{

   int rta=0;

    do
    {

        verImagen(imagen);
        printf("\n");
        printf("Resolver: x^2+0=4  el valor de x es \n");
        printf("1:x=1;x=2  2:x=-2;x=2 3:x=-1;x=2\n\n");
        printf("RTA: ");
        fflush(stdin);
        scanf("%i",&rta);
        system("cls");
    }while ( rta > 3 || rta < 1 );

    if (rta==2)
    {
        printf("Rta correcta");
        return 1;
    }
    printf("Rta incorrecta");
    return 0;
}

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
    usleep(500000);
    system("cls");

    verImagen(imagen);
    printf(" _____ \n");
    printf("|     |\n");
    printf("| +6  |\n");
    printf("|_____|\n");
    usleep(500000);
    system("cls");

    verImagen(imagen);
    printf(" _____ \n");
    printf("|     |\n");
    printf("| +9  |\n");
    printf("|_____|\n");
    usleep(500000);
    system("cls");

    verImagen(imagen);
    printf(" _____ \n");
    printf("|     |\n");
    printf("| -2  |\n");
    printf("|_____|\n");
    usleep(500000);
    system("cls");

    verImagen(imagen);
    printf(" _____ \n");
    printf("|     |\n");
    printf("| -4  |\n");
    printf("|_____|\n");
    usleep(500000);
    system("cls");

    verImagen(imagen);
    printf(" _____ \n");
    printf("|     |\n");
    printf("| +3  |\n");
    printf("|_____|\n");
    usleep(500000);
    system("cls");

    verImagen(imagen);
    printf(" _____ \n");
    printf("|     |\n");
    printf("| +6  |\n");
    printf("|_____|\n");
    usleep(500000);
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

    if(tecla == 13){
        pj = i+2;

    }else{
        if(tecla == teclaAbajo && i<opciones-1)
                i++;
            else if(tecla == teclaAbajo && i>opciones-2)
                i = 0;
            else if(tecla == teclaArriba && i>0)
                i--;
            else if(tecla == teclaArriba && i<1)
                i = opciones-1;


            pj=seleccion(i, opciones, a);
    }
    return pj;
}

stpersonaje fotopj (stImagen imagen)
{
    stpersonaje personaje;

    for(int i=0;i<imagen.fila;i++)
    {
        strcpy(personaje.dibujo[i],imagen.dibujo[i]);
    }
    personaje.fila=imagen.fila;

    return personaje;
}

void guardarPartida(char archivo[], stpersonaje a)
{
    FILE* buffer = fopen(archivo, "wb");
    int flag = 0;

        if(buffer){

            flag = fwrite(&a, sizeof(stpersonaje), 1, buffer);

            fclose(buffer);
        }

    if(flag == 1)
        printf("La partida fue guardada exitosamente!\n\n");
    else
        printf("No se pudo guardar la partida, intente nuevamente!\n\n");

}

stpersonaje cargarPartida(char archivo[])
{
    FILE* buffer = fopen(archivo, "rb");
    stpersonaje pj;

    if(buffer){

        fread(&pj, sizeof(stpersonaje), 1, buffer);

        fclose(buffer);
    }
    return pj;
}

void imagenCargaPartida(stpersonaje pj)
{
    verImagen(nombreJuego);

    printf("\n\n                                                Ultima partida\n\n");
    printf("                          -----------------------------------------------------------------------\n");
    printf("                           Nombre: %s                                                            \n", pj.nombre);
    printf("                           Habilidades:                                                          \n");
    printf("                                  Inteligencia: %i                                               \n", pj.inteligencia);
    printf("                                       Carisma: %i                                               \n", pj.habcarisma);
    printf("                                         Cheat: %i                                               \n", pj.habcheat);
    printf("                          -----------------------------------------------------------------------\n\n\n");
    printf("                                                   Desea cargar la partida?\n\n");
}

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

    if(tecla == 13){
        return i;

    }else{

        if(tecla == teclaAbajo && i<1)
                i++;
            else if(tecla == teclaAbajo && i>0)
                i = 0;
            else if(tecla == teclaArriba && i>0)
                i--;
            else if(tecla == teclaArriba && i<1)
                i = 1;


        menuCargaPartida(pj, i);
    }
}


