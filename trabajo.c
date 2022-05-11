#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajo.h"

int inicializarTrabajo(eTrabajo trabajos[], int tam)
{
    int todoOk = 0;
    if(trabajos != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            trabajos[i].estaVacio = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarTrabajoLibre(eTrabajo trabajos[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(trabajos != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( trabajos[i].estaVacio )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaTrabajo(eTrabajo trabajos[], int tam_trabajos, eMascota mascotas[], int tam_mascota, eTipo tipos[], int tam_tipos, eServicio servicios[], int tam_servicio, eColor colores[], int tam_color, int* pIdTrabajo)
{
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;

    if(trabajos && tam_trabajos && mascotas && tam_mascota && pIdTrabajo && tipos && servicios && tam_servicio && tam_tipos && colores && tam_color)
    {
        buscarTrabajoLibre(trabajos, tam_trabajos, &indice);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema para cargar un nuevo trabajo\n");
        }
        else
        {
            listarMascotas(mascotas, tam_mascota, tipos, tam_tipos, colores, tam_color);
            printf("Ingrese el id de la mascota: \n");
            scanf("%d", &nuevoTrabajo.idMascota);
            buscarMascota(mascotas, tam_mascota, nuevoTrabajo.idMascota, &indice);
            while(indice == -1)
            {
                printf("Error. Reingrese el id de la mascota: \n");
                scanf("%d", &nuevoTrabajo.idMascota);
                buscarMascota(mascotas, tam_mascota, nuevoTrabajo.idMascota, &indice);
            }

            listarServicios(servicios, tam_servicio);
            printf("Ingrese el id del servicio: ");
            scanf("%d", &nuevoTrabajo.idServicio);
            while(nuevoTrabajo.idServicio <20000 || nuevoTrabajo.idServicio>20002)
            {
                printf("Error. Reingrese el id del servicio: \n");
                scanf("%d", &nuevoTrabajo.idServicio);

            }

            trabajos[indice].idTrabajo= *pIdTrabajo;
            trabajos[indice].idMascota= nuevoTrabajo.idMascota;
            trabajos[indice].idServicio= nuevoTrabajo.idServicio;
            trabajos[indice].estaVacio=0;

            (*pIdTrabajo)++;

            todoOk=1;
        }
    }
    else
    {
        printf("Ocurrio un problema con los parametros\n");
    }
    return todoOk;
}

int mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tam_servicio)
{
    int todoOk = 0;
    char descServicio[20];

    if(servicios && tam_servicio )
    {
        cargarDescripcionServicio( servicios, tam_servicio, unTrabajo.idServicio, descServicio);

        printf("  %4d            %4d         %15s      \n", unTrabajo.idTrabajo, unTrabajo.idMascota, descServicio);


        todoOk = 1;
    }
    return todoOk;
}

int listarTrabajos(eTrabajo trabajos[], int tam_trabajo, eServicio servicios[], int tam_servicio)
{
    int todoOk = 0;
    int flag = 0;
    if(trabajos != NULL && tam_trabajo > 0 && servicios && tam_servicio )
    {


        system("cls");
        printf("           *** Listado de Trabajos ***\n\n");
        printf(" idTrabajo      idMascota            Servicio \n");
        printf("-------------------------------------------------\n");
        for(int i=0; i < tam_trabajo; i++)
        {
            if( !trabajos[i].estaVacio )
            {
                mostrarTrabajo(trabajos[i], servicios, tam_servicio);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay mascotas en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int hardcodearTrabajos(eTrabajo trabajos[], int tam_trabajo, int cantidad,int* idTrabajo)
{
    int todoOk=0;

    if(trabajos && tam_trabajo && cantidad && idTrabajo)
    {
        int idMascotas[10]= {3,4,9,0,1,5,7,2,6,8};
        int idServicios[10]= {20002,20001,20000,20002,20001,20000,20000,20001,20000,20001};

        for(int i=0; i<cantidad ; i++)
        {
            trabajos[i].idTrabajo= *idTrabajo;
            trabajos[i].idMascota= idMascotas[i];
            trabajos[i].idServicio= idServicios[i];
            trabajos[i].estaVacio= 0;
            (*idTrabajo)++;
        }
        todoOk=1;
    }

    return todoOk;
}
