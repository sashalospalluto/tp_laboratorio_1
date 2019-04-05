#include <stdio.h>
#include <stdlib.h>
#include "Funciones_Validaciones.h"
#include "function.h"
#include "funciones.h"

int main()
{
    float numeroA;
    float numeroB;
    char seguir='s';
    int opcion;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    unsigned long long int factorialA;
    unsigned long long int factorialB;
    int resultadoDivision; //resultado de la funcion "funcionDividir"
    int auxCase1;
    int auxCase2;

        while (seguir=='s')
    {
        system("cls");
        printf("\t\tMENU");
        printf("\n\n1-Ingresar 1er operando (A=%.2f)",numeroA);
        printf("\n\n2-Ingresar 2do operando (B=%.2f)",numeroB);
        printf("\n\n3-Calcular todas las operaciones");
        printf("\n\n4-Informar resultados");
        printf("\n\n5-Salir\n");

        do
        {
            printf("\n\t\tingrese opcion: ");
            scanf("\n%d",&opcion);
        }while (opcion<1 || opcion>5);

      switch (opcion)

                {
                case 1:
                    system("cls");
                    printf("Ingrese el primer operando: ");
                    scanf("%f",&numeroA);
                    auxCase1=1;
                    break;
                case 2:
                    system("cls");
                    printf("Ingrese el segundo operando: ");
                    scanf("%f",&numeroB);
                    auxCase2=1;
                    break;
                case 3:
                    if (auxCase1==1 && auxCase2==1)
                    {
                        funcionSuma(numeroA, numeroB,&suma);
                        funcionResta(numeroA, numeroB,&resta);
                        funcionMultiplicar(numeroA, numeroB, &multiplicacion);
                        resultadoDivision=funcionDividir(numeroA, numeroB,&division);
                        funcionFactorial(&numeroA,&factorialA);
                        funcionFactorial(&numeroB, &factorialB);
                        printf("\n\nProceso realizado\n");
                    }
                    else
                    {
                        printf("\nIngrese los dos operandos porfavor\n");

                    }

                    system("pause");
                    break;
                case 4:

                    if(auxCase1==1 && auxCase2==1)
                    {
                         //SUMA
                        printf("\nLa suma de %.2f + %.2f es: %.2f\n\n", numeroA, numeroB, suma);
                        //RESTA
                        printf("La resta de %.2f - %.2f es: %.2f\n\n", numeroA,numeroB, resta);
                        //MULTIPLICACION
                        printf("La multiplicacion de %.2f * %.2f es: %.2f\n\n", numeroA,numeroB, multiplicacion);
                        //DIVISION
                        if (resultadoDivision==0)
                        {
                            printf("La division de %.2f / %.2f es: %.2f\n\n", numeroA,numeroB, division);
                        }
                        else
                        {
                            printf("No se puede dividir por cero\n\n");
                        }
                        //FACTORIAL
                        funcionMostrarFactorial(numeroA,factorialA);
                        funcionMostrarFactorial(numeroB,factorialB);
                    }
                    else
                    {
                        printf("\nNo ingreso ambos datos, ingreselos por favor\n");
                    }
                    system("pause");
                    break;
                case 5:
                    seguir='f';
                    break;
                }
    }

}
