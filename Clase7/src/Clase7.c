/*
 ============================================================================
 Name        : Clase7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * int legajo[CANT_EL];
char sexo[CANT_EL];
int edad[CANT_EL];
int nota1P[CANT_EL];
int nota2P[CANT_EL];
float promedio[CANT_EL];
char arrayApellidos[CANT_EL][50];
Funciones con Arrays
*********************
Inicializar
cargar
Mostrar1Estudiante
mostrarEstudiantes
Ordenar por legajo
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"
#define QTY 200

int main(void)
{
	setbuf(stdout,NULL);

	colegioE arrayColegio[QTY];

	initColegio(arrayColegio,QTY);

	int option;
	int idUnEstudiante;

	while(option !=5)
	{
		utn_getUnsignedInt("\n\nBienvenidos\n\n1-Cargar Estudiante\n2-Mostrar Estudiante especifico\n3-Mostrar todo\n4-Ordenar por legajo\n5-Salir\nElija una opcion: ","\n\nError Ingrese opcion valida\n\n"
				,1,sizeof(int),1,5,3,&option);

		switch(option)
		{
		case 1: // Cargar osea alta :v
			cargarPersona(arrayColegio,QTY);
		break;
		case 2: // mostrar un solo estudiante
			utn_getUnsignedInt("\nIngrese el legajo a mostrar: \n","\nError,Opcion no valida\n",1,sizeof(int),0,QTY,3,&idUnEstudiante);
			mostrarUnEstudiante(arrayColegio,QTY,idUnEstudiante);
		break;
		case 3: //mostrar todos los estudiantes
			mostrarEstudiantes(arrayColegio,QTY);
			break;
		case 4://ordenar por apellido
			estructuraOrdenada(arrayColegio,QTY);
			printf("\nSe ha ordenado por apellido de forma ascendente\n");
			break;
		case 5:
			printf("\n vuelva pronto \n");
			break;

		}

	}

	return 0;
}
