#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int returnRet=-1;
    f = fopen (path, "r");

    if(f == NULL)
    {
        printf("Error al crear el archivo de texto\n");
        utn_pausa();
    }
    else
    {
         returnRet = 0;
         printf("Archivo abierto correctamente\n");
         returnRet= parser_EmployeeFromText(f , pArrayListEmployee);
         utn_pausa();
    }
    return returnRet;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int returnRet=-1;
    f= fopen(path, "rb");

    if(f==NULL)
    {
        returnRet=0;
        printf("Problemas al crear el archivo\n");
        utn_pausa();
    }
    else{
        returnRet=1;
        returnRet= parser_EmployeeFromBinary(f , pArrayListEmployee);
        printf("Archivo de texto abierto\n");
        utn_pausa();
    }

    return returnRet;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleadoNuevo;
    int returnRet=-1;
    int id, sueldo, horasTrabajadas;
    char nombre[100];
    char idS[100];
    char sueldoS [100];
    char horasTrabajadasS[100];

    if(utn_getUnsignedInt("\ningrese un ID: ","error, vuelva a intentar (1-99999)",1,6,1,99999,3,&id)==0 &&
       utn_getUnsignedInt("\nIngrese el sueldo: ","error, vuelva a intentar",1,7,1,1000000,3,&sueldo)==0 &&
       utn_getUnsignedInt("\nIngrese la cantidad de horas trabajadas: ","error, vuelva a intentar",1,7,1,999999,3,&horasTrabajadas)==0 &&
       utn_getName("\nIngrese el nombre del empleado: ","error, vuelva a intentar",0,100,3,nombre)==0)
    {
        sprintf(idS,"%d",id);
        sprintf(sueldoS,"%d",sueldo);
        sprintf(horasTrabajadasS,"%d",horasTrabajadas);

        empleadoNuevo = employee_newParametros(idS,nombre,horasTrabajadasS,sueldoS);
        ll_add(pArrayListEmployee, empleadoNuevo);

        returnRet=0;
        printf("\n\ndatos cargados correctamente!");
    }else
    {
        printf("\n\nerror al cargar los datos");
    }
    return returnRet;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int id;
    int opcion=0;
    char nombre[100];
    int sueldo;
    int horasTrabajadas;

