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
stImagen nombreJuego;

///PROTOTIPADO
void inicio(int i);
void mensaje(int i);
void cargaImagenes (char archivo[],stImagen imagen[]); /// Archivo de imagen y un arreglo de imagenes cargatodas;
void verImagen (stImagen imagen);  /// Por parametro la imagen a ver;
void opcionesInicio(int i);
void opcionesJuego(int i);
void mensJuego(int i);
void menuOpciones(int i);

int main()
{
    char imagenesPepo[] = {"ImagenesEstaticas"};
    stImagen arreglo[30];

    cargaImagenes(imagenesPepo, arreglo);
    nombreJuego = arreglo[0];
    inicio(0);


    return 0;
}

void inicio(int i)
{
    char tecla;

    verImagen(nombreJuego);
    mensaje(i);

    tecla = getch();
    system("cls");

    if(tecla == 13)
        opcionesInicio(i);
    else{
        if(tecla == teclaAbajo && i<3)
                i++;
            else if(tecla == teclaAbajo && i==3)
                i = 0;
            else if(tecla == teclaArriba && i>0)
                i--;
            else if(tecla == teclaArriba && i==0)
                i = 3;

        inicio(i);
    }
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

void opcionesInicio(int i)
{
    if(i==0)
        printf("Comienza el desafio\n\n");
    else if(i==1)
        printf("Cargar partida\n\n");
    else if(i==2)
        opcionesJuego(0);
    else if(i==3)
        printf("Gracias por jugar, vuelva pronto! \n\n");
}

void opcionesJuego(int i)
{
    char tecla;

    mensJuego(i);

    tecla = getch();
    system("cls");

    if(tecla == 13)
        menuOpciones(i);
    else{
        if(tecla == teclaAbajo && i<3)
                i++;
            else if(tecla == teclaAbajo && i==3)
                i = 0;
            else if(tecla == teclaArriba && i>0)
                i--;
            else if(tecla == teclaArriba && i==0)
                i = 3;

        opcionesJuego(i);
    }
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
        printf("Paraaaaaa, iba a tener sonido jaja\n\n");
        system("pause");
        system("cls");
        opcionesJuego(i);
    }else if(i==1){
        printf("Graficos:\n     Pestanear siempre: Activo\n\n");
        system("pause");
        system("cls");
        opcionesJuego(i);
    }else if(i==2){
        printf("Idioma:\n       Espaninglish: siempre\n\n");
        system("pause");
        system("cls");
        opcionesJuego(i);
    }else if(i==3){
        inicio(2);
    }
}
