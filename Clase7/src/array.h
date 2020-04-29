/*
 * array.h
 *
 *  Created on: 16 abr. 2020
 *      Author: Nahu_
 */

#ifndef ARRAY_H_
#define ARRAY_H_

typedef struct
{
	int legajo; // (id)
	char sexo[51];
	int edad;
	int nota1P;
	int nota2P;
	char apellidos[51];
	float promedio;
	int isEmpty;
}colegioE;

int initColegio(colegioE pArray[],int limite);

int cargarPersona(colegioE array[], int size);

int buscarEmpty(colegioE array[], int size, int* posicion);

int mostrarUnEstudiante(colegioE array[], int size,int idBuscado);

int mostrarEstudiantes(colegioE array[], int size);

int estructuraOrdenada(colegioE array[], int size);

int buscarID(colegioE array[], int size, int valorBuscado, int* posicion);
#endif /* ARRAY_H_ */
