/*Definicion de la estructura de paramatros de entrada de las funciones*/

struct numeros{
    int a;
    int b;
};

program CALCULADORA_PROG {
    version CALCULADORA_VERS {
        int SUMA(numeros) = 1;
        int MULTIPLICACION(numeros) = 2;
        int RESTA(numeros) = 3;
        int DIVISION(numeros) = 4;
        int POTENCIA(numeros) = 5;
    } = 1;        /*version 1 de la calculadora*/
} = 0x20000001;   /* numero de programa = 0x20000001*/
			       /* 0x20000000 - 0x3fffffff para usuarios*/