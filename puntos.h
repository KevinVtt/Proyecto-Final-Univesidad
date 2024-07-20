#ifndef PUNTOS_H_INCLUDED
#define PUNTOS_H_INCLUDED

struct Puntos{

    int codPuntuacion;
    int actuales;
    int puntuacionMaxima;

};

typedef struct Puntos * PuntosPtr;

// Cargar Puntos Nulos
PuntosPtr cargarPuntos();
// Mostrar Puntos
void mostrarPuntos(PuntosPtr puntos);
// Mostrar Puntos Lista
void mostrarPuntosLista(Lista lista);
// Destruir Puntos
void destruirPuntos(PuntosPtr puntos);

#endif // PUNTOS_H_INCLUDED
