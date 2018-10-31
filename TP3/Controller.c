#include "save.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE*pArchivo;
    int retorno=-1;
    if(path != NULL && pArrayListEmployee != NULL){
        pArchivo=fopen(path,"r");
        if(pArchivo != NULL){
            parser_EmployeeFromText(pArchivo,pArrayListEmployee);
            fclose(pArchivo);
        }else{
            printf("No se pudo abrir el archivo...");
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
    int retorno=-1;
    Employee* empleado;
    char bufferNombre[50];
    int bufferHoras;
    int bufferSueldo;
    if(pArrayListEmployee!=NULL &&
        !utn_getLetras(bufferNombre,50,3,"\nIngrese el nombre: ","\nError..Intente nuevamente") &&
        !utn_getEntero(&bufferHoras,3,"\nIngrese cantidad de horas: ","\nError..Intente nuevamente",1,9999) &&
        !utn_getEntero(&bufferSueldo,3,"\nIngrese el sueldo: ","\nError..Intente nuevamente",1,9999)){
                empleado=Employee_new();
            if(empleado!=NULL && !Employee_setNombre(empleado,bufferNombre) &&
                !Employee_setId(empleado,-1)&& !Employee_setSueldo(empleado,bufferSueldo)&&
                !Employee_setHorasTrabajadas(empleado,bufferHoras)){
                    retorno=0;
                    ll_add(pArrayListEmployee,empleado);
            }else{
                Employee_delete(empleado);
                empleado=NULL;
            }
    }
    return retorno;
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
    int retorno=-1;
    int len;
    int i;
    Employee* empleado;
    char bufferNombre[50];
    int bufferHoras;
    int bufferSueldo;
    int bufferId;
    int auxId;
    if(pArrayListEmployee!= NULL &&!utn_getEntero(&auxId,3,"\nIngrese el id del empleado a modificar: ","\nError..Intente nuevamente",0,99999)){
        len=ll_len(pArrayListEmployee);

        for(i=0;i<len;i++){
            empleado=(Employee*)ll_get(pArrayListEmployee,i);
            Employee_getId(empleado,&bufferId);
            if(bufferId==auxId &&!utn_getLetras(bufferNombre,50,3,"\nIngrese el nombre: ","\nError..Intente nuevamente") &&
                !utn_getEntero(&bufferHoras,3,"\nIngrese cantidad de horas: ","\nError..Intente nuevamente",1,9999) &&
                !utn_getEntero(&bufferSueldo,3,"\nIngrese el sueldo: ","\nError..Intente nuevamente",1,9999)&&
                !Employee_setNombre(empleado,bufferNombre) &&
                !Employee_setSueldo(empleado,bufferSueldo)&&
                !Employee_setHorasTrabajadas(empleado,bufferHoras)){
                retorno=0;
                break;
            }
        }
    }
    return retorno;
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
    int retorno=-1;
    int len;
    int i;
    Employee* empleado;
    int bufferId;
    int auxId;
    if(pArrayListEmployee!= NULL &&!utn_getEntero(&auxId,3,"\nIngrese el id del empleado a borrar: ","\nError..Intente nuevamente",0,99999)){
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++){
            empleado=(Employee*)ll_get(pArrayListEmployee,i);
            Employee_getId(empleado,&bufferId);
            if(bufferId==auxId){
                ll_remove(pArrayListEmployee,i);
                retorno=0;
                break;
            }
        }
    }
    return retorno;
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
    int retorno=-1;
    int len;
    int i;
    int bufferId;
    int bufferSueldo;
    char bufferNombre[50];
    int bufferHoras;
    Employee* bufferEmployee;
    if(pArrayListEmployee != NULL){
        retorno=0;
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++){
            bufferEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            Employee_getNombre(bufferEmployee,bufferNombre);
            Employee_getId(bufferEmployee,&bufferId);
            Employee_getSueldo(bufferEmployee,&bufferSueldo);
            Employee_getHorasTrabajadas(bufferEmployee,&bufferHoras);
            printf("Id - %d,Nombre - %s,Horas - %d,Sueldo - %d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);
        }
        getchar();
    }
    return retorno;
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
    int retorno=-1;
    LinkedList* auxList;
    Employee* empleado1;
    Employee* empleado2;
    char nombre1[50];
    char nombre2[50];
    int flag;
    int len;
    int i;
    if(pArrayListEmployee!= NULL){
        len=ll_len(pArrayListEmployee);
        do{
            flag=0;
            for(i=0;i<len-1;i++){
                empleado1=(Employee*)ll_get(pArrayListEmployee,i);
                empleado2=(Employee*)ll_get(pArrayListEmployee,i+1);
                Employee_getNombre(empleado1,nombre1);
                Employee_getNombre(empleado2,nombre2);
                if(strcmp(nombre1,nombre2)<0){
                    auxList=pArrayListEmployee[i+1];
                    pArrayListEmployee[i+1]=pArrayListEmployee[i];
                    pArrayListEmployee[i]=*auxList;
                    flag=1;
                }
            }
        }while(flag);
    }
    return retorno;
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
    FILE*pArchivo;
    int retorno=-1;
    if(path != NULL && pArrayListEmployee != NULL){
        pArchivo=fopen(path,"w");
        if(pArchivo != NULL && !save_EmployeesAsText(pArchivo,pArrayListEmployee)){
            fclose(pArchivo);
            printf("Guardado exitoso");
            getchar();
            retorno=0;
        }else{
            printf("No se pudo abrir el archivo...");
        }
    }
    return retorno;
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
    return 1;
}

