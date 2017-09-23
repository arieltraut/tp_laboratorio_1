#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    EPersona arrayPersona[CANTI_PERSONAS];
    int espacioLibre;
    int opcion;

    iniciarEstados(arrayPersona);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        opcion = val_menu("Opcion invalida, ingrese numeros del 1 al 5\n");

        switch(opcion)
        {
            case 1:
                espacioLibre = obtenerEspacioLibre(arrayPersona);
                if (espacioLibre == -1)
                {
                    printf("No quedan espacios libres, borre una entrada antes.\n");
                    system("pause");
                    break;
                }
                cargarPersona(arrayPersona,espacioLibre);
                break;
            case 2:
                borrarPersona(arrayPersona);
                break;
            case 3:
                ordenar(arrayPersona);
                imprimir(arrayPersona);
                system("pause");
                break;
            case 4:
                grafico(arrayPersona);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
