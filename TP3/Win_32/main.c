#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int idContador=1000;

    do{
        option = menu();
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.bin",listaEmpleados);
                utn_pausa();
                break;
            case 3:
                controller_addEmployee(listaEmpleados,&idContador);
                utn_pausa();
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                utn_pausa();
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                utn_pausa();
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                utn_pausa();
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText("data.cvs" , listaEmpleados);
                utn_pausa();
                break;
            case 9:
                controller_saveAsBinary("data.bin" , listaEmpleados);
                utn_pausa();
                break;
            case 10: //salir
                break;
        }
    }while(option != 10);
    return 0;
}
