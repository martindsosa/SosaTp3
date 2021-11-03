#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char auxiliarId[4096];
	char auxiliarNombre[4096];
	char auxiliarHorasTrabajadas[4096];
	char auxiliarSueldo[4096];
	Employee* pEmpleado;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxiliarId,auxiliarNombre,auxiliarHorasTrabajadas,auxiliarSueldo);
	do
	{
		if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxiliarId,auxiliarNombre,auxiliarHorasTrabajadas,auxiliarSueldo)== 4)
		{
			retorno = 0;
			pEmpleado = employee_newParametros(auxiliarId,auxiliarNombre,auxiliarHorasTrabajadas,auxiliarSueldo);
			if(pEmpleado != NULL){
				ll_add(pArrayListEmployee,pEmpleado);
			}
		}else{
			break;
		}
	}while(!feof(pFile));
	fclose(pFile);
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
