#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"

int buscarColor(eColor colores[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(colores != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(colores[i].idColor == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarColores(eColor colores[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarColor(colores, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}


int listarColores(eColor colores[], int tam){
int todoOk = 0;

    if(colores != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de Colores  ***    \n\n");
        printf("   Id      Descripcion\n");
        printf("--------------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s\n", colores[i].idColor, colores[i].nombreColor);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionColor(eColor colores[], int tam, int id, char descripcion[])
{
    int todoOk = 0;

    if(descripcion && tam && colores)
    {
        for(int i=0; i<tam; i++)
        {
            if(id == colores[i].idColor)
            {
                strcpy(descripcion, colores[i].nombreColor);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}
