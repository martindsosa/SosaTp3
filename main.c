#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
	setbuf(stdout,NULL);
	int option = 0;
	int i;
	int tam;
    LinkedList* listaEmpleados = ll_newLinkedList();
    Employee* auxiliarEmpleado;
    do{
		printf("****************************************************************************\n");
		printf("MENU:\n");
		printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
		printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
		printf("3. Alta de empleado\n");
		printf("4. Modificar datos de empleado\n");
		printf("5. Baja de empleado\n");
		printf("6. Listar empleados\n");
		printf("7. Ordenar empleados\n");
		printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
		printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
		printf("10. Salir\n");
		printf("*****************************************************************************\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				controller_loadFromText("data.csv",listaEmpleados);
				tam = ll_len(listaEmpleados);
				printf("ID  NOMBRE   HS TRABAJADAS SUELDO \n");
				for(i=0;i< tam ;i++){
					auxiliarEmpleado = ll_get(listaEmpleados, i);
					printf("%d %s %d %d \n",auxiliarEmpleado->id,auxiliarEmpleado->nombre,auxiliarEmpleado->horasTrabajadas,auxiliarEmpleado->sueldo);
				}
				break;
			case 2:
				controller_loadFromBinary("data.bin",listaEmpleados);
				break;
			case 3:
				controller_addEmployee(listaEmpleados);
				break;
			case 4:
				controller_editEmployee(listaEmpleados);
				break;
			case 5:
				controller_removeEmployee(listaEmpleados);
				break;
			case 6:
				controller_ListEmployee(listaEmpleados);
				break;
			case 7:
				controller_sortEmployee(listaEmpleados);
				break;
			case 8:
				controller_saveAsText("data.txt",listaEmpleados);
				break;
			case 9:
				controller_saveAsBinary("data.bin",listaEmpleados);
				break;

		}
	}while(option != 10);

    return 0;
}

