#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "lista.h"

struct Jugador{

    char alias[20];
    int dni;
    // Preguntas
    Lista preguntas;
    Lista puntos;

};

typedef struct Jugador * JugadorPtr;

JugadorPtr cargarJugadorPorTeclado();
void cargarJugadoresTeclado(JugadorPtr jugador[],int t);

int cantJugadores();

void mostrarJugador(JugadorPtr jugador);
void mostrarJugadores(JugadorPtr jugador[],int t);

// Funcion para mostrar al ganador

void liberarJugador(JugadorPtr jugador);
void liberarJugadores(JugadorPtr jugador[],int t);

#endif // JUGADOR_H_INCLUDED

