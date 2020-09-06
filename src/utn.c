#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int utn_getEntero(int* pOperador,char* pTexto, char* pTextoError, int intentos)
{
	int retorno=-1;
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
			break;
		}
	}

	if (intentosFallidos<=intentos)
	{
		retorno=0;
		*pOperador=operadorBuffer;
	}

	return retorno;
}

void calcularSuma(){
	printf("\nHola suma");
}
void calcularResta(){
	printf("\nHola resta");
}
void calcularDivision(){
	printf("\nHola division");
}
void calcularMultiplicacion(){
	printf("\nHola multiplicacion");
}
void calcularFactorial(){
	printf("\nHola factorial");
}


