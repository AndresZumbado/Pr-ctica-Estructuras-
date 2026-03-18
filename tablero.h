#ifndef CASILLAS_H
#define CASILLAS_H

#include <stdlib.h>

typedef struct {
    int numero;
    int vibilidad;
} casilla;

typedef struct {
    int *matriz;
    int capacidad;
} tablero;

tablero* crear_tablero_vacio(int capacidad) {
    int* matriz = malloc(sizeof(int*)*capacidad);	
    for (int i = 0; i < capacidad; i++) {
        matriz[i] = (casilla*)malloc(capacidad * sizeof(casilla));
    }
    struct tablero tab;
    tab.matriz = matriz;
    tab.capacidad = capacidad;
}

void llenar_tablero(tablero* tab) {
    for (int i = 0; i < capacidad; i++) {
        for (int j = 0; j < capacidad; j++) {
	    (*(tab->matriz + i) + j)*.numero = -1;
	    (*(tab->matriz + i) + j)*.visibilidad = 0;
       }
    } 
    int maximo_parejas = (tab->capacidad^2)/2;
    int parejas_hechas = 0;
    int numero_agregar = 1;
    int fila;
    int columna;
    int cont;
    while (parejas_hechas < maximo_parejas) {
	while (cont<2) {
	    casilla = rand() % tab->capacidad;
	    columna = rand() % tab->capacidad;
	    if ((((tab->matriz)+fila)*+columna)->numero != -1) {
	        (((tab->matriz)+fila)*+columna)->numero = numero_agregar;
		cont++;
	    }
	}
    numero_agregar++;
    }
}

#endif
