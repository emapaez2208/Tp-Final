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

void cargaImagenes (char archivo[],stimagen Imagen[]); /// Archivo de imagen
void VerImagen (stimagen imagen);  /// Por parametro la imagen a ver;


int main()
{
    
    return 0;
}


void VerImagen (stimagen imagen) 
{
    for (int i = 0; i < imagen.fila; i++) {
        printf("%s\n", imagen.dibujo[i]);
    }
}
