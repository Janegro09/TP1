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

	resultadoA=utn_getEntero(&operadorA,"Ingrese el primer operando: ", "Error - Ingrese un numero valido", 3);

	if(resultadoA==0)
	{
		resultadoB=utn_getEntero(&operadorB,"Ingrese el segundo operando: ", "Error - Ingrese un numero valido", 3);
		if(resultadoB==0)
		{
			printf("Ingresaste %d y %d :", operadorA, operadorB);
			calcularSuma(operadorA, operadorB);
			calcularResta(operadorA, operadorB);
			calcularMultiplicacion(operadorA, operadorB);
			calcularDivision(operadorA, operadorB);
			calcularFactorial(operadorA);
		} else {
			printf("Error en el segundo operando");
		}
	} else {
		printf("Error en el primer operando");
	}

	return EXIT_SUCCESS;
}