//    controller_ListEmployee(pArrayListEmployee);

    printf("\nIngrese el ID que desea modificar: ");
    scanf("%d",&id);

    empleado = ll_get(pArrayListEmployee, (id-1));
    do
    {
        printf("\tMODIFICACIONES\n");
        printf("1- Nombre\n");
        printf("2- Cantidad de horas trabajadas\n");
        printf("3- Sueldo\n");
        printf("4- Salir\n");

        scanf("%d", &opcion);

            switch(opcion){
                case 1:
                    if(utn_getName("\nIngrese el nombre del empleado: ","error, vuelva a intentar",0,100,3,nombre)==0)
                    {
                         employee_setNombre(empleado,nombre);
                         printf("\nNombre cambiado con exito\n");
                         utn_pausa();
                    }
                    break;
                case 2:
                    if(utn_getUnsignedInt("\nIngrese la cantidad de horas trabajadas: ","error, vuelva a intentar",1,7,1,999999,3,&horasTrabajadas)==0)
                    {
                        employee_setHorasTrabajadas(empleado,horasTrabajadas);
                        printf("\nHoras trabajadas cambiado con exito\n");
                        utn_pausa();
                    }
                    break;
                case 3:
                    if(utn_getUnsignedInt("\nIngrese el sueldo: ","error, vuelva a intentar",1,7,1,1000000,3,&sueldo)==0)
                    {
                        employee_setSueldo(empleado,sueldo);
                        printf("\nSueldo cambiado con exito\n");
                        utn_pausa();
                    }
                    break;
                case 4:
                    utn_limpiarPantalla();
                    opcion=4;
                    break;
            }
    }while(opcion!=4);

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int empleadoEliminar,i, len, opcion;
    int returnRet=-1;
    Employee* empleado;
    //controller_ListEmployee(pArrayListEmployee);
    len = ll_len(pArrayListEmployee);

    printf("Ingrese el ID que desea eliminar\n");
    scanf("%d", &empleadoEliminar);

    for(i=0;i<len;i++)
    {
        empleado= ll_get(pArrayListEmployee, i);
        if(empleado->id == empleadoEliminar)
        {
            printf("Esta seguro de que desea eliminar ?\n1-Si\n2-No\n");
            scanf("%d",&opcion );
            if(opcion ==1)
            {
                empleado=ll_pop(pArrayListEmployee,i);
                printf("\nEMPLEADO ELIMINADO");
                returnRet=0;
                break;
            }
            else
            {
                printf("\n No se pudo eliminar el empleado\n");
                break;
            }
        }
    }
    utn_pausa();
    return returnRet;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int returnRet=-1;
    int i,len;
    len=ll_len(pArrayListEmployee);
    if(pArrayListEmployee!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            employee_printEmployee(pArrayListEmployee,i);
            returnRet=0;
        }
    }
    return returnRet;
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    do
    {
        printf("Ingrese el criterio de ordenamiento");
        printf("\n1-Lista original");
        printf("\n2-ID de menor a mayor");
        printf("\n3-ID de mayor a menor");
        printf("\n4-Horas de trabajo de menor a mayor");
        printf("\n5-Horas de trabajo de mayor a menor");
        printf("\n6-Sueldo de menor a mayor");
        printf("\n7-Sueldo de mayor a menor");
        printf("\n8-Nombre de la A-Z");
        printf("\n9-Nombre de la Z-A");
        printf("\n10-Salir\n");
        scanf("%d",&opcion);
            switch (opcion)
            {
                case 1://ORIGINAL
                    controller_ListEmployee(pArrayListEmployee);
                    break;
                case 2://mM
                    printf("\tID MENOR A MAYOR\n\n");
                    ll_sort(pArrayListEmployee,employee_OrdenaEnteroID,1);
                    break;
                case 3://Mm
                    printf("\tID MAYOR A MENOR\n\n");
                    ll_sort(pArrayListEmployee,employee_OrdenaEnteroID,0);
                    break;
                case 4://mM
                    printf("\tHORAS TRABAJADAS MENOR A MAYOR\n\n");
                    ll_sort(pArrayListEmployee,employee_OrdenaEnteroHoras,1);
                    break;
                case 5://Mm
                    printf("\tHORAS TRABAJADAS MAYOR A MENOR\n\n");
                    ll_sort(pArrayListEmployee,employee_OrdenaEnteroHoras,0);
                    break;
                case 6:
                    printf("\tSUELDOS MENOR A MAYOR\n\n");
                    ll_sort(pArrayListEmployee,employee_OrdenaEnteroSueldo,1);
                    break;
                case 7:
                    printf("\tSUELDOS MAYOR A MENOR\n\n");
                    ll_sort(pArrayListEmployee,employee_OrdenaEnteroSueldo,0);
                    break;
                case 8:
                    printf("\tNOMBRES MENOR A MAYOR\n\n");
                    ll_sort(pArrayListEmployee,employee_OrdenaCadenaNombre,1);
                    break;
                case 9:
                    printf("\tNOMBRES MAYOR A MENOR\n\n");
                    ll_sort(pArrayListEmployee,employee_OrdenaCadenaNombre,0);
                    break;
                case 10:
                    printf("Salida del menu...\n\n");
                    opcion=11;
                    break;

                controller_ListEmployee(pArrayListEmployee);
            }
            utn_pausa();
    }while(opcion != 11);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* empleadoAux;
    int returnRet=-1;
    int i,len,id, sueldo, horasTrabajadas;
    char nombre[100];

    f= fopen(path, "w");
    if(f != NULL)
    {
        len=ll_len(pArrayListEmployee);
        fprintf(f,"id,nombre,horasTrabajadas,Sueldo\n");
        for(i=0; i<len; i++)
        {
            empleadoAux= ll_get(pArrayListEmployee, i);
            employee_getId(empleadoAux,&id);
            employee_getSueldo(empleadoAux, &sueldo);
            employee_getHorasTrabajadas(empleadoAux, &horasTrabajadas);
            employee_getNombre(empleadoAux,nombre);

            fprintf(f,"%d,%s,%d,%d\n",id , nombre, horasTrabajadas, sueldo);
        }
        printf("Archivo guardado\n\n");
        returnRet=0;
    }
    else
    {
        printf("No se pudo guardar el archivo\n");
        returnRet=0;
    }
    fclose(f);
    return returnRet;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int i;
    int returnRet=-1;
    int len;
    FILE* f;
    Employee* empleado;
    f=fopen(path, "wb");

    if(f != NULL)
    {
        len= ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            empleado=ll_get(pArrayListEmployee, i);
            fwrite(empleado,sizeof(Employee),1,f);
        }
        printf("Archivo binario guardado con exito\n");
        utn_pausa();
        returnRet=1;
    }
    else
    {
        printf("No se pudo guardar el archivo\n");
        utn_pausa();
    }
    fclose(f);
    return returnRet;
}

