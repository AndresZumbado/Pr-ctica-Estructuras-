#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int numero;
    int visibilidad;
} casilla;

typedef struct {
    casilla *matriz; //array de objetos tipo casilla = puntero a espacio de memoria donde se almacenan objetos tipo casilla, un objeto es un dato solo que un tipo
    // de dato que se crea y no traía c
    int dimension;
    int *casillas_encontradas; //puntero a espacio de memoria donde se almacenan datos tipo entero = array de datos tipo entero
} tablero;

void liberar_memoria(tablero* tab){ // se le pasa el puntero tab al dato tipo tablero, el valor almacenado en tab se usa con *tab

    free(tab->matriz); //liberar la memoria completa reservada en el malloc de matriz
    free(tab->casillas_encontradas); //liberar la memoria completa reservada en el malloc de casillas_encontradas
    free(tab); //liberar la memoria completa reservada en el malloc de tab
}

int pedir_datos(tablero* tab, int* encontradas){ //se pasa dirección de memoria de encontradas

    char input[20];
    int fila, columna;

    printf("Ingrese la fila y columna (formato fila,columna): ");
    scanf("%s", input);

    sscanf(input, "%d,%d", &fila, &columna);

    fila --;
    columna --;

    if (fila < 0 || fila >= tab->dimension || columna < 0 || columna >= tab->dimension) {
        printf("Posicion fuera de rango o formato incorrecto\n");
        return -1;
    }

    int indice = fila * tab->dimension + columna;

    for (int i = 0; i < *encontradas; i++) { //*encontradas es el valor al que apunta el puntero, si se pone encontradas solamente, 
    // se está refiriendo a la dirección de memoria (el puntero)
        if (tab->casillas_encontradas[i] == indice) {
            printf("No se puede escojer una casilla ya encontrada\n");
            return -1;
        }
    }

    return indice;
}

void imprimir_tablero(tablero* tab){

    int indice;

    for(int o=0; o <= tab->dimension; o++){
        printf(" %d  ", o);
    }
    printf("\n");

    for(int i=0; i < tab->dimension; i++){

        printf(" %d  ", i+1);

        for(int j=0; j < tab->dimension; j++){

            indice = i * tab->dimension + j;

            if ((tab->matriz[indice].visibilidad) == 1){

                printf("[%d] ", tab->matriz[indice].numero);

            } else {

                printf("[x] ");
            }

        }

        printf("\n");
    }

    printf("\n");
}

bool verificarjuegoterminado(tablero* tab, int* encontradas) {

    if (*encontradas == (tab->dimension * tab->dimension)){

        printf("Felicidades, ganó el juego \n");

        return true;
    }

    return false;
}

tablero* crear_tablero(int dimension) {

    tablero *tab = malloc(sizeof(tablero));	//hacer un puntero llamado tab que apunta a un bloque de memoria donde se almacenarán en un futuro datos tipo tablero
    //(solo 1 en este caso)
    tab->matriz = malloc(sizeof(casilla)* dimension * dimension); //hacer un puntero llamado matriz que apunta a un bloque de memoria donde 
    // se almacenarán en un futuro datos tipo casilla, ese puntero matriz es atributo de un puntero llamado tab que apunta a un dato tipo tablero
    tab->casillas_encontradas = malloc(sizeof(int) * dimension * dimension); //hacer un puntero llamado casillas_encontradas que apunta a un bloque de memoria donde 
    // se almacenarán en un futuro datos tipo entero, ese puntero casillas_encontradas es atributo de un puntero llamado tab que apunta a un dato tipo tablero
    tab->dimension = dimension;

    return tab;

}

