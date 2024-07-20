#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "puntos.h"


PuntosPtr cargarPuntos(){

    PuntosPtr puntos = (PuntosPtr)malloc(sizeof(struct Puntos));

    puntos->actuales = -1;
    puntos->codPuntuacion = -1;
    puntos->puntuacionMaxima = -1;

    return puntos;

};

void mostrarPuntos(PuntosPtr puntos){

    printf("\n\n-----------PUNTOS------------\n");
    printf("    Codigo Puntuacion: %d ",puntos->codPuntuacion);
    printf("    Puntos Actuales: %d ",puntos->actuales);
    printf("    Puntuacion Maxima: %d ",puntos->puntuacionMaxima);

};

void mostrarPuntosLista(Lista lista){

    for ( int i = 0 ; i<obtenerTamanio(lista); i++){

        PuntosPtr puntos = *( (PuntosPtr*) obtenerDato(lista, i) );

        mostrarPuntos(puntos);

    }


};


void destruirPuntos(PuntosPtr puntos){
    free(puntos);
};
