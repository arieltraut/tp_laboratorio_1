#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED
#define MAX_INPUT_BUFFER 4096




void myFgets(char* buffer, int limite ,FILE* archivo);
int val_getUnsignedInt(int* destino, char* mensaje,char* mensajeError,int intentos,int lowLimit, int hiLimit);
int val_getUnsignedFloat(float* destino, char* mensaje,char* mensajeError,int intentos,float lowLimit, float hiLimit);
int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getAlfanumerico(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getDescripcion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getLink(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);


int val_validarUnsignedInt(char* buffer); //ver si se deja
int val_validarUnsignedFloat(char* buffer);
int val_esSoloLetras(char* buffer);
int val_esAlfaNumerico(char str[]);
int val_esLink(char str[]);




#endif // VALIDAR_H_INCLUDED
