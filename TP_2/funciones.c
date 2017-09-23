#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void iniciarEstados(EPersona persona[])
{
    int i;
    for(i=0;i<CANTI_PERSONAS;i++)
    {
        persona[i].estado = LUGAR_LIBRE;
    }
}


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

int val_menu(char error[])
{
    int opcion,aux;
    aux=scanf("%d",&opcion);
    fflush(stdin);
    if(aux==0 ||(opcion<1||opcion>5))
    {
        printf("%s",error);
        system("pause");
    }
    return opcion;
}


void cargarPersona(EPersona persona[],int indexLibre)
{
    char bNombre[50], bDni[20], bEdad[3];

    if (val_nombre(bNombre,"Ingrese nombre\n","Nombre incorrecto, ingrese nuevamente\n") == 0)
    {
        if (val_edad (bEdad,"Ingrese edad\n","Edad incorrecta, ingrese nuevamente\n") == 0)
        {
            if (val_dni(bDni,"Ingrese DNI\n","DNI incorrecto, ingrese nuevamente\n") == 0)
            {
                strncpy(persona[indexLibre].nombre,bNombre,50);
                persona[indexLibre].edad = atoi(bEdad);
                persona[indexLibre].dni = atoi(bDni);
                persona[indexLibre].estado = LUGAR_OCUPADO;
            }
        }
    }
}

void borrarPersona(EPersona persona[])
{
    char bDni[20],respuesta;
    int indice;
    printf("Ingrese DNI de persona a borrar\n");
    myFgets(bDni,20,stdin);
    indice = buscarPorDni(persona, atoi(bDni));
    if (indice == -1)
    {
        printf ("DNI inexistente, ingrese opcion nuevamente\n");
        system("pause");
    }
    else
    {
        printf("Confirma borrar a %s   s/n ?\n",persona[indice].nombre);
        scanf("%c",&respuesta);
        if(respuesta=='s')
        {
            persona[indice].estado = LUGAR_LIBRE;
            printf("Se ha borrado a %s\n",persona[indice].nombre);
            system("pause");
        }
        else
        {
            printf("No se realizaron cambios\n");
            system("pause");
        }
    }
}


int val_nombre (char bNombre[],char mensaje[], char mensajeError[])
{
    int retorno = 0;
    printf("%s", mensaje);
    myFgets(bNombre, 50, stdin);

    if (val_soloLetras (bNombre) == -1)
    {
        printf(mensajeError);
        system("pause");
        retorno = -1;
    }
    return retorno;
}


int val_edad (char bEdad[], char mensaje[], char mensajeError[])
{
    int retorno = 0;
    printf(mensaje);
    myFgets(bEdad,20,stdin);

    if ((val_soloNumeros (bEdad) == -1) || (atoi(bEdad) > 150))
        {
            printf(mensajeError);
            system("pause");
            retorno = -1;
        }
    return retorno;
}


int val_dni (char bDni[], char mensaje[], char mensajeError[])
{
    int retorno = 0;
    printf(mensaje);
    myFgets(bDni,20,stdin);

    if ((val_soloNumeros (bDni) == -1) || (strlen(bDni) > 8) || (strlen(bDni) < 7))
        {
            printf(mensajeError);
            system("pause");
            retorno = -1;
        }
    return retorno;
}


int val_soloNumeros (char buffer[])
{
    int i=0, retorno = 0;

    while (buffer[i] != '\0')
    {
        if (buffer[i] <'0' || buffer[i] >'9')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}


int val_soloLetras (char buffer[])
{
    int i=0,retorno =0;
    while (buffer[i] != '\0' )
    {
        if((buffer[i] <'a' || buffer[i] >'z') && (buffer[i] <'A' || buffer[i] >'Z'))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}


int obtenerEspacioLibre(EPersona lista[])
{
    int i,retorno = -1;

    for(i=0;i<CANTI_PERSONAS;i++)
    {
        if(lista[i].estado==LUGAR_LIBRE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int buscarPorDni(EPersona lista[], int dni)
{
    int i,retorno = -1;
    for(i=0;i<CANTI_PERSONAS;i++)
    {
        if (lista[i].dni == dni)
        {
            retorno=i;
        }
    }
    return retorno;
}

void imprimir (EPersona persona[])
{
    int i;
    if (obtenerEspacioLibre(persona) == -1)
        {
        printf("No se ha cargado ninguna persona\n");
        }
        else
        {
            for (i=0;i<CANTI_PERSONAS;i++)
            {
                if(persona[i].estado==LUGAR_OCUPADO)
                {
                    printf("Indice: %d, Nombre: %s, Edad: %d, DNI: %d\n",i,persona[i].nombre,persona[i].edad,persona[i].dni);
                }
            }
        }
}

void ordenar(EPersona persona[])
{
     int i,j;
     EPersona temp[CANTI_PERSONAS];
     for(i=1;i<CANTI_PERSONAS;i++)
     {
        if (persona[i].estado==LUGAR_LIBRE)
            continue;

        temp[i] = persona[i];
        j=i-1;
        while((stricmp(temp[i].nombre,persona[j].nombre)<0) && j>=0)
        {
            persona[j+1] = persona[j];
            j--;
        }
        persona[j+1]=temp[i];
     }
}


void grafico (EPersona persona[])
{
    int i,menor18=0,entre19y35=0,may35=0,ocupado=0;
    for (i=0;i<CANTI_PERSONAS;i++)
    {
        if(persona[i].estado==LUGAR_OCUPADO)
        {
            ocupado++;
            if (persona[i].edad < 18)
                menor18++;
            else if ((persona[i].edad > 18) && (persona[i].edad < 35))
                entre19y35++;
            else
                may35++;
        }
    }
    for (i=ocupado;i>0;i--)
    {
            if (i<=menor18)
                printf("*\t");
            else if (i<=entre19y35)
                printf(" \t");

            if (i<=entre19y35)
                printf("*\t");
            else if (i<=may35)
                printf(" \t");

            if ((i>menor18) && (i>entre19y35) && (i<=may35))
                printf(" \t*");
            else if (i<=may35)
                printf("*");

            if (i<=menor18 || i<=entre19y35 || i<=may35)
                printf("\n");
    }
    printf("<18\t19-35\t>35\n");
}

