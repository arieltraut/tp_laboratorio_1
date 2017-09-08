#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0,flagX=0, flagY=0;;
    float x,y,resultadoSuma,resultadoResta,resultadoMulti,resultadoDiv;

    while(seguir=='s')
    {
        system("cls"); //limpia la consola

        if (flagX==0)
        {
            printf("1- Ingresar 1er operando (A)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%.2f)\n",x);
        }
        if (flagY==0)
        {
            printf("2- Ingresar 2do operando (B)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n",y);
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
                ingresaNumero(&x);
                flagX =1;
                break;
            case 2:
                ingresaNumero(&y);
                flagY =1;
                break;
            case 3:
                if(flagX==0 || flagY==0)
                {
                    printf("Antes de calcular la suma debe ingresar ambos operandos\n");
                }
                else
                {
                    suma (x, y, &resultadoSuma);
                    printf("El resultado de la suma es: %.2f\n",resultadoSuma);
                }
                break;
            case 4:
                if(flagX==0 || flagY==0)
                {
                    printf("Antes de calcular la resta debe ingresar ambos operandos\n");
                }
                else
                {
                    resta(x,y,&resultadoResta);
                    printf("El resultado de la resta es: %.2f\n",resultadoResta);
                }
                break;
            case 5:
                if(flagX==0 || flagY==0)
                {
                    printf("Antes de calcular la division debe ingresar ambos operandos\n");
                }
                else if((division(x,y,&resultadoDiv)) == 0)
                    {
                        printf("El resultado de la division es %.2f\n",resultadoDiv);
                    }
                    else
                    {
                        printf("El divisor no puede ser 0, ingrese nuevamente el segundo operando\n");
                    }
                break;
            case 6:
                if(flagX==0 || flagY==0)
                {
                    printf("Antes de calcular la multiplicacion debe ingresar ambos operandos\n");
                }
                else
                {
                    multiplicacion(x,y,&resultadoMulti);
                    printf("El resultado de la multiplicacion es %.2f\n",resultadoMulti);
                }
                break;
            case 7:
                if(flagX==0)
                {
                    printf("Antes de calcular el factorial debe ingresar el operando A\n");
                }
                else if (factorial(x)!=-1)
                {
                    printf("El resultado del factorial es %.2d\n",factorial(x));
                }
                else
                {
                    printf("No se puede calcular el factorial de un numero negativo, ingrese nuevamente\n");
                }
                break;
            case 8:
                if(flagX==0 || flagY==0)
                {
                    printf("Antes de calcular las operaciones debe ingresar ambos operandos\n");
                }
                else
                {
                    suma (x, y, &resultadoSuma);
                    printf("El resultado de la suma es: %.2f\n",resultadoSuma);

                    resta(x,y,&resultadoResta);
                    printf("El resultado de la resta es: %.2f\n",resultadoResta);

                    if((division(x,y,&resultadoDiv)) == 0)
                    {
                        printf("El resultado de la division es %.2f\n",resultadoDiv);
                    }else
                    {
                        printf("El divisor no puede ser 0, ingrese nuevamente el segundo operando.\n");
                    }

                    multiplicacion(x,y,&resultadoMulti);
                    printf("El resultado de la multiplicacion es %.2f\n",resultadoMulti);
                }
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                printf("Valor incorrecto, debe ingresar opciones del 1 al 9\n");
                break;
        }
        if(seguir=='s')
        {
            system("pause"); //crea una pausa hasta que el usuario presione una tecla
        }
    }
    return 0;
}
