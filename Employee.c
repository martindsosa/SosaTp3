#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new(){
	return (Employee*) malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo){
	Employee* pEmployee = NULL;
	pEmployee = employee_new();
	if(pEmployee != NULL){
		employee_setId(pEmployee,atoi(idStr));
		employee_setNombre(pEmployee,nombreStr);
		employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr));
		employee_setSueldo(pEmployee,atoi(sueldo));
	}
	return pEmployee;
}

void employee_delete(Employee* this){
	if(this != NULL){
		free (this);
	}
}

int employee_setId(Employee* this,int id){
	int retorno = -1;
	if(this != NULL){
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id){
	int retorno = -1;
	if(this != NULL && id != NULL){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL){
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL){
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno = -1;
	if(this != NULL){
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL){
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){
	int retorno = -1;
	if(this != NULL){
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo){
	int retorno = -1;
	if(this != NULL && sueldo != NULL){
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}
int employee_funcionCriterio(void* item1,void* item2){
	int retorno = 0;
	Employee* e1;
	Employee* e2;
	int auxId1;
	int auxId2;
	e1 = (Employee*)item1;
	e2 = (Employee*)item2;
	if(employee_getId(e1,&auxId1)==0 &&	employee_getId(e2,&auxId2)==0)
	{
		if(auxId1 > auxId2)
		{
			retorno = 1;
		}
		else{
			retorno = -1;
		}
	}
	return retorno;
}
