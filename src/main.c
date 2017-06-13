#include "functions.h"

/*
	Laboratorio 4 - Sistemas operativos
  	USACH 1-2017
  	Integrantes:
  	- Kevin Alvarez
  	- Javier Vasquez
  	Descripción:
  	El presente laboratorio consiste en recrear politicas
  	de reemplazo de páginas, y establecer diferencias.
*/

int main(int argc, char** argv)
{

	int n,m;
	int Dflag;
	char *nombreArchivo = (char*)malloc(sizeof(char) * 100);

	/*  Realizo el get opt de los valores de entrada hechos por la consola */
	call_getopt(argc, argv, &tamanoTablero, &Dflag, &nombreArchivo);

	/* inicio ciertas variables globales, como el arreglo de los guerreros */
	

	return 0;
}
