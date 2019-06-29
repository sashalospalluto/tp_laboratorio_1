#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof (Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* aux;
    aux = employee_new();

    if(aux !=  NULL)
    {
        employee_setIdS(aux , idStr);
        employee_setNombre(aux, nombreStr);
        employee_setHorasTrabajadasS(aux, horasTrabajadasStr);
        employee_setSueldoS(aux, sueldoStr);
    }
    return aux;
}

int employee_setId(Employee* this,int id)
{
    int returnRet =-1;
    if(this != NULL && id>0)
    {
        this->id =id;
        returnRet = 0;
    }
    return returnRet;
}

int employee_setIdS(Employee* this,char* id)
{
    int returnRet=-1;
    int idAux;
    if(this!=NULL && id!=NULL)
    {
        if(isValidNumber(id)==0)
        {
            idAux = atoi(id);
            if(employee_setId(this,idAux)==0)
            {
                returnRet=0;
            }
        }
    }
    return returnRet;
}

int employee_getId(Employee* this,int* id)
{
    int returnRet=-1;

    if(this != NULL && id != NULL)
    {
        *id= this->id;
        returnRet=0;
    }
    return returnRet;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int returnRet =-1;

    if(this != NULL)
    {
         strcpy (this->nombre, nombre);
    }
    return returnRet;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int returnRet =-1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        returnRet =1;
    }
    return returnRet;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int returnRet =-1;
    if(this != NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas =horasTrabajadas;
        returnRet = 0;
    }
    return returnRet;
}

int employee_setHorasTrabajadasS(Employee* this,char* horasTrabajadas)
{
    int returnRet=-1;
    int horasTrabajadasAux;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        if(isValidNumber(horasTrabajadas)==0)
        {
            horasTrabajadasAux = atoi(horasTrabajadas);
            if(employee_setHorasTrabajadas(this,horasTrabajadasAux)==0)
            {
                returnRet=0;
            }
        }
    }
    return returnRet;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int returnRet=-1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas= this->horasTrabajadas;
        returnRet=0;
    }
    return returnRet;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int returnRet =-1;
    if(this != NULL && sueldo>0)
    {
        this->sueldo =sueldo;
        returnRet = 0;
    }
    return returnRet;
}

int employee_setSueldoS(Employee* this,char* sueldo)
{
    int returnRet=-1;
    int sueldoAux;
    if(this!=NULL && sueldo!=NULL)
    {
        if(isValidNumber(sueldo)==0)
        {
            sueldoAux = atoi(sueldo);
            if(employee_setSueldo(this,sueldoAux)==0)
            {
                returnRet=0;
            }
        }
    }
    return returnRet;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int returnRet=-1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo= this->sueldo;
        returnRet=0;
    }
    return returnRet;
}

void employee_delete(Employee* lista)
{
    if(lista !=  NULL)
    {
        lista->id =0;
        lista->horasTrabajadas=0;
        lista->sueldo=0;
        strcpy(lista->nombre, "");
    }
    free(lista);
}

int employee_printEmployee(LinkedList* pArrayListEmployee, int index)
{
    Employee* empleadoAux;
    int id;
    char nombre[100];
    int horasTrabajadas;
    int sueldo;
    int returnRet=-1;
    if(pArrayListEmployee!=NULL && index>=0 && index<ll_len(pArrayListEmployee))
    {
        empleadoAux=(Employee*)ll_get(pArrayListEmployee,index);
        employee_getId(empleadoAux,&id);
        employee_getNombre(empleadoAux,nombre);
        employee_getHorasTrabajadas(empleadoAux,&horasTrabajadas);
        employee_getSueldo(empleadoAux,&sueldo);
        printf("%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
        returnRet=0;
    }
    return returnRet;
}

int employee_OrdenaEnteroID(void* elementoA, void* elementoB)
{
    int returnRet = 0;
    Employee* empleadoA;
    Employee* empleadoB;
    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;

    if(empleadoA->id > empleadoB->id)
    {
        returnRet =1 ;
    }
    if(empleadoA->id < empleadoB->id)
    {
        returnRet = -1;
    }
return returnRet;
}
int employee_OrdenaEnteroHoras(void* elementoA, void* elementoB)
{
    int returnRet = 0;
    Employee* empleadoA;
    Employee* empleadoB;
    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;

    if(empleadoA->horasTrabajadas > empleadoB->horasTrabajadas)
    {
        returnRet =1 ;
    }
    if(empleadoA->horasTrabajadas < empleadoB->horasTrabajadas)
    {
        returnRet = -1;
    }
return returnRet;
}
int employee_OrdenaEnteroSueldo(void* elementoA, void* elementoB)
{
    int returnRet = 0;
    Employee* empleadoA;
    Employee* empleadoB;
    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;

    if(empleadoA->sueldo > empleadoB->sueldo)
    {
        returnRet =1 ;
    }
    if(empleadoA->sueldo < empleadoB->sueldo)
    {
        returnRet = -1;
    }
return returnRet;
}
int employee_OrdenaCadenaNombre(void* elementoA, void* elementoB)
{
    int returnRet = 0;
    Employee* empleadoA;
    Employee* empleadoB;
    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;

    if(strcmp(empleadoA->nombre, empleadoB->nombre)<0)
    {
        returnRet =1 ;
    }
    if(strcmp(empleadoA->nombre, empleadoB->nombre)>0)
    {
        returnRet = -1;
    }
return returnRet;
}
