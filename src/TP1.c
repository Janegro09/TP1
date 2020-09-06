/*
 ============================================================================
 Name        : TP1.c
 Author      : Javier Sosa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"


int main(void) {

	setbuf(stdout,NULL);
	int operadorA;
	int operadorB;
	int resultadoA;
	int resultadoB;

	resultadoA=utn_getEntero(&operadorA,"Ingrese el numero\n", "Error - Ingrese un numero valido\n", 3);

	if(resultadoA==0)
	{
		resultadoB=utn_getEntero(&operadorB,"Ingrese el numero\n", "Error - Ingrese un numero valido\n", 3);
		if(resultadoB==0)
		{
			printf("el primer numero es %d y el segundo %d", operadorA, operadorB);
		} else {
			printf("Error en el segundo operando");
		}
	} else {
		printf("Error en el primer operando");
	}

	return EXIT_SUCCESS;
}
