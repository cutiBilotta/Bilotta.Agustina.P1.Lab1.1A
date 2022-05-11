#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{

    int idServicio;
    char descripcionServicio[25];
    float precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED

int listarServicios(eServicio servicios[], int tam);
int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[]);
