#ifndef _CALCULADORA_EJ2_
#define _CALCULADORA_EJ2_

#include <rpc/rpc.h>

struct numeros {
    int a;
    int b;
};
typedef struct numeros numeros;

int sumarLocal(numeros *numeros){
    return numeros->a + numeros->b;
}

#endif