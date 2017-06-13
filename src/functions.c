#include "functions.h"

void call_getopt(int argc, char** argv, int *m, char **archivo_entrada, char **archivo_salida){
	int c;
	char *m_value, *entrada_value, *salida_value;


	//Obtener parametros.
	opterr = 0;

	if(argc <= 6){
		printf("Se deben ingresar opciones (uso: -m <numero de marcos> -e <nombre archivo entrada> -o <nombre archivo salida>)\n");
		exit(1) ;
	}

	while((c = getopt(argc, argv, "m:e:o:")) != -1){
		switch (c) {
			case 'm':
				m_value = optarg;
				break;
			case 'e':
				entrada_value = optarg;
				break;
			case 'o':
				salida_value = optarg;
				break;
			case '?':
				if(optopt == 'm'){
					fprintf(stderr, "Opcion -m requiere un argumento.\n");
				}
				else if(optopt == 'e'){
					fprintf(stderr,"Opcion -e requiere un argumento\n");
				}
				else if(optopt == 'o'){
					fprintf(stderr,"Opcion -o requiere un argumento\n");
				}
				else if (isprint(optopt)) {
					fprintf(stderr, "Opcion -%c desconocida.\n", optopt);
				}
				else{
					fprintf(stderr, "Opcion desconocida '\\x%x'.\n", optopt);
				}
				exit(1);
			default:
				abort();
		}
	}

	//Procesar parametros.
	if(!isInt(m_value)){
		printf("El parametro ingresado para el numero de marcos no es valido\n");
		exit(1);
	}


	//retorno de parametros por referencia.
	*m = atoi(m_value);
	*archivo_entrada = entrada_value;
	*archivo_salida = salida_value;
}

int isInt(char *number){
 	int i, c;

 	for(i=0;i<strlen(number); i++){
    		c = number[i];
    		if(c < 48 || c > 57 || c == 0){
      			return 0;
    		}
  	}
  	return 1;
}

lista *crear()
{
	/* el primer nodo de la lista es la cabecera de la lista */
	lista *L=malloc(sizeof(lista));
	L->final = 1;
	L->dato = -10000;
	L->sgte=L;
	return L;
}

lista *insertar_nodo(lista *L)
{	
	lista *aux=L;
	lista *cabecera = L;

	while(aux->final != 1)
	{
		aux = aux->sgte;
	}

	aux->final = 0;
	aux->sgte = crear();
	aux->sgte->dato = -10000;
	aux->sgte->final = 1;
	aux->sgte->sgte = cabecera;

	return L;
}

int largo_lista(lista *L)
{	
	/* 
	la cabecera no cuenta para el largo de una lista.
	*/
	lista *aux = L;
	int contador = 0;

	while(aux->final != 1)
	{
		contador++;
		aux = aux->sgte;
	}

	return contador;
}

lista *insertar_dato(int x, int p, lista *L){

	/* El primer elemento de la lista que no sea la cabecera tiene posicion 0 */
	lista *aux = L->sgte;
	int largo = largo_lista(L);
	int i;

	if(p >= largo)
	{	
		/*  Si la posicion a insertar el dato supera el largo de la lista */
		printf("No se ha insertado el dato\n");
		return L;
	}

	for(i = 0; i < p; i++)
	{
		aux = aux->sgte;
	}

	aux->dato = x;
	return L;
}

void mostrar(lista *L)
{
	lista *aux=L->sgte;
	while(aux->final != 1){
		printf("%i - ", aux->dato);
		aux=aux->sgte;
	}
	printf("%i - ", aux->dato);
	printf("repeat\n");
}