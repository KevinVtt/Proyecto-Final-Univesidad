#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "jugador.h"
#include "puntos.h"
#include "preguntas.h"

JugadorPtr cargarJugadorPorTeclado(){

    JugadorPtr jugador = (JugadorPtr)malloc(sizeof(struct Jugador));

    printf("Ingrese su alias: \n");
    fflush(stdin);
    gets(jugador->alias);

    printf("Ingrese su DNI: \n");
    scanf("%d",&jugador->dni);

    //Lista Puntaje.
    jugador->puntos = crearLista(sizeof(struct Puntos));
    //Lista de Preguntas
    jugador->preguntas = crearLista(sizeof(struct Preguntas));

    return jugador;

}

void mostrarJugador(JugadorPtr jugador){

    printf("\n-----------------------------\n");
    printf("      Alias: %s",jugador->alias);
    printf("      DNI: %d",jugador->dni);

    ///mostrarPuntosLista(jugador->puntos);
    ///mostrarPreguntasLista(jugador->preguntas);
}

void mostrarJugadores(JugadorPtr jugador[],int t){

    for(int i = 0; i < t; i++){
        mostrarJugador(jugador[i]);
    }

}

void cargarJugadoresTeclado(JugadorPtr jugador[],int t){
    for(int i = 0; i < t; i++){
        jugador[i] = cargarJugadorPorTeclado();
    }
};

int cantJugadores(){

    int t;

    do{
        printf("Ingrese la cantidad de jugadores\n");
        scanf("%d",&t);

    }while(t < 1 || t > 4);

    return t;

};

void liberarJugadores(JugadorPtr jugador[],int t){

    for(int i = 0; i < t; i++){
        liberarJugador(jugador[i]);
    }

}

void liberarJugador(JugadorPtr jugador){

    free(jugador);
    jugador->dni = -1;
    liberarlista(jugador->puntos);
    liberarlista(jugador->preguntas);

}
