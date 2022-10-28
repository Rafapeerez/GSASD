#include "calculadora.h"
#include <time.h>

int main(int argc, char *argv[]){

    numeros numeros;
    printf("Introduce el primer operando: ");
	scanf("%d", &numeros.a);

	printf("Introduce el segundo operando: ");
	scanf("%d", &numeros.b);


    double resultado = 0;
    clock_t p, f;

    p = clock();
    for(int cont = 0;cont < 100000;cont++){
        resultado = resultado + sumarLocal(&numeros);
    }
    f = clock();

	printf("El resultado de la suma es: %f\n", resultado);

    double tiempo = (double)(f - p) / CLOCKS_PER_SEC;
	printf("El tiempo tardado ha sido de %f segundos.\n", tiempo);

}