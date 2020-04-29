/*
 * array.c
 *
 *  Created on: 16 abr. 2020
 *      Author: Nahu_
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "utn.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
int initColegio(colegioE pArray[],int limite)
{
	int retorno = -1;

	if(pArray != NULL && limite > 0)
	{
		for(; limite > 0; limite--)
		{
			pArray[limite-1].isEmpty = 1;
		}
		retorno=0;
	}
	return retorno;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
int cargarPersona(colegioE array[], int size)
{
    int retorno=-1;
    int posicion;
    int bufferLegajo;
    if(array!=NULL && size>0)
    {
        if(buscarEmpty(array,size,&posicion)==-1 )
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
        	utn_getUnsignedInt("\nIngrese el legajo: ","\nError.",1,sizeof(int),1,size,3,&bufferLegajo); // ERROR POR ARREGLAR
        	  if(buscarID(array,size,bufferLegajo,&posicion)==-1)
        	  {
        		  printf("\nYa existe este ID");
        	  }
        	  else
        	  {
        		  utn_getName("\nIngrese el sexo (femenino o masculino): ","\n\nError. Intentelo de nuevo",1,51,3,array[posicion].sexo);
        		  utn_getUnsignedInt("\nIngrese la edad: ","\nError",1,sizeof(int),1,99,3,&array[posicion].edad);
        		  utn_getUnsignedInt("\nIngrese la nota1P: ","\nError",1,sizeof(int),1,10,3,&array[posicion].nota1P);
        		  utn_getUnsignedInt("\nIngrese la nota2P: ","\nError",1,sizeof(int),1,10,3,&array[posicion].nota2P);
        		  utn_getTexto("\nIngrese el Apellido: ","\nError",1,51,1,array[posicion].apellidos);
        		  array[posicion].promedio= (array[posicion].nota1P + array[posicion].nota2P)/2;
        		  array[posicion].isEmpty=0;
        		  retorno=0;
        	  }

        }
    }
    return retorno;
}


int buscarEmpty(colegioE array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int buscarID(colegioE array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].isEmpty==0 && valorBuscado != array[i].legajo )
            {
            	array[i].legajo=valorBuscado;
                retorno=0;
                *posicion=i;

                break;
            }
        }
    }
    return retorno;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------

int mostrarUnEstudiante(colegioE array[], int size,int idBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0 && idBuscado>=0)
    {
        for(i=0;i<size;i++)
        {
        	if(array[i].isEmpty== 1)
        		continue;
            if(array[i].isEmpty==0 && array[i].legajo == idBuscado )
            	 printf("\n******************************************************\n Legajo: %d\nSexo: %s\nedad: %d\nnotap1: %d\nnotap2: %d\n apellido: %s\npromedio: %.2f",
            	                       array[i].legajo,array[i].sexo,array[i].edad,array[i].nota1P,array[i].nota2P,array[i].apellidos,array[i].promedio);
            else
                printf("\nEse legajo no existe papu :(.\n");
        }
        retorno=0;
    }
    return retorno;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

int mostrarEstudiantes(colegioE array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
    	for(i=0;i<size;i++)
    	{
    		if(array[i].isEmpty==1)
    			continue;
    		else
    			printf("\n******************************************************\n Legajo: %d\nSexo: %s\nedad: %d\nnotap1: %d\nnotap2: %d\n apellido: %s\npromedio: %.2f",
    			            	                       array[i].legajo,array[i].sexo,array[i].edad,array[i].nota1P,array[i].nota2P,array[i].apellidos,array[i].promedio);
        }
        retorno=0;
    }
    return retorno;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
int estructuraOrdenada(colegioE array[], int size)
{
	 int retorno=-1;
	    int i, j;
	    char bufferApellido[51];
	    int bufferLegajo;
	    char bufferSexo[51];
	   	int bufferEdad;
	   	int bufferNota1P;
	   	int bufferNota2P;
	    float bufferPromedio;
	    int bufferIsEmpty;

	    if(array!=NULL && size>=0)
	    {
	        for (i = 1; i < size; i++)
	        {
	            strcpy(bufferApellido,array[i].apellidos);
	            bufferLegajo=array[i].legajo;
	            strcpy(bufferSexo,array[i].sexo);
	            bufferEdad=array[i].edad;
	            bufferNota1P=array[i].nota1P;
	            bufferNota2P=array[i].nota2P;
	            bufferPromedio=array[i].promedio;
	            bufferIsEmpty=array[i].isEmpty;

	            j = i - 1;
	            while ((j >= 0) && strcmp(bufferApellido,array[j].apellidos)<0)
	            {
	                strcpy(array[j + 1].apellidos,array[j].apellidos);
	                array[j + 1].legajo=array[j].legajo;
	                strcpy(array[j + 1].sexo,array[j].sexo);
	                array[j + 1].edad=array[j].edad;
	                array[j + 1].nota1P=array[j].nota1P;
	                array[j + 1].nota2P=array[j].nota2P;
	                array[j + 1].promedio=array[j].promedio;
	                array[j + 1].isEmpty=array[j].isEmpty;



	                j--;
	            }
	            strcpy(array[j + 1].apellidos,bufferApellido);
	            array[j + 1].legajo=bufferLegajo;
	            strcpy(array[j + 1].sexo,bufferSexo);
	            array[j + 1].edad=bufferEdad;
	            array[j + 1].nota1P=bufferNota1P;
	            array[j + 1].nota2P=bufferNota2P;
	            array[j + 1].promedio=bufferPromedio;
	            array[j + 1].isEmpty=bufferIsEmpty;


	        }
	        retorno=0;
	    }
	    return retorno;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

