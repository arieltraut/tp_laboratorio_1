#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    system("mode con: cols=110 lines=40");
    char seguir='s';
    int opcion=0;
    EMovie arrayPeliculas[CANTIDAD_PELICULAS];

    if ((importarPeliculas(arrayPeliculas,CANTIDAD_PELICULAS)) == -1)
        pelicula_init(arrayPeliculas,CANTIDAD_PELICULAS);

    while(seguir=='s')
    {
        system("cls");
        autoSavePeliculas(arrayPeliculas,CANTIDAD_PELICULAS);

        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                pelicula_alta(arrayPeliculas,CANTIDAD_PELICULAS);
                system("pause");
                break;
            case 2:
                pelicula_baja(arrayPeliculas,CANTIDAD_PELICULAS);
                system("pause");
                break;
            case 3:
                pelicula_modificar(arrayPeliculas,CANTIDAD_PELICULAS);
                break;
            case 4:
                generarPagina(arrayPeliculas,"template/index.html",CANTIDAD_PELICULAS);
                break;
            case 5:
                autoSavePeliculas(arrayPeliculas,CANTIDAD_PELICULAS);
                system("pause");
                seguir = 'n';
                break;
            default:
                printf("Ingresar solo opciones 1 a 5");
                system("pause");
                break;
        }
    }

    return 0;
}
