#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
/**
 * \brief Solicita un entero al usuario
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

	int retorno=1;
	int banderaIntentos=0;
	int operadorBuffer;
	int resultadoScan;
	int intentosFallidos=0;

	if(
			pTexto!=NULL &&
			pTextoError!=NULL &&
			minimo<maximo &&
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
 * \return no retorna
 */
void utn_calcularSuma(int operador1, int operador2){
	int suma;
	suma = operador1+operador2;
	printf("El resultado de %d + %d es: %d\n",operador1,operador2,suma);
}

/**
 * \brief Toma dos enteros, realiza la resta y lo imprime en pantalla
 * \param int operador1, el primer numero
 * \param int operador2, el segundo numero
 * \return no retorna
 */
void utn_calcularResta(int operador1, int operador2){
	int resta;
	resta = operador1-operador2;
	printf("El resultado de %d - %d es: %d\n",operador1,operador2,resta);
}

/**
 * \brief Toma dos enteros, realiza la Division y lo imprime en pantalla
 * \param int operador1, el primer numero
 * \param int operador2, el segundo numero
 * \return no retorna
 */
void utn_calcularDivision(int operador1, int operador2){
	float division;
	if(operador2 == 0)
	{
		printf("No se puede dividir %d por %d\n",operador1,operador2);
	}
	else {
		division=(float)operador1/operador2;
		printf("El resultado de %d / %d es: %.2f\n", operador1, operador2, division);
	}
}

/**
 * \brief Toma dos enteros, realiza la multiplicacion y lo imprime en pantalla
 * \param int operador1, el primer numero
 * \param int operador2, el segundo numero
 * \return no retorna
 */
void utn_calcularMultiplicacion(int operador1, int operador2){
	int multiplicacion;
	multiplicacion=operador1*operador2;
	printf("El resultado de %d * %d es %d\n", operador1, operador2, multiplicacion);
}

/**
 * \brief Toma un entero, realiza el factorial de un numero
 * \param int operador, el primer numero
 * \return no retorna
 */
void utn_calcularFactorial(int operador){
	int factorial=1;
	if(operador>=0)
	{
		for(int i=0;i<operador;i++)
		{
			factorial=factorial*(i+1);
		}
		printf("El resultado de %d! es %d: \n", operador, factorial);
	} else {
		printf("No se puede realizar el factorial de un numero negativo\n");
	}
}
