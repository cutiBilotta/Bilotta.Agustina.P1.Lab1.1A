#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int idColor;
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

int validarColores(eColor colores[], int tam, int id);
int buscarColor(eColor colores[], int tam, int id, int* pIndice);
int listarColores(eColor colores[], int tam);
int cargarDescripcionColor(eColor colores[], int tam, int id, char descripcion[]);
