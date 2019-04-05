#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

void funcionSuma (float num1, float num2, float* suma)
{
    float sumaFunc;
    sumaFunc = num1+num2;
    *suma=sumaFunc;
}

void funcionResta (float num1,float num2,float* resta)
{
    float restaFunc;
    restaFunc = num1-num2;
    *resta=restaFunc;
}

void funcionMultiplicar (float num1,float num2, float* multiplicar)
{
    float multiplicarfunc;
    multiplicarfunc=num1*num2;
    *multiplicar=multiplicarfunc;
}

int funcionDividir (float num1, float num2, float* dividir)
{
    int ret;
    float dividirFunc;

    if (num2==0)
    {
        ret=-1;
    }
    else
    {
        dividirFunc=num1/num2;
        *dividir=dividirFunc;
        ret=0;
    }

    return ret;

}

void funcionFactorial (float* num, unsigned long int* factorial)
{
    int factorialFunc=1;
    int numero=(*num);

    if (numero<0)
    {
        factorialFunc=-1;
    }
    else if (numero==0 || numero==1)
    {
        factorialFunc=1;
    }
    else
    {
        for (int i=numero; i>1; i--)
        {
            factorialFunc=factorialFunc*i;
        }

        *factorial=factorialFunc;
    }
}

void funcionMostrarFactorial(float num,unsigned long int factorial)
{
    if(factorial==-1)
    {
        printf("el numero %.2f no se puede factorear. ",num);
    }else
    {
        printf("el factorial de %.2f es: %lu .",num,factorial);
    }
}

int utn_getNumero(float* pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    float num;

    while (reintentos>0)
    {
        printf("%s",mensaje);

        if (getFloat(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
                //__fpurge(stdin);
                reintentos--;

                if(reintentos==0)
                {
                    printf("NO HAY MAS INTENTOS");
                }
                else
                {
                    printf("%s\n",mensajeError);
                }

    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}

int getFloat(float *pResultado)
{
    int ret=-1;
    char buffer[64];
    scanf("%s",buffer);

    ret=validarNumero(buffer);

    if(ret==0)
    {
        *pResultado = atof(buffer);
    }


    return ret;
}

int validarNumero (char* numero)
{
    int ret=-1;
    int i=0;
    while(*(numero)+i!='\o')
    {
        if (isdigit ((*numero)+i))
        {
            ret=0;
        }else
        {
            break;
        }
        i++;
    }
    return ret;
}


