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

/// CONSTANTES
const char teclaArriba = 'w', teclaAbajo = 's';
stImagen nombreJuego, imagenVacia;
int variableSonido = 1;

///PROTOTIPADO
int moverse(int i, int opciones, void funcActual(), int funcSiguiente(), stImagen a);
void mensaje(int i);
void cargaImagenes (char archivo[],stImagen imagen[]); /// Archivo de imagen y un arreglo de imagenes cargatodas;
void verImagen (stImagen imagen);  /// Por parametro la imagen a ver;
int opcionesInicio(int i);
void mensJuego(int i);
void menuOpciones(int i);
void reproducirSonido(int i);
void cambiarSonido();


int main()
{
    char imagenesPepo[] = {"ImagenesEstaticas"};
    stImagen arreglo[30];
    int menu;

    cargaImagenes(imagenesPepo, arreglo);
    nombreJuego = arreglo[0];
    menu = moverse(0, 4, mensaje, opcionesInicio, nombreJuego);

    do
    {

        switch(menu)
        {
        case 1:
            {
                Textoinicia(arreglo);
                system("pause");
                system("cls");
                ///--------aca menu con arreglo[3],arreglo[4],arreglo[5],arreglo[6]-------
                verImagen(arreglo[2]);
                verImagen(arreglo[3]);
                verImagen(arreglo[4]);
                verImagen(arreglo[5]);
                system("pause");
                system("cls");

                ///guardar el elegigo en la struct de personaje
                printf("Pedir nombre, pedir edad, poner estadisticar\n\n");
                printf("Se guarda el personaje\n\n");

                system("pause");
                system("cls");

                menu=3;

                break;
            }
        case 2:
            {
                verImagen(arreglo[6]);
                verImagen(arreglo[7]);
                verImagen(arreglo[8]);
                verImagen(arreglo[9]);
                printf("Aca se cargo la partida\n");
                printf("Aca se muestra el personaje guardado\n\n");

                system("pause");
                system("cls");
                menu=3;

                break;
            }
        case 3:
            {
                int aux;
                verImagen(arreglo[10]);
                printf("se va a el pasillo\n");
                printf("Poner  donde vamos \n");
                printf("4 makano  5 carmelia cantuccini    6 ana maria Rosa  7 beretche \n\n");
                scanf("%i",&aux);
                if(aux<8 && aux>3)
                {
                    menu=aux;
                }



                system("pause");
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
        case 9:
            {
                printf("Felicidades pasaste de etapa\n");
                system("pause");
                system("cls");
                menu=8;
                break;
            }
        default:
            {
                break;
            }

        }

    }while(menu!=8);


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

int opcionesInicio(int i)
{
    if(i==0){
        printf("Retorno 1 para nueva partida\n\n");
        return 1;
    }else if(i==1){
        printf("retorno 2 para Cargar partida\n\n");
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
                      printf("Tu habilidad para saltarte las reglas te permiten safas el ejercicio\n");
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
