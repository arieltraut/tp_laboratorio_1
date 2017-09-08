#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
* \brief Toma una variable float y devuelve por referencia el valor ingresado.
* \param Numero ingresado
* \return void
*/
void ingresaNumero (float* numeroIngresado)
{
    float aux;
    scanf("%f",&aux);
    *numeroIngresado=aux;
}

/**
* \brief Suma dos variables float y devuelve por referencia el valor ingresado.
* \param Primer numero ingresado
* \param Segundo numero ingresado
* \param Resultado de la suma
* \return void
*/
void suma (float numeroUno, float numeroDos, float*resultado)
{
    *resultado = numeroUno + numeroDos;
}

/**
* \brief Resta dos variables float y devuelve por referencia el valor ingresado.
* \param Primer numero ingresado
* \param Segundo numero ingresado
* \param Resultado de la resta
* \return void
*/
void resta (float numeroUno, float numeroDos, float* resultado)
{
    *resultado = numeroUno - numeroDos;
}

/**
* \brief Divide dos variables float, devuelve por referencia el valor ingresado y retorna validacion.
* \param Primer numero ingresado
* \param Segundo numero ingresado
* \param Resultado de la division
* \return (0)= OK **** (-1)= Error
*/
int division (float numeroUno, float numeroDos, float* resultado)
{
    int retorno=-1;

    if(numeroDos!=0)
    {
        *resultado = numeroUno / numeroDos;
        retorno = 0;
    }

    return retorno;
}

/**
* \brief Multiplica dos variables float y devuelve por referencia el valor ingresado.
* \param Primer numero ingresado.
* \param Segundo numero ingresado.
* \param Resultado de la multiplicacion.
* \return void
*/
void multiplicacion (float numeroUno, float numeroDos, float*resultado)
{
    *resultado = numeroUno * numeroDos;
}

/**
* \brief Toma un numero, valida que sea entero y positivo y devuelve el factorial por referencia
* \param Numero ingresado
* \param Resultado del factorial
* \return 0= OK **** -1= Error
*/
int factorial (float numeroUno, float*resultado)
{
    int retorno = -1, auxiliar = 1,i;

    if(numeroUno >= 0 && numeroUno - (int)numeroUno == 0 )
    {
        for(i=numeroUno; i>=1;i--)
        {
            auxiliar = auxiliar * i;
        }
        *resultado = auxiliar;
        retorno = 0;
    }


    return retorno;
}







