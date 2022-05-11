#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{

    int idTipo;
    char descripcionTipo[20];

}eTipo;

#endif // TIPO_H_INCLUDED

int validarTipo(eTipo tipos[], int tam, int id);
int buscarTipo(eTipo tipos[], int tam, int id, int* pIndice);
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);
int listarTipos(eTipo tipos[], int tam);
