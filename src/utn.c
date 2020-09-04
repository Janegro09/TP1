#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int utn_getEntero(int* pOperador,char* pTexto, char* pTextoError, int pIntentos)
{
	int retorno=-1;
	int* operadorBuffer;
	int resultadoScan;

	printf("%s",pTexto);
	__fpurge(stdin);
	resultadoScan=scanf("%d",operadorBuffer);
	while(resultadoScan ==0)
	{
		printf("%s",pTextoError);
		__fpurge(stdin);
		resultadoScan=scanf("%d",operadorBuffer);
	}
	printf("Los intentos son %d",pIntentos);
	retorno=0;
	*pOperador=*operadorBuffer;

	return retorno;

}

