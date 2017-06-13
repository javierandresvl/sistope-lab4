#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

//////// --ESTRUCTURAS-- ///////
struct celda{
    int dato;
    int final;  /* valor 1 para indicar que el nodo es el final de la lista */
    struct celda *sgte;
};
typedef struct celda lista;

//////// -- VAR. GLOBALES -- ///////


//////// --FUNCIONES-- ////////

/*
    Procedimiento que hace la llamada a getopt para obtener las opciones y
    parametros ingresados por la terminal.
    @parametros ...
*/
void call_getopt(int argc, char** argv, int *m, char **archivo_entrada, char **archivo_salida);

/*
    Funcion que verifica si un string representa un numero o no, entrega 0 si es
    un numero y 1 si no.
    @param number string para verificar.
    @return resultado de la verificacion.
*/
int isInt(char *number);

/*

*/
lista *crear();

/*

*/
lista *insertar_nodo(lista *L);

/*

*/
int largo_lista(lista *L);

/*

*/
lista *insertar_dato(int x, int p, lista *L);

/*

*/
void mostrar(lista *L);

#endif

