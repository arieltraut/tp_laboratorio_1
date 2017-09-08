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
* \return 0= OK **** -1= Error
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
* \brief
* \param
* \param
* \param
* \return
*/
int factorial (float numeroUno)
{
    int resp;
    if(numeroUno>0)
    {
        resp=numeroUno * factorial(numeroUno-1);
    }
    else if(numeroUno==0)
    {
        return 1;
    }
    else
    {
        return -1;
    }

    return (resp);
}







