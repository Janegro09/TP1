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
#define BARRA printf("\n**********************************\n")
//#define MAXIMO 50000
//#define MINIMO -50000

int main(void) {

	setbuf(stdout,NULL);
	int operadorA;
	int operadorB;
	int resultadoSumar;
	int resultadoRestar;
	int resultadoMultiplicar;
	float resultadoDividir;
	int resultadoFactorialA;
	int resultadoFactorialB;
	int banderaOperadorA=0;
	int banderaOperadorB=0;
	int banderaOperacionesRealidas=0;
	int validarDivision;
	int validarFactorialA;
	int validarFactorialB;
	int opcionElegida;
	int continuar=0;
	int resultadoOpcionMenuElegida;

	printf("Bienvenido al TP1-Calculadora, seleccionà una opciòn\n");
	do {

		if(banderaOperadorA==0)
		{
			printf("1) Ingresar 1er operando (A=x) \n");
		} else {
			printf("1) Ingresar 1er operando (A=%d) \n",operadorA);
		}
		if(banderaOperadorB==0)
		{
			printf("2) Ingresar 2do operando (B=y) \n");
		} else {
			printf("2) Ingresar 2do operando (B=%d) \n",operadorB);
		}
		printf("3) Calcular todas las operaciones\n");
		printf("4) Informar resultados\n");
		printf("5) Salir\n");

		resultadoOpcionMenuElegida=utn_getEntero("Opcion elegida:", "Error en el dato ingresado\n", CANTINTENTOS, 5, 1, &opcionElegida);
		if(resultadoOpcionMenuElegida==0)
		{
			switch (opcionElegida)
			{
			case 1:
				BARRA;
				utn_getEnteroSinMaxMin("Ingrese el primer operando", "Error en el dato ingresado", CANTINTENTOS, &operadorA);
				banderaOperadorA=1;
				break;
			case 2:
				BARRA;
				utn_getEnteroSinMaxMin("Ingrese el segundo operando", "Error en el dato ingresado", CANTINTENTOS, &operadorB);
				banderaOperadorB=1;
				break;
			case 3:
				BARRA;
				if(banderaOperadorA!=0 && banderaOperadorB!=0)
				{
					utn_calcularSuma(operadorA, operadorB, &resultadoSumar);
					utn_calcularResta(operadorA, operadorB, &resultadoRestar);
					utn_calcularMultiplicacion(operadorA, operadorB, &resultadoMultiplicar);
					validarDivision=utn_calcularDivision(operadorA, operadorB, &resultadoDividir);
					validarFactorialA=utn_calcularFactorial(operadorA, &resultadoFactorialA);
					validarFactorialB=utn_calcularFactorial(operadorB, &resultadoFactorialB);
					banderaOperacionesRealidas=1;
					printf("Calculaste todas las operaciones\n");
				} else {
					printf("Tenes que ingresar los dos operadores para realizar los calculos\n");
				}
				break;
			case 4:
				BARRA;
				if(banderaOperadorA!=0 && banderaOperadorB!=0 && banderaOperacionesRealidas!=0)
				{
					printf("El resultado de %d + %d es: %d\n", operadorA, operadorB, resultadoSumar);
					printf("El resultado de %d - %d es: %d\n", operadorA, operadorB, resultadoRestar);
					printf("El resultado de %d * %d es: %d\n", operadorA, operadorB, resultadoMultiplicar);
					if(validarDivision==0)
					{
						printf("El resultado de %d / %d es: %.2f\n", operadorA, operadorB, resultadoDividir);
					} else {
						printf("No es posible dividir por cero\n");
					}
					if(validarFactorialA==0 && validarFactorialB==0)
					{
						printf("El factorial de %d! es: %d y el factorial de %d! es: %d\n", operadorA, resultadoFactorialA, operadorB, resultadoFactorialB);
					} else {
						printf("No es posible realizar el factorial de numeros negativos\n");
					}
					banderaOperadorA=0;
					banderaOperadorB=0;
					BARRA;
				} else {
					printf("Tenes que ingresar los dos operadores para realizar los calculos y despues realizar los calculos para imprimir los resultados\n");
				}
				break;
			case 5:
				continuar=1;
				break;
			default:
				BARRA;
				printf("Error al tomar la opcion\n");
				break;
			}
		} else {
			printf("Te quedaste sin intentos\n");
		}
	} while (continuar!=1 && resultadoOpcionMenuElegida==0);


	return EXIT_SUCCESS;
}
