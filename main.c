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
}stimagen;

///Prototipado

void cargaImagenes (char archivo[],stimagen Imagen[]); /// Archivo de imagen y un arreglo de imagenes cargatodas;
void VerImagen (stimagen imagen);  /// Por parametro la imagen a ver;


int main()
{
    
    return 0;
}

///Carga todas las imagenes del archivo,    Loadind Imagenes ....
void cargaImagenes (char archivo[],stimagen Imagen[])
{
FILE* archi=fopen(archivo,"rb");
int i=0;
    if(archi)
    {
        while(fread(&Imagen[i++],sizeof(stimagen),1,archi)>0)
        {
        }
        fclose(archi);
    };
}

/// Muestra 1 imagen
void VerImagen (stimagen imagen) 
{
    for (int i = 0; i < imagen.fila; i++) {
        printf("%s\n", imagen.dibujo[i]);
    }
}

/// stickman en movimiento
void dibujarStickman(int pasos) {     /// pasos es la cantidad de espacios a moverse(pasar por parametro)
    int pie=0;

   for(int i=0;i!=pasos;i++)
   {
    espacio(i);printf(" O   \n");espacio(i);printf(" |\\  \n");espacio(i);printf(" /)  \n");
    usleep(259000);system("cls");                                                          ///tiempo en que fleccione
    espacio(i);printf(" O   \n");espacio(i);printf("[|-  \n");espacio(i);printf(" |\\  \n");
    usleep(200000);system("cls");                                                         ///tiempo a que pase de cuadro
    }
}
///adelantamiento de stickman
void espacio (int movimiento)
{
    for(int i=0;i<movimiento;i++)
    {
        printf(" ");                   ///Espacio a moverse
    }
}