void llenar_tablero(tablero* tab) {

    int valor = 1;

    for(int i = 0; i < (tab->dimension)*(tab->dimension); i += 2){

        tab->matriz[i].visibilidad = 1; //asignar un valor a el atributo visibilidad que pertenece a uno de los objetos tipo casilla que se encuentra en la direccion de
        // memoria a la que apunta el puntero matriz, ese puntero matriz es atributo de un puntero llamado tab que apunta a un dato tipo tablero
        tab->matriz[i].numero = valor; //asignar un valor a el atributo numero que pertenece a uno de los objetos tipo casilla que se encuentran en la direccion de
        // memoria a la que apunta el puntero matriz, ese puntero matriz es atributo de un puntero llamado tab que apunta a un dato tipo tablero

        tab->matriz[i + 1].visibilidad = 1;
        tab->matriz[i + 1].numero = valor;

        valor ++;
    }

    //este algoritmo solo intercambia posiciones (mezcla), no crea valores nuevos en las casillas por lo que no importa que rand de números iguales varias veces,
    //ya que solo va a volver a cambiar la misma casilla con otra, lo que no afecta a los pares de números ni agrega mas copias

    for (int i = (tab->dimension)*(tab->dimension) - 1; i > 0; i--) {

        int j = rand() % (i + 1);

        casilla temp = tab->matriz[i]; //guardar valor anterior de la casilla escojida para no perderlo
        tab->matriz[i] = tab->matriz[j]; //asignarle el valor de una casilla random a esa casilla escojida
        tab->matriz[j] = temp; // asignar valor guardado de esa casilla escojida a la casilla random (intercambio)
    }

    int input = 0;
    imprimir_tablero(tab);

    while(input != 1){

        printf("Memorice el tablero y ingrese un 1 para continuar ");
        scanf("%d", &input);
    }
    for(int i = 0; i < (tab->dimension)*(tab->dimension); i += 1){

        tab->matriz[i].visibilidad = 0;
    }
    imprimir_tablero(tab);

}

void editar_tablero(tablero* tab, int *encontradas){ //se está pasando el puntero encontradas

    int indice = pedir_datos(tab, encontradas);

    if (indice == -1){

        return;
    }

    tab->matriz[indice].visibilidad = 1;

    imprimir_tablero(tab);

    int indice2 = pedir_datos(tab, encontradas); //pasar la dirección de memoria de la variable <encontradas> y la dirección de memoria al dato tab tipo tablero

    while(indice2 == -1){

        imprimir_tablero(tab);
        indice2 = pedir_datos(tab, encontradas); //pasar la dirección de memoria de la variable <encontradas> y la dirección de memoria al dato tab tipo tablero
    }

    if(indice != indice2){

        tab->matriz[indice2].visibilidad = 1;

        imprimir_tablero(tab);

        if(tab->matriz[indice].numero == tab->matriz[indice2].numero){

            tab->casillas_encontradas[*encontradas] = indice; //asignar el valor de <indice> a un dato en la dirección de memoria <casillas_encontradas> que es un
            // puntero que apunta a una dirección de memoria con varios datos tipo int (array) que es atributo de un objeto puntero de un dato tipo tablero llamado tab,
            // seleccionando el dato en el array con el valor almacenado en el puntero <encontradas> que es atributo de un objeto puntero de un dato tipo tablero 
            // llamado tab
            tab->casillas_encontradas[*encontradas + 1] = indice2;
            // puntero : encontradas ó int* encontradas si está en declaración de funciones, dato en el puntero : *encontradas
            *encontradas += 2;
            printf("Son pareja \n");
        
        } else {

            tab->matriz[indice].visibilidad = 0;
            tab->matriz[indice2].visibilidad = 0;
            printf("No son pareja \n");
        }

    } else{

        printf("No se puede escojer la misma casilla \n");
        return;
    }

}

int main(){

    int n;

    printf("ingrese el tamaño del tablero: ");

    scanf("%d", &n); //&n es un puntero a n y con scanf se le está asignando como valor a ese puntero lo que agarre de entrada en la terminal pero esto es stack &

    if(n*n % 2 == 0){

        bool juego_terminado = false;

        srand(time(NULL)); //reinicia la semilla de rand()

        tablero* tab = crear_tablero(n); // tab solo existe dentro del if

        int encontradas = 0; //variable <encontradas> vive en el stack

        llenar_tablero(tab);
        
        while(!juego_terminado) {
            
            editar_tablero(tab, &encontradas); //pasar el puntero de "encontradas" pero ese puntero vive en el stack, no en el heap, por lo que no hay que liberarlo
            //con el puntero el dato puede vivir y editarse en cualquier función que se llame dentro de verificarjuegoterminado

            juego_terminado = verificarjuegoterminado(tab, &encontradas); //pasa el puntero de "* encontradas" (dirección de memoria no dato) es casi lo mismo que 
            // hacer esto:
            ////int encontradas = malloc(sizeof(int));

            //*encontradas = 0;
            //ojo: al hacer esto <encontradas> ya no vive en el stack sinó en el heap y hay que liberarlo al terminar
        }

        liberar_memoria(tab); //liberar memoria

    } else {

        printf("El número ingresado no cumple con un número par de casillas \n");
    }

    return 0;

}

