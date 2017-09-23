#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANTI_PERSONAS 20
#define LUGAR_LIBRE 0
#define LUGAR_OCUPADO 1

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * \brief Inicializa un array de Personas con el valor recibido
 * \param array Es el array a ser inicializado
 * \return void
 *
 */
void iniciarEstados(EPersona persona[]);


/**
 * \brief valida los datos tomados
 * \param cadena a ser analizada
 * \param limite de caracteres a ingresar
 * \return void
 */
void myFgets(char* buffer, int limite ,FILE* archivo);


/** \brief valida la opcion ingresada por el usuario
 * \param recibe un mensaje de error para informar
 * \return retorna la opción ingresada por el usuario
 */
int val_menu(char error[]);


/**
 * \brief da el alta a la persona obteniendo nombre, dni y edad
 * \param lista el array se pasa como parametro
 * \param el primer indice libre donde sera almacenada la persona
 * \return void
 */
void cargarPersona(EPersona persona[],int indexLibre);


/**
 * \brief Verifica si el nombre es valido
 * \param str Array con la cadena a ser analizada
 * \param mensaje pidiendo el ingreso del nombre
 * \param mensaje de error
 * \return 0 si contiene solo letras y 1 si no lo es
 *
 */
int val_nombre (char bNombre[],char mensaje[], char mensajeError[]);


/**
 * \brief Verifica si el valor es una edad valida
 * \param str Array con la cadena a ser analizada
 * \param mensaje pidiendo el ingreso de edad
 * \param mensaje de error
 * \return 0 si es númerico y menor a 150 y -1 si no lo es
 *
 */
int val_edad (char bDni[], char mensaje[], char mensajeError[]);


/**
 * \brief Verifica si el valor recibido es DNI
 * \param str Array con la cadena a ser analizada
 * \return 0 si es númerico, menor a 9 y mayor a 7 digitos y -1 si no lo es
 *
 */
int val_dni (char bDni[], char mensaje[], char mensajeError[]);


/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo letras y 1 si no lo es
 *
 */
int val_soloLetras (char buffer[]);


/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 0 si es númerico y -1 si no lo es
 *
 */
int val_soloNumeros (char buffer[]);


/**
 * Borra la persona indicada por dni.
 * @param lista el array se pasa como parametro.
 * @return void
 */
void borrarPersona(EPersona persona[]);


/**
 * Imprime las personas agregadas.
 * @param lista el array se pasa como parametro.
 * @return void
 */
void imprimir (EPersona persona[]);


/**
 * Ordena las personas agregadas por el campo nombre.
 * @param lista el array se pasa como parametro.
 * @return void
 */
void ordenar(EPersona persona[]);


/**
 * Imprime un grafico de edades.
 * @param lista el array se pasa como parametro.
 * @return void
 */
void grafico (EPersona persona[]);


/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

#endif // FUNCIONES_H_INCLUDED
