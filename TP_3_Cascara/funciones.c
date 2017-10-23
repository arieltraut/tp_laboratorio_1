#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validar.h"


int importarPeliculas(EMovie movie[],int lenPeliculas)
{
    int retorno = -1, cantidadLeida;
    FILE* pArchivo;
    pArchivo = fopen("movies.dat","rb");
    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
            cantidadLeida = fread(&movie,sizeof(EMovie),lenPeliculas,pArchivo);
            if(cantidadLeida > 0)
                retorno = 0;
        }
    }
    fclose(pArchivo);
    return retorno;
}

int autoSavePeliculas(EMovie movie[],int lenPeliculas)

{
    int retorno = -1, cantidadEscrita;//,index;
    FILE* pArchivo;
    pArchivo = fopen("movies.dat","wb");
    if(pArchivo==NULL)
    {
        printf("\nEl archivo no puede ser abierto");
    }
    else
    {
        cantidadEscrita = fwrite(&movie,sizeof(EMovie),lenPeliculas,pArchivo);
        if(cantidadEscrita > 0)
            retorno = 0;
        fclose(pArchivo);
    }
    return retorno;
}

void generarPagina(EMovie movie[],char nombre[], int lenPeliculas)
{
    int i;
    FILE *pArchivo;
    pArchivo=fopen(nombre, "w");
    if(pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(pArchivo,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");
        for(i=0; i<lenPeliculas; i++)
        {
            if(movie[i].flagOcupado == 1)
            {
                fprintf(pArchivo,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero: %s</li><li>Puntaje: %.1f</li><li>Duracion:%d</li></ul><p>%s</p></article>", movie[i].linkImagen, movie[i].titulo, movie[i].genero, movie[i].puntaje, movie[i].duracion, movie[i].descripcion);
            }
        }
        fprintf(pArchivo,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
    }
    fclose(pArchivo);
    printf("Pagina guardada con exito\n"); //////
}



int pelicula_init(EMovie movie[], int len)
{
    int i;
    int retorno = -1;
    if (movie != NULL && len >0)
    {
        for(i=0;i<len;i++)
        {
            movie[i].flagOcupado = 0;
            movie[i].idPelicula = -1;
        }
        retorno = 0;
    }
    return retorno;
}

int pelicula_generarProximoId(EMovie movie[], int len)
{
    int i, maxId=-2;
    if(movie != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if((movie[i].flagOcupado) == 1 || (movie[i].flagOcupado) == 0)
            {
                if((movie[i].idPelicula) > maxId || maxId == -2)
                    maxId = movie[i].idPelicula;
            }
        }
    }
    return maxId+1;
}

int pelicula_buscarPosicionLibre(EMovie movie[], int len)
{
    int i;
    int retorno = -1;
    if(movie != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(movie[i].flagOcupado == 0)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}

int pelicula_buscarIndicePorId(EMovie movie[],int len,int id)
{
    int i;
    int retorno = -1;
    if (movie != NULL && len >0)
    {
        for(i=0;i<len;i++)
            {
                if(movie[i].flagOcupado == 1)
                {
                    if(movie[i].idPelicula == id)        //(strcmp(array[i].a, array[i].dni) == 0)
                    {
                        retorno = i;
                        break;
                    }
                }
            }
    }
    return retorno;
}


int pelicula_alta(EMovie movie[],int len)
{
    int retorno = -1;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[LEN_DESCRIPCION];
    float puntaje;
    char linkImagen[LEN_LINK];
    int idNuevo;

    int indexVacio = pelicula_buscarPosicionLibre(movie,len);

    if (movie != NULL && indexVacio >=0 && indexVacio < len)
    {
        if (val_getAlfanumerico(titulo, "\nIngrese Titulo\n", "\nTitulo invalido\n",3,20)==0)
        {
            if (val_getNombre(genero, "\nIngrese genero\n", "\nGenero invalido\n",3,20)==0)
            {
                if(val_getUnsignedInt(&duracion,"\nIngrese duracion en minutos\n","\nError:\n",2,0,999)==0)
                {
                    if (val_getDescripcion(descripcion, "\nIngrese descripcion\n", "\nMaximo 1000 caracteres\n",3,LEN_DESCRIPCION)==0)
                    {
                        if(val_getUnsignedFloat(&puntaje,"\nIngrese puntaje\n","\nIngrese puntaje entre 1 y 10:\n",2,1,10)==0)
                        {
                            if (val_getLink(linkImagen, "\nIngrese link de imagen\n", "\nlink invalido\n",3,LEN_LINK)==0)
                            {
                                idNuevo = pelicula_generarProximoId(movie,len);

                                strncpy(movie[indexVacio].titulo,titulo,20);
                                strncpy(movie[indexVacio].genero,genero,20);
                                movie[indexVacio].duracion = duracion;
                                strncpy(movie[indexVacio].descripcion,descripcion,LEN_DESCRIPCION);
                                movie[indexVacio].puntaje = puntaje;
                                strncpy(movie[indexVacio].linkImagen,linkImagen,LEN_LINK);
                                movie[indexVacio].idPelicula = idNuevo;
                                movie[indexVacio].flagOcupado = 1;
                                printf("\nPelicula dada de alta");
                                retorno = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
    printf("\nNo se pudo realizar el alta\n");
    }
    return retorno;
}

int pelicula_modificar(EMovie movie[],int len)
{
    int retorno = -1;
    int bufferId;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[LEN_DESCRIPCION];
    float puntaje;
    char linkImagen[LEN_LINK];
    char seguir='s';
    pelicula_print(movie,len,1);
    val_getUnsignedInt(&bufferId,"\nIngrese ID de pelicula a modificar\n","\nIngrese solo numeros\n",2,0,9999);
    int index = pelicula_buscarIndicePorId(movie,len,bufferId);

    if (movie != NULL && len > 0)
    {
        if (index != -1)
        {
            while(seguir=='s')
            {

                if ((val_getUnsignedInt(&bufferId,"\nIngrese campo a modificar:\n  Titulo\t[0]\n  Genero\t[1]\n  Duracion\t[2]\n  Puntaje\t[3]\n  Descripcion\t[4]\n  Link Poster\t[5]\n  Terminar\t[6]\n","\nIngrese solo numeros\n",2,0,6)) == 0);
                {
                    switch(bufferId)
                    {
                    case 0:
                        if (val_getAlfanumerico(titulo, "\nIngrese Titulo\n", "\nTitulo invalido\n",3,20)==0)
                            strncpy(movie[index].titulo,titulo,20);
                        break;
                    case 1:
                        if (val_getNombre(genero, "\nIngrese genero\n", "\nGenero invalido\n",3,20)==0)
                            strncpy(movie[index].genero,genero,20);
                        break;
                    case 2:
                        if (val_getUnsignedInt(&duracion,"\nIngrese duracion en minutos\n","\nError:\n",2,0,999)==0)
                            movie[index].duracion = duracion;
                        break;
                    case 3:
                        if (val_getUnsignedFloat(&puntaje,"\nIngrese puntaje\n","\nIngrese puntaje entre 1 y 10:\n",2,0,10)==0)
                            movie[index].puntaje = puntaje;
                        break;
                    case 4:
                        if (val_getDescripcion(descripcion, "\nIngrese descripcion\n", "\nMaximo 1000 caracteres\n",3,LEN_DESCRIPCION)==0)
                            strncpy(movie[index].descripcion,descripcion,LEN_DESCRIPCION);
                        break;
                    case 5:
                        if (val_getLink(linkImagen, "\nIngrese link de imagen\n", "\nlink invalido\n",3,LEN_LINK)==0)
                            strncpy(movie[index].linkImagen,linkImagen,LEN_LINK);
                        break;
                    case 6:
                        seguir = 'n';
                        break;
                    }
                }
            }
            retorno = 0;
        }
        else
        {
            printf("El ID elegido no existe\n");
            system("pause");
        }
    }
    return retorno;
}


int pelicula_baja(EMovie movie[],int len)
{
    int retorno = -1;
    int bufferId;
    char bConfirm[50];

    pelicula_print(movie,len,1);
    val_getUnsignedInt(&bufferId,"\nIngrese ID a dar de baja\n","\nIngrese solo numeros\n",2,0,9999);
    int indexPan = pelicula_buscarIndicePorId(movie,len,bufferId);


    if (movie != NULL && len > 0)
    {
        if (indexPan != -1)
        {
            if (val_getNombre(bConfirm,"\nConfirma borrar la pelicula? S/N?\n","\nValor invalido\n",2,3)==0);
            {
                if (bConfirm[0] == 'S' || bConfirm[0]=='s')
                {
                    movie[indexPan].flagOcupado = 0;
                    retorno = 0;
                    printf("\nSe ha realizado la baja\n\n");
                }
                else
                {
                    printf("\nNo se han realizado bajas\n\n");
                }
            }
        }
        else
        {
            printf("\nEl ID elegido no existe\n");
        }
    }
    return retorno;
}

void pelicula_print(EMovie movie[], int len, int estado)
{
    int i;
    printf("Id\t%20s\t%20s\t%s\t%s\t%25s\n","Titulo","Genero","Duracion","Puntaje","Descripcion");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for(i=0; i<len; i++)
    {
        if ((movie[i].flagOcupado) == estado)
        {
            printf("%d\t%20s\t%20s\t%8d\t%7.1f\t%22.20s...\n", movie[i].idPelicula, movie[i].titulo, movie[i].genero, movie[i].duracion, movie[i].puntaje,movie[i].descripcion);
        }
    }
}
