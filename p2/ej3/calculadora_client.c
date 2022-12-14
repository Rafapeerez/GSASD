/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calculadora.h"
#include <time.h>


int
calculadora_prog_1(char *host, char* operacion, struct numeros numeros)
{
	CLIENT *clnt;
	int  *result_1;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA_PROG, CALCULADORA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	if(strcmp(operacion, "suma") == 0){
		result_1 = suma_1(&numeros, clnt);
		if (result_1 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
	}
	else if(strcmp(operacion, "multiplicacion") == 0){
		result_1= multiplicacion_1(&numeros, clnt);
		if (result_1 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
	}
	else if(strcmp(operacion, "resta") == 0){
		result_1 = resta_1(&numeros, clnt);
		if (result_1 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
	}
	else if(strcmp(operacion, "division") == 0){
		result_1 = division_1(&numeros, clnt);
		if (result_1 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
	}
	/*else if(strcmp(operacion, "potencia") == 0){
		result_2 = potencia_1(&numeros, clnt);
		if (result_2 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
	}*/
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
	return *result_1;
}

void menu(){
	printf("|---------------------------------------------------------------| \n");
	printf("|                            MENU                               | \n");
	printf("|---------------------------------------------------------------| \n");
	printf("| A continuación, le muestro las opciones que tiene para elegir.| \n");
	printf("| 1. suma                                                       | \n");
	printf("| 2. multiplicacion                                             | \n");
	printf("| 3. resta                                                      | \n");
	printf("| 4. division                                                   | \n");
	printf("| Por favor, escriba la opcion que desee.                       | \n");
	printf("|---------------------------------------------------------------| \n");
}

int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	struct numeros numeros;
	char operacion[40];

	printf("Introduce el primer operando: ");
	scanf("%d", &numeros.a);

	printf("Introduce el segundo operando: ");
	scanf("%d", &numeros.b);

	menu();

	printf("Indica la operacion a realizar: ");
	scanf("%s", operacion);

	host = argv[1];

	double resultado;
	clock_t p, f;

    p = clock();
    for(int cont = 0;cont < 100000;cont++){
        resultado = resultado + calculadora_prog_1(host, operacion, numeros);
    }
    f = clock();

	double tiempo = (double)(f - p) / CLOCKS_PER_SEC;
	printf("El resultado de la %s de los dos numeros introducidos es: %f \n", operacion, resultado);
	printf("El tiempo tardado ha sido de %f segundos.\n", tiempo);
	
exit (0);
}


