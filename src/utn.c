#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
/**
 * \brief Solicita un entero al usuario y valida un rango max y min
 * \param char* pTexto, es el mensaje a ser mostrado al usuario
 * \param char* pTextoError, es el mensaje de error a ser mostrado al usuario
 * \param reintentos, cantidad de oportunidades para ingresar el dato
 * \param int pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int maximo, valor maximo admitido
 * \param int minimo, valor minimo admitido
 * \return (1) Error / (0) Tomo el entero ok
 */

int utn_getEntero(char* pTexto, char* pTextoError, int reintentos, int maximo, int minimo, int* pOperador)
{

	int retorno=-1;
	int operadorBuffer;
	int resultadoScan;

	if(
		pTexto!=NULL &&
		pTextoError!=NULL &&
		minimo<maximo &&
		reintentos>=0
		)
		{
			do {
				printf("%s",pTexto);
				resultadoScan=scanf("%d",&operadorBuffer);
				__fpurge(stdin);
				if((resultadoScan==1) && operadorBuffer<=maximo && minimo<=operadorBuffer)
				{
					retorno=0;
					*pOperador=operadorBuffer;
					break;
				} else {
					reintentos--;
					printf("%s",pTextoError);
				}

			}while(0<=reintentos);
		}
	return retorno;
}

/**
 * \brief Solicita un entero al usuario
 * \param char* pTexto, es el mensaje a ser mostrado al usuario
 * \param char* pTextoError, es el mensaje de error a ser mostrado al usuario
 * \param reintentos, cantidad de oportunidades para ingresar el dato
 * \param int pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (1) Error / (0) Tomo el entero ok
 */

int utn_getEnteroSinMaxMin(char* pTexto, char* pTextoError, int reintentos, int* pOperador)
{

	int retorno=1;
	int banderaIntentos=0;
	int operadorBuffer;
	int resultadoScan;
	int intentosFallidos=0;

	if(
			pTexto!=NULL &&
			pTextoError!=NULL &&
			reintentos>=0
		)
		{

		printf("%s",pTexto);
		__fpurge(stdin);
		resultadoScan=scanf("%d",&operadorBuffer);
		while(resultadoScan ==0)
		{
			if(intentosFallidos<reintentos)
			{
				printf("%s",pTextoError);
				__fpurge(stdin);
				resultadoScan=scanf("%d",&operadorBuffer);
				intentosFallidos++;
			} else {
				banderaIntentos=1;
				break;
			}
		}
		if(banderaIntentos==0){
			retorno=0;
			*pOperador=operadorBuffer;
		}
	}
	return retorno;
}

/**
 * \brief Toma dos enteros, realiza la suma y lo imprime en pantalla
 * \param int operador1, el primer numero
 * \param int operador, el segundo numero
 * \param int* pResultado, es el resultado de la suma
 * \return 0 siempre, no hay condiciones para sumar 2 numeros
 */
int utn_calcularSuma(int operador1, int operador2, int* pResultado){
	int suma;
	suma = operador1+operador2;
	*pResultado=suma;
	return 0;
}

/**
 * \brief Toma dos enteros, realiza la resta y lo imprime en pantalla
 * \param int operador1, el primer numero
 * \param int operador2, el segundo numero
 * \param int* pResultado, es el resultado de la resta
 * \return 0 siempre, no hay condiciones para restar 2 numeros
 */
int utn_calcularResta(int operador1, int operador2, int* pResultado){
	int resta;
	resta = operador1-operador2;
	*pResultado=resta;
	return 0;
}

/**
 * \brief Toma dos enteros, realiza la Division y lo imprime en pantalla
 * \param int operador1, el primer numero
 * \param int operador2, el segundo numero
 * \param int* pResultado, es el resultado de la division
 * \return o si se puede hacer la divison -1 si no se pudo
 */
int utn_calcularDivision(int operador1, int operador2, float* pResultado){
	float division;
	int retorno=-1;
	if(operador2 != 0)
	{
		division=(float)operador1/operador2;
		retorno=0;
	}
	*pResultado=division;
	return retorno;
}

/**
 * \brief Toma dos enteros, realiza la multiplicacion y lo imprime en pantalla
 * \param int operador1, el primer numero
 * \param int operador2, el segundo numero
 * \param int* pResultado, es el resultado de la multiplicacion
 * \return 0 siempre, no hay condiciones para la multiplicacion
 */
int utn_calcularMultiplicacion(int operador1, int operador2, int* pResultado){
	int multiplicacion;
	multiplicacion=operador1*operador2;
	*pResultado=multiplicacion;

	return 0;
}

/**
 * \brief Toma un entero, realiza el factorial de un numero
 * \param int operador, el primer numero
 * \param int* pResultado, donde se guarda el resultado del factorial
 * \return 0 si realizò el factorial y -1 si no se pudo hacer
 */
int utn_calcularFactorial(int operador, int* pResultado){
	int retorno=-1;
	int factorial=1;

	if(operador>=0)
	{
		for(int i=0;i<operador;i++)
		{
			factorial=factorial*(i+1);
		}
		retorno=0;
	} else {
		printf("No se puede realizar el factorial de un numero negativo\n");
	}
	*pResultado=factorial;

	return retorno;
}
