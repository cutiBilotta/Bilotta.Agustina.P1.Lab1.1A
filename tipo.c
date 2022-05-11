#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipo.h"

int buscarTipo(eTipo tipos[], int tam, int id, int* pIndice)
{
    int todoOk = 0;
    if(tipos != NULL && tam > 0 && pIndice != NULL)
    {
        *pIndice = -1;
        for(int i=0; i < tam; i++)
        {
            if(tipos[i].idTipo == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarTipo(eTipo tipos[], int tam, int id)
{
    int esValido = 0;
    int indice;

    buscarTipo(tipos, tam, id, &indice);

    if(indice != -1)
    {
        esValido = 1;
    }
    return esValido;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[])
{
    int todoOk = 0;

    if(descripcion && tam )
    {
        for(int i=0; i<tam; i++)
        {
            if(id == tipos[i].idTipo)
            {
                strcpy(descripcion, tipos[i].descripcionTipo);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}


int listarTipos(eTipo tipos[], int tam)
{
    int todoOk = 0;

    if(tipos != NULL && tam > 0)
    {

        printf("   *** Lista de Tipos  ***   \n\n");
        printf("   Id      Descripcion\n");
        printf("--------------------------\n");
        for(int i=0; i < tam; i++)
        {
            printf("   %4d    %10s\n", tipos[i].idTipo, tipos[i].descripcionTipo);
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}
