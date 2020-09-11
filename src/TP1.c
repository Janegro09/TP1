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
#define ERRORDATO "Error dato invalido"
#define TEXTOCALCULADORA "Ingrese un numero para la operacion:\n 1) + (suma) \n 2) - (resta) \n 3) * (multiplicacion) \n 4) / (division) \n 5) ! (factorial) \n 6) Todas las operaciones anteriores \n"
#define MAXIMO 50000
#define MINIMO -50000

int main(void) {

	setbuf(stdout,NULL);
	int operadorA;
	int operadorB;
	int resultadoA;
	int resultadoB;
	int operador;
	int resultadoOperacion;
	char continuar='N';

	do
	{
		resultadoA=utn_getEntero("Ingrese el primer operando: ",ERRORSEGUNDOINTENTOENTERO , CANTINTENTOS, MAXIMO, MINIMO, &operadorA);
		if(resultadoA==0)
		{
			resultadoB=utn_getEntero("Ingrese el segundo operando: ", ERRORSEGUNDOINTENTOENTERO, CANTINTENTOS, MAXIMO, MINIMO, &operadorB);
			if(resultadoB==0)
			{
				printf("Ingresaste %d y %d :\n", operadorA, operadorB);

				do{
				resultadoOperacion=utn_getEntero(TEXTOCALCULADORA,ERRORSEGUNDOINTENTOENTERO , 0, 6, 1,&operador);
				} while(resultadoOperacion!=0);

					switch (operador)
					{
						case 1:
							utn_calcularSuma(operadorA, operadorB);
							break;
						case 2:
							utn_calcularResta(operadorA, operadorB);
							break;
						case 3:
							utn_calcularMultiplicacion(operadorA, operadorB);
							break;
						case 4:
							utn_calcularDivision(operadorA, operadorB);
							break;
						case 5:
							utn_calcularFactorial(operadorA);
							break;
						case 6:
							utn_calcularSuma(operadorA, operadorB);
							utn_calcularResta(operadorA, operadorB);
							utn_calcularMultiplicacion(operadorA, operadorB);
							utn_calcularDivision(operadorA, operadorB);
							utn_calcularFactorial(operadorA);
							break;
						default:
							printf("Error - Operador invalido \n");
							break;
					}
			printf("Ingrese S para continuar realizando operaciones, para salir cualquier otro valor\n");
			__fpurge(stdin);
			scanf("%c",&continuar);
		} else {
			printf(ERRORDATO);
		}
	} else {
		printf(ERRORDATO);
	}
	} while (continuar=='S');

	return EXIT_SUCCESS;
}
