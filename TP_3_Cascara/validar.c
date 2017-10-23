#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"




/**
 * \brief valida los datos tomados
 * \param cadena a ser analizada
 * \param limite de caracteres a ingresar
 * \param puntero a archivo
 * \return void
 */
void myFgets(char* buffer, int limite ,FILE* archivo)
{
    int i=0;
    fflush(stdin);
    fgets(buffer, limite ,archivo);
    buffer[limite-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param input puntero al lugar donde se cargar� el numero ingresado
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite de caracteres a cargar
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int val_getUnsignedInt(int* destino, char* mensaje,char* mensajeError,int intentos,int lowLimit, int hiLimit)
{
    int retorno = -1,aux;
    char buffer[MAX_INPUT_BUFFER];

    printf(mensaje);
    for( ; intentos>0; intentos--)
    {
        myFgets(buffer, MAX_INPUT_BUFFER,stdin);

        if(val_soloNumeros(buffer) == -1)
        {
            printf(mensajeError);
            continue;
        }
        aux = atoi(buffer);
        if(aux < lowLimit || aux > hiLimit)
        {
            printf ("%s",mensajeError);
            continue;
        }
        else
        {
            *destino = aux;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param input puntero al lugar donde se cargar� el numero ingresado
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite de caracteres a cargar
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int val_getUnsignedFloat(float* destino, char* mensaje,char* mensajeError,int intentos,float lowLimit, float hiLimit)
{
    int retorno = -1;
    float aux;
    char buffer[MAX_INPUT_BUFFER];

    printf(mensaje);
    for( ; intentos>0; intentos--)
    {
        myFgets(buffer, MAX_INPUT_BUFFER,stdin);

        if(val_validarUnsignedFloat(buffer) == -1)
        {
            printf(mensajeError);
            continue;
        }
        aux = atof(buffer);
        if(aux < lowLimit || aux > hiLimit)
        {
            printf ("%s",mensajeError);
            continue;
        }
        else
        {
            *destino = aux;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido es float
 * \param str Array con la cadena a ser analizada
 * \return 0 si es flotante y -1 si no lo es
 *
 */
int val_validarUnsignedFloat(char buffer[])
{
   int i=0;
   int cantidadPuntos=0;
   while(buffer[i] != '\0')
   {
       if (buffer[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(buffer[i] < '0' || buffer[i] > '9')
           return -1;
       i++;
   }
   return 0;
}


/**
 * \brief Solicita un string al usuario y lo valida
 * \param input puntero al lugar donde se cargar� el numero ingresado
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite de caracteres a cargar
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_esSoloLetras(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido es alfanumerico
 * \param input puntero al lugar donde se cargar� el numero ingresado
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite
 * \return 0 si es OK y -1 si no lo es
 *
 */
int val_getAlfanumerico(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_esAlfaNumerico(buffer) == 0)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido es una descripcion
 * \param input puntero al lugar donde se cargar� el numero ingresado
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite de caracteres a ingresar
 * \return 0 si es OK y -1 si no lo es
 *
 */
int val_getDescripcion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);

        myFgets(buffer, limite,stdin);
        strncpy(destino,buffer,limite);
        retorno = 0;
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido es un enlace
 * \param input puntero al lugar donde se cargar� el numero ingresado
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite de caracteres a ingresar
 * \return 0 si es OK y -1 si no lo es
 *
 */
int val_getLink(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_esLink(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int val_esSoloLetras(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && buffer[i] != ',' && buffer[i] != '.' && buffer[i] != ' ' && buffer[i] != '-')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 *
 */
int val_esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9') && (str[i] != '.'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido no contiene espacios
 * \param str Array con la cadena a ser analizada
 * \return -1 si contiene espacios y 0 si no contiene
 *
 */
int val_esLink(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] == ' '))
           return -1;
       i++;
   }
   return 0;
}


/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int val_soloNumeros(char* buffer)
{
    int retorno = 0,i=0;

    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

