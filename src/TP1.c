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

	utn_getEntero(&operadorA,"Ingrese el numero\n", "Error - Ingrese un numero valido\n", 3);

	return EXIT_SUCCESS;
}
