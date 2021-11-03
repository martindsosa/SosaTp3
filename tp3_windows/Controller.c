#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0-> se pudo abrir -1->no se pudo abrir
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* fpArchivo;
	if(pArrayListEmployee != NULL && path != NULL)
	{
		fpArchivo = fopen(path,"r");
		if(fpArchivo != NULL)
		{
			retorno=0;
			printf("archivo abierto");
			parser_EmployeeFromText(fpArchivo , pArrayListEmployee);
		}
	}
	return retorno;
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
    return 1;
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
    return 1;
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
    return 1;
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
	ll_sort(pArrayListEmployee, employee_funcionCriterio, 0);
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
    return 1;
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
	int retorno = -1;

	int sizeEmpleado;
	int cantidad;
	FILE* pArchivo;
	Employee* empleado;
	sizeEmpleado = ll_len(pArrayListEmployee);
	printf("tamaño de empleado %d",sizeEmpleado);
	if (sizeEmpleado != -1){
		pArchivo = fopen("data.bin","wb");
		if(pArchivo != NULL){
			/*do{
				empleado = (Employee*)ll_get(pArrayListEmployee,index);
				printf("%d",index);
				index++;
				//sizeEmpleado--;
				//cantidad = fwrite(empleado,sizeof(empleado),sizeEmpleado,pArchivo);
			}while(sizeEmpleado != 0);*/
			cantidad = fwrite(pArrayListEmployee,sizeof(empleado),sizeEmpleado,pArchivo);
			if(cantidad != sizeEmpleado){
				printf("\n error en la grabacion del archivo binario !!\n");

			}else{
				printf("\ngrabo %d registros\n",cantidad);
			}

		}
	}


    return retorno;
}

