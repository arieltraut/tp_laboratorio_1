#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANTIDAD_PELICULAS 10
#define LEN_DESCRIPCION 1000
#define LEN_LINK 1000

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[LEN_DESCRIPCION];
    float puntaje;
    char linkImagen[LEN_LINK];
    int flagOcupado;
    int idPelicula;
}EMovie;

#endif // FUNCIONES_H_INCLUDED

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[], int lenPeliculas);


/**
 *  Genera un array de peliculas a partir de un archivo binario.
 *  @param EMovie movie[] Puntero al array de peliculas.
 *  @param len int Longitud del array.
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 */
int importarPeliculas(EMovie movie[],int lenPeliculas);


/**
 *  Genera un archivo binario a partir de del array de las peliculas.
 *  @param EMovie movie[] Puntero al array de peliculas.
 *  @param len int Longitud del array.
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 */
int autoSavePeliculas(EMovie movie[],int lenPeliculas);


/** \brief Pide al usuario los datos de una nueva pelicula y luego lo agrega al array
 * \param EMovie movie[] Puntero al array de peliculas
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int pelicula_alta(EMovie movie[],int lenPeliculas);


/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado un 0.
 *
 * \param EMovie movie[] Puntero al array de peliculas
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int pelicula_init(EMovie movie[], int len);


/** \brief  Busca en el array la primer posicion libre
 * \param  EMovie movie[] Puntero al array de peliculas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */
int pelicula_buscarPosicionLibre(EMovie movie[], int len);


/** \brief  Busca en el array el id mas alto entre los usados y los borrados
 * \param EMovie movie[] Puntero al array de peliculas
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (proximo ID) si Ok
 *
 */
int pelicula_generarProximoId(EMovie movie[],int len);


/** \brief Busca en la lista un Id de pelicula que coincida con el Id recibido
 *
 * \param EMovie movie[] Puntero al array de peliculas
 * \param len int Longitud del array
 * \param id int ID a analizar
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int pelicula_buscarIndicePorId(EMovie movie[],int len,int id);


/** \brief Pide al usuario el ID, de una pelicula para modificar sus campos
 * \param EMovie movie[][] Puntero al array de peliculas.
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el id]
 *                    ( 0) si Ok
 */
int pelicula_modificar(EMovie movie[],int len);


/** \brief Pide al usuario el ID de una pelicula a ser dada de baja
 * \param EMovie movie[] Puntero al array de peliculas
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida, puntero NULL o no se encontro el id].
 *                    ( bufferId) si Ok
 */
int pelicula_baja(EMovie movie[],int len);


/** \brief Imprime por pantalla el array de peliculas
 * \param EMovie movie[] Puntero al array de peliculas
 * \param len int Longitud del array
 * \param estado int estado de la pelicula
 * \return void.
 *
 */
void pelicula_print(EMovie movie[], int len, int estado);



