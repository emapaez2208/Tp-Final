#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

///PROTOTIPADO
void inicio(int i);
void mensaje(int i);


int main()
{

    inicio(0);


    return 0;
}

void inicio(int i)
{
    char tecla;

    mensaje(i);

    tecla = getch();
    system("cls");

    if(tecla == 13)
        printf("termina");
    else{
        if(tecla == 115 && i<2)
                i++;
            else if(tecla == 115 && i==2)
                i = 0;
            else if(tecla == 119 && i>0)
                i--;
            else if(tecla == 119 && i==0)
                i = 2;

        inicio(i);
    }
}

void mensaje(int i)
{
    if(i==0){
        printf("--> Mensaje\n");
        printf("    Mensaje\n");
        printf("    Mensaje\n");
    }else if(i==1){
        printf("    Mensaje\n");
        printf("--> Mensaje\n");
        printf("    Mensaje\n");
    }else if(i==2){
        printf("    Mensaje\n");
        printf("    Mensaje\n");
        printf("--> Mensaje\n");
    }
}
