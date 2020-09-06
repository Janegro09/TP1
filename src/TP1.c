/*
 ============================================================================
 Name        : TP1.c
 Author      : Javier Sosa
 Division    : 1-H
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

#define CANTINTENTOS 3
#define ERRORSEGUNDOINTENTOENTERO "Error - Ingrese un numero valido: "
#define ERRORDATO "Error en el numero ingresado"

int main(void) {

	setbuf(stdout,NULL);
	int operadorA;
	int operadorB;
	int resultadoA;
	int resultadoB;

	resultadoA=utn_getEntero(&operadorA,"Ingrese el primer operando: ",ERRORSEGUNDOINTENTOENTERO , CANTINTENTOS);
	if(resultadoA==0)
	{
		resultadoB=utn_getEntero(&operadorB,"Ingrese el segundo operando: ", ERRORSEGUNDOINTENTOENTERO, CANTINTENTOS);
		if(resultadoB==0)
		{
			printf("Ingresaste %d y %d :", operadorA, operadorB);
			utn_calcularSuma(operadorA, operadorB);
			utn_calcularResta(operadorA, operadorB);
			utn_calcularMultiplicacion(operadorA, operadorB);
			utn_calcularDivision(operadorA, operadorB);
			utn_calcularFactorial(operadorA);
		} else {
			printf(ERRORDATO);
		}
	} else {
		printf(ERRORDATO);
	}
	return EXIT_SUCCESS;
}
