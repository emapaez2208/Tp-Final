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

    printf("retorne %i", menu);


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


            moverse(i, opciones, funcActual, funcSiguiente, a);
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
    int algo = 32;

    if(i==0){
        printf("Retorno 1 para nueva partida\n\n");
        algo = 1;
    }else if(i==1){
        printf("retorno 2 para Cargar partida\n\n");
        algo = 2;
    }else if(i==2)
        moverse(0, 4, mensJuego, menuOpciones, nombreJuego);
    else if(i==3)
        printf("Gracias por jugar, vuelva pronto! \n\n");

    return algo;

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
