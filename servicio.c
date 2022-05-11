#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "servicio.h"

int listarServicios(eServicio servicios[], int tam){
int todoOk = 0;

    if(servicios != NULL && tam > 0){
     // system("cls");
        printf("          *** Listado de Servicios ***\n\n");
        printf("   Id               Descripcion          Precio\n");
        printf("-----------------------------------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %20s         %.2f\n", servicios[i].idServicio, servicios[i].descripcionServicio, servicios[i].precio);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[]){
int todoOk = 0;

    if(descripcion && tam ){


       for(int i=0;i<tam;i++){
            if(id == servicios[i].idServicio){
               strcpy(descripcion, servicios[i].descripcionServicio);
               todoOk = 1;
            }
       }
    }
  return todoOk;
}
