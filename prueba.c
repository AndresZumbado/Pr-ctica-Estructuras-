#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <tablero.h>

int main(){

    
typedef struct {
    int numero;
    int visibilidad;
} casilla;

    int n;

    printf("ingrese el tamaño del tablero nxn: ");

    scanf("%d/n", &n);

    bool juego_terminado = false;

    crear_tablero(int n);
    
    while(!juego_terminado) {

        int fila, columna;

        char input;

        printf("ingrese la fila y la columna en formato <fila>,<columna>: ");

        scanf("%s" &input);

        sscanf(input, "%d,%d", &fila, &columna);
        
        editar_tablero();

        imprimir_tablero();

        juego_terminado = verificarjuegoterminado();

    }

    return 0;

}

void crear_tablero(tablero *t, int n){
    
    
}

void editar_tablero(tablero *t){

}


void imprimir_tablero(int n){

    for (int i==0; i<n; i++){
        for (int j==0; j<n; j++){
            if (tablero[i][j].visibilidad==1){
                print(tablero[i][j].numero);
                else{
                    print("no funciono")
                }
            }

        }
    }
    

}


bool verificarjuegoterminado(){


    
}
#ifndef CASILLAS_H
#define CASILLAS_H



casilla **matriz(int n){
    casilla **matriz= malloc(n* sizeof(casilla*));
    for (int i =0; i<0; i++){
        if (matriz[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matriz[j]);}
    }
    if matriz ==NULL return 
    }

}


#endif


struct player {
    int score;
    
};

void registro_match( player,int &match, int &paircount,int new_p  ){
    int [paircount+1];

    for (int=0; i<paircount; i++){
        temp[i]=paircount [i];

        temp[paircount]=new_p;
    }
}