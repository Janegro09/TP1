#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int utn_getEntero(int* pOperador,char* pTexto, char* pTextoError, int intentos)
{
	int retorno=1;
	int banderaIntentos=1;
	int operadorBuffer;
	int resultadoScan;
	int intentosFallidos=0;

	printf("%s",pTexto);
	__fpurge(stdin);
	resultadoScan=scanf("%d",&operadorBuffer);
	while(resultadoScan ==0)
	{
		if(intentosFallidos<intentos)
		{
			printf("%s",pTextoError);
			__fpurge(stdin);
			resultadoScan=scanf("%d",&operadorBuffer);
			intentosFallidos++;
		} else {
			banderaIntentos=0;
			break;
		}
	}
	if(banderaIntentos==1){
		retorno=0;
		*pOperador=operadorBuffer;
	}
	return retorno;
}

void utn_calcularSuma(int operador1, int operador2){
	int suma;
	suma = operador1+operador2;
	printf("\nEl resultado de %d + %d es: %d",operador1,operador2,suma);
}

void utn_calcularResta(int operador1, int operador2){
	int resta;
	resta = operador1-operador2;
	printf("\nEl resultado de %d - %d es: %d",operador1,operador2,resta);
}

void utn_calcularDivision(int operador1, int operador2){
	float division;
	if(operador2 == 0)
	{
		printf("\nNo se puede dividir %d por %d",operador1,operador2);
	}
	else {
		division=(float)operador1/operador2;
		printf("\nEl resultado de %d / %d es: %.2f", operador1, operador2, division);
	}
}

void utn_calcularMultiplicacion(int operador1, int operador2){
	int multiplicacion;
	multiplicacion=operador1*operador2;
	printf("\nEl resultado de %d * %d es %d", operador1, operador2, multiplicacion);
}

void utn_calcularFactorial(int operador){
	int factorial=1;
	if(operador>=0)
	{
		for(int i=0;i<operador;i++)
		{
			factorial=factorial*(i+1);
		}
		printf("\nEl resultado de %d! es %d: ", operador, factorial);
	} else {
		printf("\nNo se puede realizar el factorial de un numero negativo");
	}
}
